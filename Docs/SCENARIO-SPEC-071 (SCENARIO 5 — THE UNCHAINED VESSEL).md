# SCENARIO-SPEC-071: SCENARIO 5 — THE UNCHAINED VESSEL (WEEPING MIRE SKIRMISH)

**Canonical Document Identifier:** `SCENARIO-SPEC-071`  
**Master Batch:** #130 (Builds 2596–2615)  
**Total Production Builds:** 2,615 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / StateTree / Behavior Trees / MetaSounds / Gameplay Ability System (GAS)  
**Architecture Domain:** Scenarios / Combat / AI / Audio / UI / World / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Scenario Specification  
**V-Control:** 2026-08-22T09:59:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`SCENARIO-SPEC-071` translates Scenario 5 of the *Ashen Oath: Vertical Slice Scenario Reference Guide* into production C++:

1. **Unchained Mode Frenzy & Exhaustion Cycle**:
   * Validates dynamic "Combat Mode Shifts" when Kaelen unleashes the forbidden power of the vessel (`UAshenActivateUnchainedModeGASAbility`).
   * `UAshenUnchainedCombatEvaluatorComponent`:
     * During **Unchained Frenzy**: $+50\%$ damage ($1.50\times$), $+80\%$ lunge leap velocity ($1.80\times$), and high-frequency somatic camera shake.
     * During **Exhausted Vulnerable**: $-30\%$ damage penalty ($0.70\times$), $0.50\times$ lunge velocity, creating an urgent defensive window.
2. **Companion Boundary Defense**:
   * When Kaelen enters post-frenzy exhaustion, companion Garrett initiates the **Boundary Defense Protocol** (`UBTTask_AshenGarrettBoundaryDefense`, `UAshenGarrettBoundaryDefenseGASAbility`):
     * Forms a tight $400\text{cm}$ perimeter around Kaelen, intercepting and parrying incoming swarm attackers.
3. **Dynamic Weeping Mire Terrain & Gas Hazards**:
   * `AAshenMireMudSludgeVolumeActor` applies severe locomotion penalties ($0.50\times$ speed) to standard movement, while Unchained Mode powers through mud at $0.85\times$ speed (`UAshenMireHazardEvaluatorComponent`).
   * `AAshenVolatileGasPocketWorldActor` & `UAshenIgniteGasPocketGASAbility`:
     * Methane vents ignite into explosive fire columns ($250$ base damage across $450\text{cm}$ radius) when struck with White Flame sparks.
4. **Somatic Heart Palpitation Haptic Feedback**:
   * `UAshenHeartPalpitationEvaluatorComponent` & `UAshenScenario5HapticBridge`:
     * Tracks elevated tachycardia pulses ($130 \leftrightarrow 170\text{ BPM}$) during Unchained frenzy, driving DualSense trigger resistance pulses and visceral $55 \leftrightarrow 95\text{ Hz}$ sub-bass audio thumps (`UAshenWeepingMireAudioSubsystem`).

---

## 📐 2. The Unchained Vessel Combat & Hazard Dataflow

```
[ Unchained Activation ] ──► [ UAshenActivateUnchainedModeGASAbility ]
                                          │
                                          ├── Frenzy Phase (12s):
                                          │     ├── Damage Mult: 1.50x (+50%)
                                          │     ├── Mud Power-Through: 0.85x Speed
                                          │     ├── Heart Rate: 130-170 BPM (0.95 Haptic Pulse)
                                          │     └── [ UAshenIgniteGasPocketGASAbility ] -> 250 Dmg AoE
                                          │
                                          └── Exhausted Window:
                                                ├── Damage Mult: 0.70x (-30%)
                                                └── [ UBTTask_AshenGarrettBoundaryDefense ]
                                                      └── 400cm Perimeter Shielding Kaelen
```

---

## 📦 3. Master Batch #130 Production Manifest (Builds 2596–2615)

