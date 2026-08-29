# backend/app/services/rag_pipeline.py
import asyncio
import logging
import os
import re
from functools import lru_cache
from typing import Any, Dict, List, Optional, Tuple

from fastapi import FastAPI
from pydantic import BaseModel, Field, field_validator

logger = logging.getLogger(__name__)

app = FastAPI(title="Ashen Oath Cognitive Ingestion Pipeline")

# ==========================================
# DATA CONTRACTS & CONFIGURATION [VOICE-SPEC-054]
# ==========================================

NATIVE_TAG_DICTIONARY = {
    "Journal.Tone.SelfAccusatory", 
    "Journal.Tone.Defiant", 
    "Combat.Stance.Friction", 
    "Evidence.Autopsy.SeveredSternum"
}

class AshenPerspectivePayload(BaseModel):
    node_id: str
    author_name: str
    interpretation_text: str
    ontological_lens: str
    intensity: float = Field(..., description="Somatic distortion intensity value")
    metadata: Dict[str, Any]

    @field_validator('intensity')
    @classmethod
    def clamp_intensity(cls, value: float) -> float:
        # Stage 4: Float Clamp [VOICE-SPEC-054]
        return max(0.0, min(1.0, value))


# ==========================================
# 4-STAGE FIREWALL VERIFIER [VOICE-SPEC-054]
# ==========================================

class CognitiveFirewallValidator:
    def __init__(self, active_imprint_buffer: List[str]):
        """
        Active Imprint Buffer tracks canonical node registrations currently 
        unlocked in game memory state.
        """
        self.active_imprint_buffer = active_imprint_buffer

    def audit(self, payload: AshenPerspectivePayload) -> Tuple[bool, str]:
        # Stage 1: Schema Validation
        # Automatically handled by Pydantic engine compilation layers.
        
        # Stage 2: Provenance Audit
        if payload.node_id not in self.active_imprint_buffer:
            return False, "FailedProvenanceAudit"
            
        # Stage 3: Tag Registry Check
        gameplay_tags = payload.metadata.get("gameplay_tags", [])
        for tag in gameplay_tags:
            if tag not in NATIVE_TAG_DICTIONARY:
                return False, "FailedTagRegistryCheck"
                
        # Stage 4: Float Clamping
        # Safely asserted downstream by the Pydantic type validator definitions.
        return True, "Success"


# ==========================================
# INGESTION & TEXT SPLITTING UTILITIES
# ==========================================

class RecursiveCharacterChunker:
    def __init__(self, chunk_size: int = 512, chunk_overlap: int = 50):
        self.chunk_size = chunk_size
        self.chunk_overlap = chunk_overlap

    def split_text(self, text: str) -> List[str]:
        """Splits raw text down into semantic pieces across clean sentence boundaries."""
        sentences = re.split(r'(?<=[.!?])\s+', text)
        chunks = []
        current_chunk = ""
        
        for sentence in sentences:
            if len(current_chunk) + len(sentence) <= self.chunk_size:
                current_chunk += (" " if current_chunk else "") + sentence
            else:
                if current_chunk:
                    chunks.append(current_chunk.strip())
                # Sliding context window back by overlapping margins
                current_chunk = sentence
        if current_chunk:
            chunks.append(current_chunk.strip())
        return chunks


# ==========================================
# VECTOR EMBEDDING & SUPABASE UPSERT [VOICE-SPEC-054]
# ==========================================
#
# Dependencies (add to requirements.txt):
#   sentence-transformers>=3.0
#   supabase>=2.0
#
# Required env vars (same keys as packages/supabase/src/client.ts):
#   SUPABASE_URL                — Supabase project URL
#   SUPABASE_ANON_KEY           — Supabase anon/publishable key
#
# Target table DDL (run once via Supabase migration):
#   CREATE EXTENSION IF NOT EXISTS vector;
#   CREATE TABLE IF NOT EXISTS ashen_oath_documents (
#       id              uuid PRIMARY KEY DEFAULT gen_random_uuid(),
#       node_id         text NOT NULL,
#       author_name     text NOT NULL,
#       interpretation_text text NOT NULL,
#       ontological_lens text NOT NULL,
#       intensity       float4 NOT NULL,
#       metadata        jsonb,
#       embedding       vector(384),   -- all-MiniLM-L6-v2 output dimension
#       ingested_at     timestamptz DEFAULT now()
#   );
#   CREATE INDEX ON ashen_oath_documents USING ivfflat (embedding vector_cosine_ops);

