# backend/app/services/rag_pipeline.py
import re
from typing import Any, Dict, List, Optional, Tuple

from fastapi import FastAPI
from pydantic import BaseModel, Field, field_validator

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
        
    # Mock Database Vector Injection block (In production: supabase.table().insert())
    # generate_embeddings_and_upsert_to_supabase(processed_records)
    
    return {
        "status": "ProcessingComplete",
        "total_chunks": len(processed_records),
        "payloads": processed_records
    }
