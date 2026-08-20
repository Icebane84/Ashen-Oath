# Ashen Oath: The Unreal Engine 5.8 C++ PHOENIX CODEX

**Document ID:** WLF-ENG-CODEX-001  
**Version:** 2.0 (Canonical Engine Architecture & Zero-Entropy Mandate)  
**Governed By:** Phoenix Protocol v15.0+ [OMEGA]  
**Master Milestone:** 2,295 Builds Clean (0 Errors, 0 Warnings across Master Batches #1–#114)  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Slate UMG  
**V-Control:** 2026-08-20T10:08:00Z  

---

## 🏛️ 1. Executive Axioms of Ashen Oath Engine Architecture

1. **Axiom I (The Architecture of Consequence)**:
   * Subsystems do not exist in isolation. Every kinetic combat action (parry, posture break, stagger, sacrificial intercept) writes directly to the immutable runtime kernel (`FCanonicalSoulStateVector` / `FCanonicalCombatEvent`), propagating real-time mutations across AI behavior, hardware haptics, diegetic audio, skeletal shaders, and living journal inscriptions.
2. **Axiom II (The Subservient Cognitive Architecture Mandate)**:
   * Expressive translation subsystems (e.g. `Inner Voice Compiler IVC-001`, `Campfire Marginalia CMM-001`) act as **translators, NEVER Game Masters**. They possess zero sovereign authority over physical combat math, health pools, hit registration, or progression flags.
3. **Axiom III (Zero Entropy & 4-Stage Firewall Protocol)**:
   * All dynamic text, monologue tokens, and memory imprints must pass through the **4-Stage Zero-Entropy C++ Firewall**:
     1. *Schema Validation* (Rejects malformed JSON / empty fields)
     2. *Provenance Audit* (Rejects citations absent from authoritative `FMemoryImprintPayload` buffers)
     3. *Native Tag Registry Check* (Verifies all `GameplayTags` exist in the native tag dictionary)
     4. *Numerical Clamping* (Clamps distortion and intensity floats strictly to $[0.0, 1.0]$)
   * On any failure, the engine instantly resolves to the deterministic fallback dictionary keyed to `EOntologicalLens::Defiance`, `EOntologicalLens::Grace`, or `EOntologicalLens::Wrath`.
4. **Axiom IV (The Ecology of Fellowship)**:
   * Dynamic companion relationships reject arbitrary "+5 / -5" approval meters. They are mathematically modeled as an **Ecology of Fellowship** governed by:
     * *Pattern Continuity & Synarchy Ratio* ($\text{SR} = \frac{\text{Interventions}_{\text{Successful}}}{\text{Interventions}_{\text{Attempted}}}$)
     * *Faith Under Uncertainty*: $F(t) = P(t) \cdot e^{-\lambda \Delta t}$
     * *Costly Presence*: Sacrificial high-speed sprint intercepts where companions physically step into lethal blows.
     * *Remembered Repair*: Permanent physical residue (cross-outs in the journal, wrist soot creep) that remains forever.

---

## 🏛️ 2. The 12 Domain-Driven Vertical Slices & Single Source Tree

All C++ production classes reside exclusively within `AshenOath/Source/AshenOath/` structured across 12 domain layers with strict one-way dependency flow and zero circular dependencies:

```
[ Domain Layer Hierarchy (Strict One-Way Downstream Flow) ]

  1. Soul / Core Architecture (AshenSoulStateVector, Canonical Types, State Registry)
          │
          ▼
  2. Memory & Provenance (TAM-001, Imprint Buffers, Keystone Compilers)
          │
          ▼
  3. Relational Ecology & Companions (Pattern Continuity, Faith Engine, Marginalia)
          │
          ▼
  4. Combat, GAS & Somatics (Abilities, Poise Duels, Trial of Will, Posture)
          │
          ▼
  5. AI & Symmetrical Collapse (Shepherd's Gambit, Behavior Trees, Intercepts)
          │
          ▼
  6. Audio & Hardware Haptics (3-Channel Proximity, DualSense Speakers, Trigger Locks)
          │
          ▼
  7. UI, Living Journal & Shaders (Slate/UMG Spread, Ink Bleed, Vertex Jitter)
          │
          ▼
  8. World, Traversal & Anchors (Campfire Nexus, Rupture Anchors, Star-Striders)
          │
          ▼
  9. Narrative & Dialogue (Dialogue Bridges, Will Choice Prompts)
          │
          ▼
  10. Core & SaveGame (Serialization Adapters, Checkpoint Archives)
          │
          ▼
  11. Orchestration & Master Bridges (Macro-Systemic Event Spines)
          │
          ▼
  12. QA & Automation Tests (Value-Asserting Dev Tests for Every Batch)
```

---

## 🏛️ 3. Memory Safety, Struct Layouts & Blueprint Interop Rules

### 1. The 128-Byte Cache-Line Kernel
* `FCanonicalSoulStateVector` must remain compact ($< 128$ bytes) to fit cleanly in a dual L1 cache line during high-frequency dispatch.

### 2. Guardrails on Blueprint Properties & Function Signatures
* **No `bIsActive` parameter names**: Never use `bIsActive` as a parameter name in `UFUNCTION(BlueprintCallable)` signatures to avoid name conflicts with generated Blueprint actor properties.
* **64-bit Integer Typing**: Always use `int64` for 64-bit integer IDs exposed to Blueprints (Unreal Header Tool does not support `uint64` in `UPROPERTY`/`UFUNCTION`).
* **Enums & Structs**: Mark all enums as `UENUM(BlueprintType)` with `enum class : uint8`. Mark all public data contract structs as `USTRUCT(BlueprintType)` with `ASHENOATH_API`.
* **Dynamic Material Parameter Binding**: Dynamic scalar parameters on materials (e.g. `NightsteelStain`, `CoverWear`, `InkBleed`) must be driven through `UMaterialInstanceDynamic` created during `BeginPlay`.

### 3. Spatial Anchor Envelopes & Anti-Collision Standards
* Dynamic UI text rendering in Slate/UMG must enforce character-count budgets (Max 90 chars for margin notes, Max 140 chars for footers).
* The `UAshenMarginaliaSpatialLayoutEngine` must dynamically re-route overlapping annotations to prevent text collision.

---

## 🏛️ 4. Asynchronous Processing & Active Duty Cycling

1. **Non-Abandonable Background Workers**:
   * Complex narrative evaluations and JSON schema parsing must run completely off the Game Thread using `FNonAbandonableTask` workers (e.g. `FAshenAsyncVoiceCompilationWorker`).
2. **Active Duty Cycling (Tick Sleep)**:
   * All world actors and non-combat components must initialize with `PrimaryActorTick.bStartWithTickEnabled = false`.
   * Wake up tick execution (`SetActorTickEnabled(true)`) only during active transitions or dynamic interpolation, and return to sleep immediately once settling.

---

## 🏛️ 5. Master Production Batches (The 20-Build Cadence)

Every Master Batch follows the rigid **20-Build Cadence** across 4 systematic phases:

```
[ Phase 1: Builds 1–5  ] ──► Data Contracts, Canonical Types, Core Subsystems & Firewalls
[ Phase 2: Builds 6–10 ] ──► Gameplay Mechanics, GAS Abilities & World 3D Anchors
[ Phase 3: Builds 11–15] ──► Actuators, AI Behavior Trees, DualSense Audio & Slate UI Shaders
[ Phase 4: Builds 16–20] ──► SaveGame Serialization, Master Orchestrator Bridges & QA Test Suite
```

* **Verification Protocol**: Every 20-build batch must compile cleanly under Unreal Engine 5.8 with **0 Errors, 0 Warnings** and pass all value-asserting QA assertions before committing and pushing.

---

**Status**: Canonical North Star for all Ashen Oath C++ Architecture. Adherence is mandatory for maintaining Zero Entropy.
