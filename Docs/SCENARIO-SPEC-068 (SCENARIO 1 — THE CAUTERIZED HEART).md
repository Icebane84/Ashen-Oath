# SCENARIO-SPEC-068: SCENARIO 1 — THE CAUTERIZED HEART (OAKHAVEN CHAPEL CLIMAX)

**Canonical Document Identifier:** `SCENARIO-SPEC-068`  
**Master Batch:** #127 (Builds 2536–2555)  
**Total Production Builds:** 2,555 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Behavior Trees / MetaSounds  
**Architecture Domain:** Scenarios / Combat / Audio / UI / AI / World / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Scenario Specification  
**V-Control:** 2026-08-21T18:50:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`SCENARIO-SPEC-068` translates Scenario 1 of the *Ashen Oath: Vertical Slice Scenario Reference Guide* into production C++:

1. **The Principle of the Reluctant Knife**:
   * Pits the Absolute Nihilism of Brother Malakor against the Controlled Mitigation of Elder Valerius.
   * `UAshenReluctantKnifeEvaluatorComponent` evaluates Valerius's physical and emotional exhaustion (`ControlledMitigation` $\to$ `DesperateContainment` $\to$ `HardenedResignation`), ensuring his containment of Kaelen is understood as desperate strategic hardening rather than villainy.
2. **Ritual Disruption & Integration Debt Escalation**:
   * Kaelen channels `UAshenKaelenClarityOfHeartGASAbility` at the physicalized `AAshenOakhavenChapelRitualAltarWorldActor`.
   * `UAshenRitualClarityOfHeartSubsystem` dynamically spikes Kaelen's `IntegrationDebt` by up to $+45\%$ ($0.15 + 0.30 \cdot P_{\text{interrupt}}$) when Malakor interrupts the channeling with `UAshenMalakorVoidSmashGASAbility`.
3. **Null Zone Cascade & Somatic Audio Submersion**:
   * `UAshenNullZoneCascadeGASAbility` strips passive buffs and muffles audio frequencies down to a suffocating $320\text{ Hz}$ via `UAshenOakhavenAudioSubsystem`.
   * When `IntegrationDebt` exceeds $50\%$, "Shadow Self" whispers are routed directly to the DualSense controller speaker.
4. **DualSense Titan's Stand Parry Resistance**:
   * `UAshenTitansStandParryGASAbility` and `UAshenScenario1HapticBridge` dynamically scale adaptive trigger resistance ($70 \to 85 \to 100$ Max Hard Stop) during Malakor's phase escalations.

---

## 📐 2. The Scenario 1 Encounter Dataflow

```
[ Brother Malakor Boss ] ────► [ UAshenMalakorEncounterComponent ]
                                           │
                                           ▼ (Phase 1 / 2 / 3 Escalation)
[ Heavy Void Smash Strike ] ──► [ UAshenMalakorVoidSmashGASAbility ]
                                           │
                                           ▼
[ Oakhaven Chapel Altar ] ────► [ AAshenOakhavenChapelRitualAltarWorldActor ]
                                           │
                                           ├──► [ UAshenRitualClarityOfHeartSubsystem ]
                                           │     └── Spikes IntegrationDebt (+15% to +45%)
                                           │
                                           ├──► [ UAshenOakhavenAudioSubsystem ]
                                           │     ├── Null Zone 320 Hz Muffled Filter
                                           │     └── Controller Speaker Shadow Whispers (>50% Debt)
                                           │
                                           └──► [ UAshenReluctantKnifeEvaluatorComponent ]
                                                 └── Elder Valerius Hardened Resignation Dialogue
```

---

## 📦 3. Master Batch #127 Production Manifest (Builds 2536–2555)

### Phase 1: Data Contracts, Subsystems & Evaluators (Builds 2536–2540)
* **Build 2536 (`AshenScenario1CauterizedHeartTypes.h`)**: Enums (3), Structs (2), Multicast Delegates (4).
* **Build 2537 (`UAshenScenario1MissionSubsystem`)**: Subsystem managing Oakhaven Chapel mission progression and encounter state.
* **Build 2538 (`UAshenMalakorEncounterComponent`)**: Evaluates Brother Malakor's boss phase thresholds and Void Smash damage.
* **Build 2539 (`UAshenReluctantKnifeEvaluatorComponent`)**: Implements the Principle of the Reluctant Knife for Elder Valerius.
* **Build 2540 (`UAshenRitualClarityOfHeartSubsystem`)**: Tracks ritual progress and calculates debt penalties on disruption.