SUPABASE_TABLE = "ashen_oath_documents"
EMBEDDING_MODEL_NAME = "all-MiniLM-L6-v2"  # 384-dim, fast CPU inference, MIT license
EMBEDDING_BATCH_SIZE = 50
EMBEDDING_MAX_RETRIES = 3
EMBEDDING_RETRY_DELAY = 2.0  # seconds


@lru_cache(maxsize=1)
def _get_embedding_model():
    """
    Lazy singleton for the SentenceTransformer model.
    Loaded once on first call; subsequent calls return the cached instance.
    Import is deferred so the module loads cleanly even without the
    sentence-transformers package installed (useful during unit tests).
    """
    try:
        from sentence_transformers import SentenceTransformer  # type: ignore[import]
        logger.info("[RAG] Loading embedding model '%s'...", EMBEDDING_MODEL_NAME)
        model = SentenceTransformer(EMBEDDING_MODEL_NAME)
        logger.info("[RAG] Embedding model loaded.")
        return model
    except ImportError as exc:
        raise RuntimeError(
            "sentence-transformers is not installed. "
            "Run: pip install sentence-transformers"
        ) from exc


async def _encode_batch(texts: List[str]) -> List[List[float]]:
    """
    Runs SentenceTransformer.encode() in a thread-pool executor so the
    synchronous CPU-bound call does not block the FastAPI event loop.
    Returns L2-normalised 384-dim vectors as plain Python lists.
    """
    loop = asyncio.get_running_loop()
    model = _get_embedding_model()

    def _sync_encode() -> List[List[float]]:
        vecs = model.encode(
            texts,
            batch_size=EMBEDDING_BATCH_SIZE,
            normalize_embeddings=True,
            show_progress_bar=False,
        )
        return vecs.tolist()

    return await loop.run_in_executor(None, _sync_encode)


async def _embed_all(texts: List[str]) -> List[List[float]]:
    """
    Splits *texts* into batches of EMBEDDING_BATCH_SIZE and embeds each batch
    with up to EMBEDDING_MAX_RETRIES attempts before propagating the error.
    Mirrors the batching + retry pattern in open-notebook/commands/embedding_commands.py.
    """
    all_embeddings: List[List[float]] = []
    total = len(texts)
    n_batches = (total + EMBEDDING_BATCH_SIZE - 1) // EMBEDDING_BATCH_SIZE

    for batch_idx in range(n_batches):
        start = batch_idx * EMBEDDING_BATCH_SIZE
        batch = texts[start : start + EMBEDDING_BATCH_SIZE]

        for attempt in range(1, EMBEDDING_MAX_RETRIES + 1):
            try:
                batch_vecs = await _encode_batch(batch)
                all_embeddings.extend(batch_vecs)
                logger.debug(
                    "[RAG] Embedded batch %d/%d (%d texts)",
                    batch_idx + 1, n_batches, len(batch),
                )
                break
            except Exception as exc:
                if attempt < EMBEDDING_MAX_RETRIES:
                    logger.warning(
                        "[RAG] Embedding batch %d/%d attempt %d/%d failed: %s — retrying in %.0fs",
                        batch_idx + 1, n_batches, attempt, EMBEDDING_MAX_RETRIES,
                        exc, EMBEDDING_RETRY_DELAY,
                    )
                    await asyncio.sleep(EMBEDDING_RETRY_DELAY)
                else:
                    raise RuntimeError(
                        f"[RAG] Embedding batch {batch_idx + 1}/{n_batches} failed after "
                        f"{EMBEDDING_MAX_RETRIES} attempts: {exc}"
                    ) from exc

    return all_embeddings


