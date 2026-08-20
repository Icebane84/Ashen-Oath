# INTENT-SPEC-056: THE COMPANION INTENT INFERENCE & DYNAMIC RELATIONAL ADAPTATION ENGINE (THE "MR. HERO" PROTOCOL)

**Canonical Document Identifier:** `INTENT-SPEC-056`  
**Master Batch:** #115 (Builds 2296–2315)  
**Total Production Builds:** 2,315 Builds  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Behavior Trees  
**Architecture Domain:** Companions / AI / Combat / Audio / UI / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Master Specification  
**V-Control:** 2026-08-20T11:10:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`INTENT-SPEC-056` codifies **The Companion Intent Inference & Dynamic Relational Adaptation Engine** for *Ashen Oath*.

In traditional companion AI, relationships are flattened into binary obedience meters: high affinity means the companion blindly follows the player, low affinity means they refuse orders. 

`INTENT-SPEC-056` introduces the **Intent Resolution Model**:
> **Trust is Confidence in Intent, NOT Obedience.**
> A companion with high trust retains their own ontological boundaries, tactical judgment, and moral principles. High trust grants the companion **higher interpretive resolution over Kaelen's kinetic decisions**. They can distinguish whether Kaelen is breaking formation out of self-sacrificial protection or succumbing to suicidal Ashen Mark rage.

---

## 📐 2. The "Mr. Hero" Formation-Break Decision Spectrum

When Kaelen breaks tactical formation or charges into danger, the `UAshenCompanionIntentInferenceSubsystem` evaluates telemetry snapshots and historical confidence:

```
                              [ Kaelen Breaks Formation / Charges ]
                                                │
                                                ▼
                        [ Snapshot: FPlayerIntentTelemetrySnapshot ]
                                                │
                                                ▼
                          [ Intent Inference Evaluator (C++) ]
                                                │
         ┌──────────────────────────────┬───────┴──────────────────────┬──────────────────────────────┐
         ▼                              ▼                              ▼                              ▼
[ 1. Low Trust + Rescue ]    [ 2. High Trust + Rescue ]    [ 3. High Trust + Wrath ]    [ 4. Tactical Necessity ]
  • Intent: Reckless           • Intent: Heroic Sacrifice    • Intent: Mark Corruption    • Intent: Flank Exploit
  • Action: Flank & Compensate • Action: Shoulder-To-Shoulder • Action: Body-Block / Stop   • Action: Pincer Sync
  • Bark: "God damn it Kaelen! • Bark: "Damn it. There goes  • Bark: "No. Not this time! • Bark: "Got your left!
    I said wait!"                our Mr. Hero again."          Pull back!"                  Drive them in!"
```

---

## 📦 3. Master Batch #115 Production Manifest (Builds 2296–2315)

### Phase 1: Core Data Contracts, Intent Telemetry & Inference Classifier (Builds 2296–2300)
* **Build 2296 (`AshenCompanionIntentTypes.h`)**: Enums (`EPlayerFormationBreakIntent`, `ECompanionTacticalResponse`, `EIntentConfidenceTier`), Structs (`FPlayerIntentTelemetrySnapshot`, `FCompanionIntentEvaluationResult`), and 4 master multicast delegates.
* **Build 2297 (`UAshenCompanionIntentInferenceSubsystem`)**: Central world subsystem evaluating player formation breaks and querying historical memory patterns.
* **Build 2298 (`UAshenGarrettIntentEvaluatorComponent`)**: Garrett's tactical intent evaluator weighing cynical restraint vs heroic confidence.
* **Build 2299 (`UAshenSerafinaEmpathicIntentEvaluatorComponent`)**: Serafina's moral intent evaluator distinguishing sacrificial protection from dark corruption.
* **Build 2300 (`UAshenHistoricalIntentProvenanceAuditor`)**: Audits player historical choices to compute intent confidence without artificial meters.

