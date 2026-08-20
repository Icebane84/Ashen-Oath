# VOICE-SPEC-054: THE INNER VOICE COMPILER & PHENOMENOLOGICAL COGNITIVE FIREWALL (IVC-001)

**Canonical Document Identifier:** `VOICE-SPEC-054`  
**Master Batch:** #113 (Builds 2256–2275)  
**Total Production Builds:** 2,275 Builds  
**Target Engine:** Unreal Engine 5.8 C++  
**Architecture Domain:** Soul / Memory / Core Architecture / Combat / Audio / UI / AI / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Master Specification  
**V-Control:** 2026-08-20T09:50:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`VOICE-SPEC-054` codifies the **Inner Voice Compiler (IVC-001)** and **Zero-Entropy Cognitive Firewall Protocol** for *Ashen Oath*. 

The IVC operates as a decoupled, event-driven translation subsystem between deterministic game telemetry (`FCanonicalSoulStateVector`, active `EOntologicalLens`, and `FMemoryImprintPayload` buffers) and the phenomenological expression layer (DualSense controller speaker whispers, UI chromatic edge desaturation, and multi-author Living Journal annotations).

### The Golden Rule of Subservient Cognitive Architecture:
> **The Inner Voice Compiler serves as an expressive compiler, NOT a game master.** It holds zero sovereign authority over physical combat math, health pools, hit registration, or progression flags. Its exclusive mandate is translating verified numerical and relational states into Kaelen's internal cognitive reality.

---

## 📐 2. The 4-Stage Zero-Entropy C++ Firewall Protocol

Before raw compiler JSON output can touch game memory, it passes through four deterministic validation stages:

```
[ Raw Compiler JSON ]
        │
        ├──► 1. Schema Validation (Rejects malformed JSON / empty fields)
        │
        ├──► 2. Provenance Audit (Rejects payload if cited_memory_id is absent from active ImprintBuffer)
        │
        ├──► 3. Tag Registry Check (Verifies GameplayTags exist in Native Tag Dictionary)
        │
        └──► 4. Float Clamp (Clamps distortion and intensity values strictly to [0.0, 1.0])
                │
                ├──► [PASSED] ──► Dispatched to Actuators (Controller Speaker, HUD Shaders, Journal)
                │
                └──► [FAILED] ──► Deterministic Fallback (Pre-authored line keyed to EOntologicalLens)
```

* **Failure Fallback:** If any validation stage fails (e.g. citing an unvisited memory site), the payload is discarded, and the engine immediately executes the deterministic fallback dictionary keyed to `EOntologicalLens::Defiance`, `EOntologicalLens::Grace`, or `EOntologicalLens::Wrath`.

---

## 📦 3. Master Batch #113 Production Manifest (Builds 2256–2275)

### Phase 1: Core Subsystem, Data Contracts & 4-Stage Firewall (Builds 2256–2260)
* **Build 2256 (`AshenInnerVoiceCompilerTypes.h`)**: Enums (`EVoiceChannel`, `EFirewallValidationResult`, `ESalienceTriggerClass`), Structs (`FAshenVoiceIngestPacket`, `FAshenInnerVoicePayload`, `FAshenCompanionMarginaliaPayload`), and 4 master multicast delegates.
* **Build 2257 (`UAshenInnerVoiceCompilerSubsystem`)**: Central world subsystem managing async compilation queue, Salience Gate evaluator, and worker thread dispatcher.
* **Build 2258 (`UAshenCognitiveFirewallValidator`)**: 4-stage zero-entropy firewall auditing schema, memory provenance, gameplay tags, and float clamping.
* **Build 2259 (`UAshenDeterministicVoiceFallbackProvider`)**: Lens-keyed and debt-keyed deterministic fallback dictionary for instant zero-latency offline recovery.
* **Build 2260 (`UAshenMemoryProvenanceAuditor`)**: Cross-references cited memory IDs against the canonical state registry and imprint buffer.