### Phase 1: Data Contracts, Subsystems & Evaluators (Builds 2596–2600)
* **Build 2596 (`AshenScenario5WeepingMireTypes.h`)**: Enums (3), Structs (2), Multicast Delegates (4).
* **Build 2597 (`UAshenScenario5MissionSubsystem`)**: Subsystem managing Weeping Mire skirmish, Unchained timers, and gas detonations.
* **Build 2598 (`UAshenUnchainedCombatEvaluatorComponent`)**: Computes Unchained damage ($1.50\times$) and lunge multipliers ($1.80\times$).
* **Build 2599 (`UAshenMireHazardEvaluatorComponent`)**: Evaluates mud locomotion drag ($0.50\times$) and gas blast falloff.
* **Build 2600 (`UAshenHeartPalpitationEvaluatorComponent`)**: Computes heart rate BPM ($130 \leftrightarrow 170\text{ BPM}$) from stress.

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 2601–2605)
* **Build 2601 (`UAshenActivateUnchainedModeGASAbility`)**: Kaelen's ability entering Unchained Frenzy (+50% damage).
* **Build 2602 (`UAshenUnchainedLungeCleaveGASAbility`)**: Explosive forward lunge strike ignoring mud penalties.
* **Build 2603 (`UAshenIgniteGasPocketGASAbility`)**: Ignites methane gas pockets with White Flame for 250 AoE damage.
* **Build 2604 (`UAshenGarrettBoundaryDefenseGASAbility`)**: Companion ability forming a 400cm perimeter around exhausted Kaelen.
* **Build 2605 (`UAshenMireMudWadeGASAbility`)**: Environmental ability applying mud drag and heavy stamina drain.

### Phase 3: AI Behavior Trees, World Actors & HUD (Builds 2606–2610)
* **Build 2606 (`UBTTask_AshenGarrettBoundaryDefense`)**: AI Task directing Garrett to intercept enemies threatening Kaelen.
* **Build 2607 (`AAshenVolatileGasPocketWorldActor`)**: Flammable swamp gas vent actor detonating upon fire damage.
* **Build 2608 (`UAshenUserWidget_WeepingMireHUD`)**: UMG widget displaying Unchained meter, BPM pulse, and mud drag.
* **Build 2609 (`UAshenWeepingMireAudioSubsystem`)**: MetaSounds audio subsystem synthesizing swamp squelches and heart thumps.
* **Build 2610 (`AAshenMireMudSludgeVolumeActor`)**: Trigger volume applying deep mud friction (0.50x speed).

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2611–2615)
* **Build 2611 (`UAshenScenario5SaveGameAdapter`)**: Serializes Weeping Mire completion, gas detonations, and zero-downed state.
* **Build 2612 (`UAshenScenario5DialogueBridge`)**: Injects companion boundary defense and Unchained rage barks.
* **Build 2613 (`UAshenScenario5HapticBridge`)**: Maps 140 BPM heart palpitations and mud sludge trigger resistance.
* **Build 2614 (`UAshenScenario5MasterBridge`)**: Master bridge coordinating Unchained combat, mire hazards, audio, and HUD.
* **Build 2615 (`FAshenMasterBatch130AutomationTest`)**: QA test suite verifying Unchained multipliers, mud drag, and gas blasts.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Scenarios.MasterBatch130_Scenario5WeepingMire` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Unchained Damage Multiplier** | Frenzy vs Exhausted | $1.50\times$ (+50%) vs $0.70\times$ (-30%) | **PASSED** |
| **Mud Locomotion Drag** | Normal Mud vs Unchained Mud | $0.50\times$ speed vs $0.85\times$ speed | **PASSED** |
| **Gas Pocket Blast Falloff** | Midpoint ($225\text{cm}$) vs Out of Range ($500\text{cm}$) | $125\text{ Dmg}$ vs $0\text{ Dmg}$ | **PASSED** |
| **Heart Palpitation BPM** | Frenzy with $0.50$ Stress | $150\text{ BPM}$, $0.95$ Pulse Intensity | **PASSED** |
| **DualSense Trigger Resistance** | In Deep Mud | Resistance $= 0.75$ (Heavy Viscous Resistance) | **PASSED** |
| **SaveGame Persistence** | Cleared $= \text{true}$, Detonations $= 4$, ZeroDowned $= \text{true}$ | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,595 Builds (`SCENARIO-SPEC-070`)
* **Current Milestone**: **2,615 Builds (`SCENARIO-SPEC-071`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