### Phase 2: Tactical Adaptation, Behavior Tree Tasks & GAS Abilities (Builds 2301–2305)
* **Build 2301 (`UAshenShoulderToShoulderCommitGASAbility`)**: High-trust companion sprint ability committing side-by-side with Kaelen (+40% mutual poise hardening).
* **Build 2302 (`UAshenCompanionConfrontationInterveneGASAbility`)**: High-trust companion ability physically body-blocking Kaelen when succumbing to blind wrath.
* **Build 2303 (`UBTTask_AshenEvaluatePlayerIntent`)**: Behavior Tree Task querying intent inference subsystem to update Blackboard tactical state.
* **Build 2304 (`UBTTask_AshenShoulderToShoulderSprint`)**: Behavior Tree Task executing synchronized close-formation rush.
* **Build 2305 (`UBTDecorator_AshenIntentConfidenceGate`)**: Behavior Tree Decorator gating companion tactical decisions based on intent confidence.

### Phase 3: Contextual Audio Barks, Diegetic Cues & Somatic Feedback (Builds 2306–2310)
* **Build 2306 (`UAshenRelationalContextBarkDispatcher`)**: Dispatches character-authentic voice barks ("There goes our Mr. Hero again" vs "God damn it Kaelen!").
* **Build 2307 (`UAshenCompanionBreathingProximityAdapter`)**: Synchronizes companion sprint breathing when charging shoulder-to-shoulder.
* **Build 2308 (`UAshenUserWidget_WordlessResonancePromptHUD`)**: Subtle gold/amber UI vignette flare when companion commits alongside Kaelen.
* **Build 2309 (`UAshenCompanionFormationHapticAdapter`)**: DualSense tactile haptic rumble representing companion footsteps rushing in sync.
* **Build 2310 (`AAshenEndangeredInnocentAnchorActor`)**: 3D world encounter anchor defining civilian rescue scenarios for intent testing.

### Phase 4: SaveGame Serialization, Master Orchestrator Bridge & Value-Asserting QA (Builds 2311–2315)
* **Build 2311 (`UAshenCompanionIntentSaveGameAdapter`)**: Serializes historical intent decisions and companion trust interpretations.
* **Build 2312 (`UAshenCompanionIntentDialogueBridge`)**: Injects formation-break confrontations into campfire dialogue trees.
* **Build 2313 (`UAshenCompanionFormationMeshAdapter`)**: Drives synchronized lean and sprint animation parameters for shoulder-to-shoulder charge.
* **Build 2314 (`UAshenCompanionIntentMasterBridge`)**: Master bridge connecting Intent Subsystem, State Registry, GAS, and Audio/UI.
* **Build 2315 (`FAshenMasterBatch115AutomationTest`)**: Deep QA automation test suite validating all intent pathways (Heroic Rescue, Blind Wrath, Low Trust Flank, High Trust Commit).

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Companions.MasterBatch115_IntentInference` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **High Trust + Innocent Rescue** | Innocent = `true`, Tier = `Confident` | $\text{Response} = \text{ShoulderToShoulderCommit}, \, \text{Bark} = \text{"Mr. Hero"}$ | **PASSED** |
| **Low Trust + Innocent Rescue** | Innocent = `true`, Tier = `Doubtful` | $\text{Response} = \text{CautiousFlankCompensate}, \, \text{Bark} = \text{"I said wait"}$ | **PASSED** |
| **High Trust + Blind Wrath** | Dysreg = $0.85$, Lens = `Wrath` | $\text{Response} = \text{ConfrontationalIntervene}, \, \text{Bark} = \text{"Not this time"}$ | **PASSED** |
| **Confidence Tier Auditor** | Lens = `Grace`, Dysreg = $0.15$ | $\text{ConfidenceTier} = \text{Absolute}$ | **PASSED** |
| **Serafina Moral Evaluation** | Innocent = `true`, Tier = `Confident` | $\text{Response} = \text{DefensiveSanctuaryHold}, \, \text{Bark} = \text{"flame will shelter"}$ | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,295 Builds (`JOURNAL-SPEC-055`)
* **Current Milestone**: **2,315 Builds (`INTENT-SPEC-056`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