### Phase 2: Gameplay Ability System (GAS) & Encounter Actuators (Builds 2541–2545)
* **Build 2541 (`UAshenKaelenClarityOfHeartGASAbility`)**: Channeling ability executing the Clarity of Heart ritual at the altar.
* **Build 2542 (`UAshenMalakorVoidSmashGASAbility`)**: Ability executing Brother Malakor's ritual-breaking Void Smash.
* **Build 2543 (`UAshenValeriusReluctantInterveneGASAbility`)**: Ability executing Valerius's intervention parry against Malakor.
* **Build 2544 (`UAshenTitansStandParryGASAbility`)**: Ability executing Kaelen's Titan's Stand parry with DualSense resistance.
* **Build 2545 (`UAshenNullZoneCascadeGASAbility`)**: Ability initiating the Null Zone cascade, stripping passive buffs.

### Phase 3: AI Behavior Trees, World Actors & HUD (Builds 2546–2550)
* **Build 2546 (`UBTTask_AshenMalakorExecuteVoidSmash`)**: AI Task directing Malakor to target the ritual center.
* **Build 2547 (`AAshenOakhavenChapelRitualAltarWorldActor`)**: Physicalized altar actor with amber flame braziers.
* **Build 2548 (`UAshenUserWidget_OakhavenEncounterHUD`)**: UMG HUD displaying Malakor's health bar, ritual progress, and debt.
* **Build 2549 (`UAshenOakhavenAudioSubsystem`)**: MetaSounds audio subsystem managing amber flame audio and controller whispers.
* **Build 2550 (`UAshenShadowVeinMaterialModulatorComponent`)**: Modulates dynamic shadow-vein opacity and camera trauma jitter.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2551–2555)
* **Build 2551 (`UAshenScenario1SaveGameAdapter`)**: Serializes chapel resolution state, Malakor defeat, and debt mutations.
* **Build 2552 (`UAshenScenario1DialogueBridge`)**: Injects Malakor and Valerius confrontation dialogue into narrative graphs.
* **Build 2553 (`UAshenScenario1HapticBridge`)**: Maps Titan's Stand trigger resistance (70–100) into DualSense haptics.
* **Build 2554 (`UAshenScenario1MasterBridge`)**: Master bridge coordinating encounter subsystem, altar, audio, and HUD.
* **Build 2555 (`FAshenMasterBatch127AutomationTest`)**: QA test suite verifying phase shifts, debt spikes, and Reluctant Knife logic.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Scenarios.MasterBatch127_Scenario1CauterizedHeart` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Malakor Phase Shifts** | Health $1.00 \to 0.50 \to 0.20$ | `Phase1_Inquisitor` $\to$ `Phase2_PuristZealot` $\to$ `Phase3_Abomination` | **PASSED** |
| **Void Smash Damage** | Base $180.0 \to$ Phase 3 | Damage $= 396.0$ ($2.20\times$) | **PASSED** |
| **Ritual Debt Spike** | Interruption at $50\%$ and $90\%$ | Spike at $50\% = 0.30$, Spike at $90\% = 0.42$ ($0.15 + 0.30 \cdot P$) | **PASSED** |
| **Reluctant Knife Stance** | Early battle vs $>120\text{s} + >50\%$ damage | `ControlledMitigation` $\to$ `HardenedResignation` | **PASSED** |
| **Titan's Stand Haptics** | Rest tension vs Phase 3 Parry | Rest $= 10.0$, Phase 3 Parry $= 100.0$ (Max Hard Stop) | **PASSED** |
| **SaveGame Serialization** | Cleared $= \text{true}$, Iso $= 0.40$, Debt $= 0.65$ | Exact persistence and restoration across save/load | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,535 Builds (`ARCHIVE-SPEC-067`)
* **Current Milestone**: **2,555 Builds (`SCENARIO-SPEC-068`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