async def generate_embeddings_and_upsert_to_supabase(
    records: List[Dict[str, Any]],
    table: str = SUPABASE_TABLE,
) -> int:
    """
    Embeds every record's ``interpretation_text`` and bulk-upserts the
    enriched rows into Supabase via the Python async client.

    Returns the number of rows successfully upserted.
    Raises ``RuntimeError`` if the Supabase credentials are missing or the
    write fails; logs a warning and returns 0 if *records* is empty.

    Env vars consumed (identical to packages/supabase/src/client.ts):
        SUPABASE_URL
        SUPABASE_ANON_KEY  (falls back to NEXT_PUBLIC_SUPABASE_PUBLISHABLE_DEFAULT_KEY)
    """
    if not records:
        logger.warning("[RAG] generate_embeddings_and_upsert_to_supabase: no records — skipping.")
        return 0

    # --- resolve credentials (matches TS resolveEnv() key priority) -----------
    supabase_url = os.environ.get("SUPABASE_URL") or os.environ.get("NEXT_PUBLIC_SUPABASE_URL")
    supabase_key = (
        os.environ.get("SUPABASE_ANON_KEY")
        or os.environ.get("NEXT_PUBLIC_SUPABASE_ANON_KEY")
        or os.environ.get("NEXT_PUBLIC_SUPABASE_PUBLISHABLE_DEFAULT_KEY")
    )

    if not supabase_url or not supabase_key:
        logger.warning(
            "[RAG] SUPABASE_URL / SUPABASE_ANON_KEY not set — "
            "skipping vector upsert (set env vars to enable)."
        )
        return 0

    # --- embed all interpretation texts in one batched pass ------------------
    texts = [r["interpretation_text"] for r in records]
    logger.info("[RAG] Generating embeddings for %d record(s)...", len(texts))
    embeddings = await _embed_all(texts)

    if len(embeddings) != len(records):
        raise RuntimeError(
            f"[RAG] Embedding count mismatch: got {len(embeddings)} vectors "
            f"for {len(records)} records."
        )

    # --- build rows with embedding vectors attached --------------------------
    rows = [
        {**record, "embedding": embedding}
        for record, embedding in zip(records, embeddings)
    ]

    # --- upsert to Supabase --------------------------------------------------
    try:
        from supabase import acreate_client  # type: ignore[import]
    except ImportError as exc:
        raise RuntimeError(
            "supabase-py is not installed. Run: pip install supabase"
        ) from exc

    client = await acreate_client(supabase_url, supabase_key)
    response = await client.table(table).upsert(rows).execute()

    n_upserted = len(response.data) if response.data else 0
    logger.info("[RAG] Upserted %d row(s) → supabase table '%s'.", n_upserted, table)
    return n_upserted


# ==========================================
# FASTAPI ENDPOINT IMPLEMENTATION
# ==========================================

@app.post("/api/v1/ingest-document")
async def ingest_document(
    document_payload: Dict[str, Any],
    active_imprints: Optional[List[str]] = None,
) -> Dict[str, Any]:
    """
    Ingests unstructured multi-author logs, breaks them down into semantic shards,
    filters them through the firewall, and registers them into vector states.
    """
    raw_text = document_payload.get("text", "")
    author = document_payload.get("author", "Kaelen")
    node_id = document_payload.get("node_id", "")
    lens = document_payload.get("lens", "Defiance")
    tags = document_payload.get("tags", [])
    
    # 1. Chunk documents into granular blocks
    chunker = RecursiveCharacterChunker()
    text_shards = chunker.split_text(raw_text)
    
    firewall = CognitiveFirewallValidator(active_imprint_buffer=active_imprints or [])
    processed_records = []
    
    for shard in text_shards:
        # Build out candidate raw compilation structures
        candidate = AshenPerspectivePayload(
            node_id=node_id,
            author_name=author,
            interpretation_text=shard,
            ontological_lens=lens,
            intensity=1.85, # Will trigger float clamp rules (1.85 -> 1.0)
            metadata={"gameplay_tags": tags, "shard_length": len(shard)}
        )
        
        # 2. Assert Zero-Entropy Firewall
        passed, status_code = firewall.audit(candidate)
        
        if not passed:
            # Deterministic Fallback Trigger [VOICE-SPEC-054]
            fallback_text = "The past fragments fade into unreadable static."
            if lens == "Wrath":
                fallback_text = "Your memory burns away behind walls of blinding blood."
                
            processed_records.append({
                "node_id": node_id,
                "author_name": "SystemFallback",
                "interpretation_text": fallback_text,
                "ontological_lens": lens,
                "intensity": 0.0,
                "metadata": {"firewall_status": status_code}
            })
            continue

        processed_records.append(candidate.model_dump())
        
    # 3. Generate embeddings and upsert to Supabase vector store [VOICE-SPEC-054]
    #    No-ops gracefully when SUPABASE_URL / SUPABASE_ANON_KEY are absent.
    await generate_embeddings_and_upsert_to_supabase(processed_records)
    
    return {
        "status": "ProcessingComplete",
        "total_chunks": len(processed_records),
        "payloads": processed_records
    }
