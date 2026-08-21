# SCENARIO-SPEC-070: SCENARIO 4 — YOU MISTAKE THE WOUND FOR THE WORLD (WHISPERWOOD TRANSITION)

**Canonical Document Identifier:** `SCENARIO-SPEC-070`  
**Master Batch:** #129 (Builds 2576–2595)  
**Total Production Builds:** 2,595 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / StateTree / Behavior Trees / MetaSounds / Gameplay Ability System (GAS)  
**Architecture Domain:** Scenarios / Combat / AI / Audio / UI / World / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Scenario Specification  
**V-Control:** 2026-08-21T19:35:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`SCENARIO-SPEC-070` translates Scenario 4 of the *Ashen Oath: Vertical Slice Scenario Reference Guide* into production C++:

1. **Environmental Event Generation & Nightmare Incursions**:
   * Simulates the surreal transition into Whisperwood beneath a "bruised sore" sky and undulating purple mist (`AAshenPurpleMistVolumeActor`).
   * `UAshenWhisperingWindsGustGASAbility` generates sudden mist billows and auditory whisper pulses.
2. **Companion Grounding Mechanic**:
   * Kaelen's fractured sanity causes phantom mirages (`AAshenPhantomMirageWorldActor`) to spawn.
   * `UAshenCompanionGroundingEvaluatorComponent` & `UBTTask_AshenCompanionGroundingGaze`:
     * Checks companion (Garrett's) skeletal forward vector against the perceived entity's location.
     * If the angle exceeds $35^\circ$ or Garrett does not have the entity targeted, the entity is mathematically invalidated as a hallucination ($\text{State} = \text{InvalidatedHallucination}$) and dissolves into purple ash motes (`UAshenPhantomSlashDisperseGASAbility`).
3. **Sanity Chromatic Aberration & Lens Soot Layer**:
   * `UAshenSanityChromaticEvaluatorComponent` dynamically scales post-process Chromatic Aberration ($0.0 \leftrightarrow 5.0$) inversely to player Sanity:
     $$\text{ChromaticAberration}(\text{Sanity}) = (1.0 - \text{Sanity}) \cdot 5.0$$
   * `UAshenWipeSootTouchpadGASAbility` maps the DualSense controller touchpad to a tactile "Wiping Soot" gesture, physically clearing diegetic blur and ash residue from the camera lens.
4. **Cognitive Loci & Memory Palace Graph Expansion**:
   * `UAshenCognitiveLociRegistryComponent` and `UAshenCognitiveLocusAttuneGASAbility` allow Kaelen to discover and attune to psychological anchors, stabilizing sanity by $+0.20$.

---

## 📐 2. Companion Grounding & Sanity Dataflow

```
[ Phantom Entity Appears ] ──► [ AAshenPhantomMirageWorldActor ]
                                          │
                                          ▼
[ Companion Skeletal Gaze ] ──► [ UAshenCompanionGroundingEvaluatorComponent ]
                                          │
                                          ├── Within 35° & Target Active:
                                          │     └── Verified Physical Threat (Engage Combat)
                                          │
                                          └── Out of Cone / Untargeted:
                                                ├── Invalidated Hallucination
                                                ├── [ UAshenScenario4DialogueBridge ] -> Garrett: "There's nothing there, Kaelen..."
                                                └── [ UAshenPhantomSlashDisperseGASAbility ] -> Dissolves into Purple Ash
```

---

## 📦 3. Master Batch #129 Production Manifest (Builds 2576–2595)

### Phase 1: Data Contracts, Subsystems & Evaluators (Builds 2576–2580)
* **Build 2576 (`AshenScenario4WhisperwoodTypes.h`)**: Enums (3), Structs (2), Multicast Delegates (4).
* **Build 2577 (`UAshenScenario4MissionSubsystem`)**: Central subsystem managing Whisperwood state, soot layer opacity, and cognitive loci.
* **Build 2578 (`UAshenCompanionGroundingEvaluatorComponent`)**: Evaluates companion skeletal gaze alignment ($35^\circ$ cone) to ground reality.
* **Build 2579 (`UAshenSanityChromaticEvaluatorComponent`)**: Scales Chromatic Aberration ($0.0 \leftrightarrow 5.0$) inversely to player Sanity.
* **Build 2580 (`UAshenCognitiveLociRegistryComponent`)**: Manages mental anchor nodes and memory graph loci.

### Phase 2: Gameplay Ability System (GAS) & Hallucination Actuators (Builds 2581–2585)
* **Build 2581 (`UAshenWipeSootTouchpadGASAbility`)**: DualSense touchpad gesture clearing soot distortion from the lens.
* **Build 2582 (`UAshenGroundingCheckGASAbility`)**: Locks eyes with companion to verify physical reality and dismiss phantoms.
* **Build 2583 (`UAshenWhisperingWindsGustGASAbility`)**: Triggers sudden purple mist billows and auditory whispers.
* **Build 2584 (`UAshenCognitiveLocusAttuneGASAbility`)**: Attunes to a memory locus to anchor sanity ($+0.20$ Sanity).
* **Build 2585 (`UAshenPhantomSlashDisperseGASAbility`)**: Cleaves through a hallucination to instantly disperse it into ash.

### Phase 3: AI Behavior Trees, World Actors & HUD (Builds 2586–2590)
* **Build 2586 (`UBTTask_AshenCompanionGroundingGaze`)**: AI Task directing companion to align gaze with verified physical threats.
* **Build 2587 (`AAshenPhantomMirageWorldActor`)**: World actor representing a hallucinatory phantom entity.
* **Build 2588 (`UAshenUserWidget_WhisperwoodHUD`)**: UMG widget displaying sanity distortion, soot layer opacity, and loci count.
* **Build 2589 (`UAshenWhisperwoodAudioSubsystem`)**: MetaSounds audio subsystem synthesizing eerie whispering winds and pitch warbles.
* **Build 2590 (`AAshenPurpleMistVolumeActor`)**: Volumetric fog actor modulating purple mist density.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2591–2595)
* **Build 2591 (`UAshenScenario4SaveGameAdapter`)**: Serializes Whisperwood transition completion, discovered loci, and sanity state.
* **Build 2592 (`UAshenScenario4DialogueBridge`)**: Injects Garrett's reality-grounding dialogue barks.
* **Build 2593 (`UAshenScenario4HapticBridge`)**: Maps touchpad soot swipe friction to DualSense haptics.
* **Build 2594 (`UAshenScenario4MasterBridge`)**: Master bridge coordinating Companion Grounding, audio, HUD, and SaveGame.
* **Build 2595 (`FAshenMasterBatch129AutomationTest`)**: QA test suite verifying grounding evaluation, chromatic aberration, and haptics.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Scenarios.MasterBatch129_Scenario4Whisperwood` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Companion Grounding Check** | LOS + Companion Targeted vs Untargeted | `VerifiedPhysicalThreat` vs `InvalidatedHallucination` | **PASSED** |
| **Gaze Cone Alignment** | Angle $11.3^\circ$ vs $56.3^\circ$ (Max $35^\circ$) | Inside cone $= \text{true}$, Outside cone $= \text{false}$ | **PASSED** |
| **Sanity Chromatic Scaling** | Sanity $1.00 \to 0.50 \to 0.00$ | Aberration $= 0.00 \to 2.50 \to 5.00$ | **PASSED** |
| **Touchpad Soot Wiping** | Initial $0.60$ opacity, wipe $0.35$ | Remaining opacity $= 0.25$ | **PASSED** |
| **DualSense Touchpad Haptics** | Velocity $0.80$, Soot $0.50$ | Touchpad swipe haptic intensity $= 0.60$ | **PASSED** |
| **SaveGame Persistence** | Cleared $= \text{true}$, Loci $= 3$, Sanity $= 0.85$ | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,575 Builds (`SCENARIO-SPEC-069`)
* **Current Milestone**: **2,595 Builds (`SCENARIO-SPEC-070`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
