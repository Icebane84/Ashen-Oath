# MIND-SPEC-058: THE SOMATIC SILENCE CLASSIFIER & AMBIENT INTENT READING MATRIX

**Canonical Document Identifier:** `MIND-SPEC-058`  
**Master Batch:** #117 (Builds 2336–2355)  
**Total Production Builds:** 2,355 Builds  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Behavior Trees  
**Architecture Domain:** Companions / AI / Combat / Audio / UI / Narrative / World / Core / Orchestration / QA  
**Authority Level:** Canonical Master Specification  
**V-Control:** 2026-08-20T17:45:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`MIND-SPEC-058` operationalizes the **Non-Verbal Relational Dynamics and Boundary Integrity** of fellowship codified in Sophia's dialogue:

1. **The 3 Somatic Silence Classifications**:
   * `Contemplative` (Exploration context + low dysregulation $\implies$ respectful $500\text{uu}$ spacing).
   * `TraumaticAftermath` (Post-combat context $\le 15\text{s}$ + moderate dysregulation $\implies 250\text{uu}$ pace matching and grounded accompaniment).
   * `DestabilizingCrisis` (High dysregulation $\ge 0.70$ or active memory trigger $\implies 200\text{uu}$ vanguard lead, companion steps ahead to shield).
2. **Wordless Support Actions (Quiet Competence)**:
   * When companion trust is high ($\ge 0.65$), companions proactively clear obstacles/rubble within $800\text{uu}$ without dialogue prompts or UI pings (`UAshenWordlessObstacleClearGASAbility`).
3. **Companion Boundary Refusals ("The Most Dangerous Moment: Nobody Follows")**:
   * High trust does not mean blind obedience. When Kaelen recklessly charges into self-destruction, high-trust companions execute an AI boundary standoff at the threshold ($800\text{uu}$ standoff via `UAshenBoundaryHaltDisengageGASAbility`), refusing to enable his demise.

---

## 📐 2. The Silence & Boundary Causal Architecture

```
                               [ Player Movement & Somatics ]
                                              │
                                              ▼
                        [ UAshenSilenceClassifierComponent ]
                                              │
         ┌────────────────────────────────────┼────────────────────────────────────┐
         ▼                                    ▼                                    ▼
  [ Contemplative ]                 [ Traumatic Aftermath ]              [ Destabilizing Crisis ]
  • Spacing: 500uu                    • Spacing: 250uu (Match Pace)        • Spacing: 200uu (Take Point)
  • Audio: Wind Muffle (8kHz)         • Audio: Heartbeat (3.5kHz)          • Audio: Whisper Muffle (1.5kHz)
  • Mesh: Head Track Look-at          • Ability: Grounded Presence         • Boundary: Refusal Standoff (800uu)
```

---

## 📦 3. Master Batch #117 Production Manifest (Builds 2336–2355)

### Phase 1: Data Contracts, Subsystems & Evaluators (Builds 2336–2340)
* **Build 2336 (`AshenSomaticSilenceTypes.h`)**: Enums (3), Structs (2), Multicast Delegates (4).
* **Build 2337 (`UAshenSomaticSilenceSubsystem`)**: Central world subsystem coordinating silence classification, wordless support, and boundary refusal events.
* **Build 2338 (`UAshenSilenceClassifierComponent`)**: Evaluates combat recency, dysregulation scalars, and memory triggers to classify silence.
* **Build 2339 (`UAshenWordlessSupportEvaluatorComponent`)**: Evaluates proactive obstacle clearance commands based on proximity and trust.
* **Build 2340 (`UAshenBoundaryRefusalEvaluatorComponent`)**: Evaluates whether Kaelen's action triggers a companion boundary standoff.

### Phase 2: Gameplay Abilities (GAS) & Tactical Actions (Builds 2341–2345)
* **Build 2341 (`UAshenWordlessObstacleClearGASAbility`)**: Garrett's proactive ability clearing civilian debris/rubble before Kaelen arrives.
* **Build 2342 (`UAshenPaceMatchingSupportGASAbility`)**: Companion ability syncing locomotion speed to match Kaelen's stride.
* **Build 2343 (`UAshenBoundaryHaltDisengageGASAbility`)**: Companion ability executing the boundary standoff halt at the threshold.
* **Build 2344 (`UAshenTakePointShieldingGASAbility`)**: Companion ability moving ahead of Kaelen to take point during cognitive crises.
* **Build 2345 (`UAshenGroundedPresenceGASAbility`)**: Companion passive presence granting +0.05 Resolve regen during silent accompaniment.

### Phase 3: AI Behavior Trees, Ambient Audio & UI Shaders (Builds 2346–2350)
* **Build 2346 (`UBTTask_AshenEvaluateSomaticSilence`)**: Behavior Tree Task auditing silence classification and setting Blackboard spacing.
* **Build 2347 (`UBTTask_AshenExecuteWordlessSupport`)**: Behavior Tree Task directing companion to clear obstacles ahead of Kaelen.
* **Build 2348 (`UAshenSilenceAudioFilterComponent`)**: Dynamically modulates low-pass acoustic filters based on silence type.
* **Build 2349 (`UAshenUserWidget_WordlessResonanceHUD`)**: Minimalist UI displaying reticle stabilization and quiet solidarity indicators.
* **Build 2350 (`AAshenWorldObstacleAnchorActor`)**: 3D world obstacle entity (rubble/debris) proactively cleared by high-trust companions.

### Phase 4: SaveGame, Dialogue Bridge, Mesh Adapters & QA Suite (Builds 2351–2355)
* **Build 2351 (`UAshenSilenceSaveGameAdapter`)**: Serializes wordless support statistics and boundary refusal logs.
* **Build 2352 (`UAshenBoundaryReflectionDialogueBridge`)**: Formats campfire dialogue reflections after boundary refusal events.
* **Build 2353 (`UAshenCompanionSilenceMeshAdapter`)**: Modulates companion head tracking gaze weight toward Kaelen during silence.
* **Build 2354 (`UAshenSomaticSilenceMasterBridge`)**: Master bridge coordinating silence events, state registry updates, and audio/UI.
* **Build 2355 (`FAshenMasterBatch117AutomationTest`)**: Comprehensive QA automation test suite validating silence, wordless assistance, and boundary refusals.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Companions.MasterBatch117_SomaticSilence` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Silence Classification** | Exploration, Post-Combat, Crisis | Correct classification across all 3 states & spacing targets | **PASSED** |
| **Wordless Obstacle Clearing** | High Trust ($\ge 0.65$) within $800\text{uu}$ | Dispatches `ClearCivilianObstacle` with suppressed dialogue | **PASSED** |
| **Boundary Refusal Standoff** | Suicidal Charge + Dysregulation $\ge 0.75$ | Companion returns `BoundaryRefusal` standoff | **PASSED** |
| **Aligned Follow** | Heroic Combat Charge | Follow maintained without hesitation | **PASSED** |
| **SaveGame Serialization** | Wordless $= 14$, Boundary $= 3$ | Exact integer persistence across save/restore cycles | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,335 Builds (`BURDEN-SPEC-057`)
* **Current Milestone**: **2,355 Builds (`MIND-SPEC-058`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