### Phase 2: Salience Gating & Slow-Loop Worker Integration (Builds 2261–2265)
* **Build 2261 (`UAshenSalienceGateTriggerEvaluatorComponent`)**: Evaluates debt thresholds (0.50, 0.75, 1.0), relational ruptures ($\Delta \ge 0.15$), and lens transmutations to trigger slow-loop compilation.
* **Build 2262 (`FAshenAsyncVoiceCompilationWorker`)**: Thread-safe non-abandonable async task worker parsing and auditing raw compiler output completely off the game thread.
* **Build 2263 (`UAshenInnerVoiceCombatStanceGASAbility`)**: GAS ability firing internal monologue reflections when morphing combat stances under friction ($\ge 0.50$).
* **Build 2264 (`AAshenReflectiveCampfireNexusActor`)**: 3D world campfire entity triggering full journal tone & internal monologue compilation passes.
* **Build 2265 (`AAshenSubconsciousEchoAnchorActor`)**: 3D world spatial anchor triggering localized whisper motifs when approached.

### Phase 3: Phenomenological Actuators, UI Distortion & Audio Routing (Builds 2266–2270)
* **Build 2266 (`UBTTask_AshenCompanionMarginaliaQuery`)**: Behavior tree task querying recent voice context for companion barks.
* **Build 2267 (`UAshenSubconsciousSemanticAudioAdapter`)**: Routes sanitized audio motifs to DualSense controller speaker (`EVoiceChannel::ShadowSelf`) vs world spatial audio (`EVoiceChannel::Eldrin`).
* **Build 2268 (`UAshenUserWidget_InnerMonologueSubtitleHUD`)**: Subtle, non-intrusive subtitle HUD rendering internal monologue with channel-specific color tinting.
* **Build 2269 (`UAshenUserWidget_CognitiveDistortionOverlayHUD`)**: Edge flicker and desaturation overlay modulated by distortion intensity.
* **Build 2270 (`UAshenLivingJournalToneModulatorAdapter`)**: Applies journal tone tokens (`Journal.Tone.SelfAccusatory`) to living journal parchment shaders.

### Phase 4: Save State, Orchestration Bridge & Value-Asserting QA (Builds 2271–2275)
* **Build 2271 (`UAshenInnerVoiceMeshTremorAdapter`)**: Skeletal tremor feedback when internal monologue contradicts active stance.
* **Build 2272 (`UAshenInnerVoiceSaveGameAdapter`)**: Serializes compilation history, verified memory citations, and active voice channel states.
* **Build 2273 (`UAshenInnerVoiceDialogueBridge`)**: Feeds compiled internal monologue as narrative seeds for choice prompts.
* **Build 2274 (`UAshenInnerVoiceMasterOrchestratorBridge`)**: Master orchestrator binding the IVC subsystem, State Registry, GAS, and UI/Audio actuators.
* **Build 2275 (`FAshenMasterBatch113AutomationTest`)**: Deep QA automation test verifying the 4-stage firewall, provenance audit rejection, float clamping, and fallback resolution.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Soul.MasterBatch113_InnerVoiceCompiler` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Firewall Stage 1-4: Valid Payload** | Cited Memory = `mem_oakhaven_001` | $\text{ValidationResult} = \text{Success}$ | **PASSED** |
| **Provenance Audit Rejection** | Cited Memory = `mem_hallucinated_999` | $\text{ValidationResult} = \text{FailedProvenanceAudit}$ | **PASSED** |
| **Numerical Clamping** | Raw Intensity = $1.85$ | $\text{ClampedIntensity} = 1.0, \, \text{Result} = \text{FailedNumericalBoundsClamped}$ | **PASSED** |
| **Fallback Resolution: Defiance** | Lens = `Defiance`, Debt = 0.60 | $\text{Channel} = \text{KaelenReflex}, \, \text{Audio} = \text{Whisper.Left}$ | **PASSED** |
| **Fallback Resolution: Grace** | Lens = `Grace`, Debt = 0.20 | $\text{Channel} = \text{Eldrin}, \, \text{Audio} = \text{Echo.Harmonic}$ | **PASSED** |
| **Fallback Resolution: Wrath** | Lens = `Wrath`, Debt = 0.90 | $\text{Channel} = \text{ShadowSelf}, \, \text{Audio} = \text{Whisper.Right}$ | **PASSED** |
| **Salience Gate: Debt Crossing** | Debt: $0.40 \longrightarrow 0.55$ | $\text{Triggered} = \text{TRUE}, \, \text{Class} = \text{DebtStageEscalation}$ | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,255 Builds (`ECOL-SPEC-053`)
* **Current Milestone**: **2,275 Builds (`VOICE-SPEC-054`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
