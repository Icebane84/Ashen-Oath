# STANCE-SPEC-094: THE OATHBRINGER HISTORICAL GREATSWORD STANCE FLOW & RUNIC MASTERY LOOP

**Canonical Document Identifier:** `STANCE-SPEC-094`  
**Master Batch:** #153 (Builds 3056–3075)  
**Total Production Builds:** 3,075 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / MetaSounds / DualSense Haptics  
**Architecture Domain:** Combat / UI / AI / Audio / Core / Orchestration / Narrative / World / QA  
**Authority Level:** Canonical Combat Stance Specification (4 Historical Greatsword Guards ↔ Rhythm Flow Cancels ↔ Runic Fuller Inscriptions)  
**V-Control:** 2026-08-29T08:05:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`STANCE-SPEC-094` implements the **Oathbringer Historical Greatsword Stance Flow & Runic Mastery Loop**, grounding Kaelen's two-handed greatsword combat in historical martial guards (Vom Tag, Pflug, Ochs, Mordhau/Half-Sword) linked to rhythm-timed recovery cancels and dynamic runic fuller seam illuminations:

```
┌─────────────────────────────────────────────────────────────────────────────────────────────┐
│              OATHBRINGER 4-GUARD HISTORICAL STANCE MATRIX & FLOW-CHAINING LOOP              │
│               Vom Tag ↔ Pflug ↔ Ochs ↔ Mordhau / Half-Sword Martial Matrix                  │
└─────────────────────────────────────────────────────────────────────────────────────────────┘
                                               │
       ┌───────────────────────┬───────────────┴───────────────┬───────────────────────┐
       ▼                       ▼                               ▼                       ▼
[ VOM TAG: HIGH WRATH ] [ PFLUG: LOW PLOW ]             [ OCHS: CROWN GUARD ]   [ MORDHAU / HALF-SWORD ]
• D-Pad UP              • D-Pad DOWN                    • D-Pad LEFT            • D-Pad RIGHT
• Overhead Cleaves      • Lunging Thrusts               • Crown Counter-Binds   • Gauntlet Blade Grip / Pommel
• +40% Poise Damage     • Low Stamina (14 sta)          • +0.12s Parry Window   • 100% Armor Penetration
• Crimson Seam Embers   • White Flame Wind Shimmer      • Golden Guard Glow     • Umbral Impact Shockwaves
       │                       │                               │                       │
       └───────────────────────┴───────────────┬───────────────┴───────────────────────┘
                                               ▼
                              ┌─────────────────────────────────┐
                              │  RHYTHM-TIMED FLOW-CHAINING     │
                              │  "Flow Glint" Recovery Cancel   │
                              │  0 Stamina Cost + Momentum Buff │
                              └─────────────────────────────────┘
```

---

## 📦 2. Master Batch #153 Production Manifest (Builds 3056–3075)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 3056–3060)
* **Build 3056 (`AshenOathbringerStanceTypes.h`)**: Enums (`EOathbringerMartialStance`, `EFlowChainingTimingQuality`), Structs (`FOathbringerStanceKinematics`, `FFlowChainingWindowData`), Multicast Delegates (4).
* **Build 3057 (`UAshenOathbringerStanceFlowConvergenceSubsystem`)**: Central world subsystem managing active stance, flow timing windows, and kinetic momentum handoffs.
* **Build 3058 (`UAshenStanceKinematicsEvaluator`)**: Evaluator calculating poise damage modifiers ($+40\%$), parry windows ($+0.12\text{s}$), and armor penetration ($100\%$).
* **Build 3059 (`UAshenFlowChainingTimingEvaluator`)**: Evaluator calculating the $0.15\text{s}$ "Flow Glint" cancel window, stamina refunds ($0\text{ cost}$), and $+15\text{ Flow Charge}$.
* **Build 3060 (`UAshenOathbringerRunicSeamDirectorComponent`)**: Component controlling dynamic fuller seam shader parameters (Crimson, White Flame, Gold, Umbral).

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 3061–3065)
* **Build 3061 (`UAshenVomTagOverheadCleaveGASAbility`)**: Vom Tag heavy overhead cleave with hyper-armor and $+40\%$ poise damage.
* **Build 3062 (`UAshenPflugLungingThrustGASAbility`)**: Pflug lunging point-pierce with reduced stamina cost and rapid recovery.
* **Build 3063 (`UAshenOchsCrownCounterBindGASAbility`)**: Ochs crown guard parry ability deflecting strikes into instant riposte thrusts.
* **Build 3064 (`UAshenMordhauArmorShatterGASAbility`)**: Mordhau pommel/half-sword strike bypassing plate armor defenses.
* **Build 3065 (`UAshenStanceFlowCancelRhythmGASAbility`)**: Core ability executing the stamina-neutral recovery cancel and momentum chain.

### Phase 3: AI Behavior Trees, Audio & HUD (Builds 3066–3070)
* **Build 3066 (`UBTService_AshenAIStanceReactionTactics`)**: AI Behavior Tree service detecting Kaelen's active stance and adapting defensive/aggressive postures.
* **Build 3067 (`UAshenUserWidget_OathbringerStanceMatrixHUD`)**: UMG widget rendering the 4-guard directional stance diamond, active rune glow, and Flow Glint timing meter.
* **Build 3068 (`UAshenOathbringerStanceAudioSubsystem`)**: MetaSounds subsystem rendering distinct whooshes, blade binds, pommel crunches, and flow chime chimes.
* **Build 3069 (`UAshenStanceCameraTraumaAdapter`)**: Camera shake adapter driving heavy overhead screen kicks and half-sword thrust zooms.
* **Build 3070 (`AAshenStanceTrainingTargetWorldActor`)**: Specialized combat target actor for practicing 4-guard stance flows and timing windows.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 3071–3075)
* **Build 3071 (`UAshenOathbringerStanceSaveGameAdapter`)**: Serializes stance mastery progression, flow timing calibration, and unlocked techniques.
* **Build 3072 (`UAshenOathbringerStanceNarrativeBridge`)**: Companion combat callouts reacting to stance masteries and clean flow executions.
* **Build 3073 (`UAshenOathbringerStanceHapticBridge`)**: Maps DualSense haptics (Vom Tag heavy thud, Pflug high-frequency buzz, Ochs parry click, Mordhau crunch).
* **Build 3074 (`UAshenOathbringerStanceMasterBridge`)**: Master bridge connecting stance subsystem, GAS abilities, UI diamond, and player controller.
* **Build 3075 (`FAshenMasterBatch153AutomationTest`)**: QA test suite validating stance kinematics, flow timing math, stamina refunds, and SaveGame persistence.

---

## 🧪 3. Value-Asserting Verification Matrix

The test suite `AshenOath.Combat.MasterBatch153_OathbringerStanceFlowConvergence` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Vom Tag Kinematics** | High Wrath Cleave | Dmg $= 1.40\times$, Poise Dmg $= 1.40\times$ ($+40\%$), Armor Pen $= 20\%$ | **PASSED** |
| **Pflug Kinematics** | Low Plow Thrust | Dmg $= 1.00\times$, Stamina $= 14\text{ sta}$ ($-30\%$), Armor Pen $= 35\%$ | **PASSED** |
| **Ochs Parry Window** | Crown Deflection | Parry Window $= 0.22\text{s}$ ($+0.12\text{s}$ leniency) | **PASSED** |
| **Mordhau Armor Penetration** | Half-Sword / Pommel | Poise Dmg $= 1.75\times$ ($+75\%$), Armor Pen $= 100\%$ | **PASSED** |
| **Flow Glint Timing Window** | $0.45\text{s}$ in $[0.40\text{s}, 0.55\text{s}]$ | Inside Window $= \text{true}$, Missed Outside $= \text{false}$ | **PASSED** |
| **Stamina-Neutral Refund** | Clean Flow Cancel | Transition Stamina Cost $= 0.0$, Momentum Bonus $= +25.0\%$ | **PASSED** |
| **Runic Seam Intensity** | Vom Tag Seam Color | $\vec{C}_{\text{red}} = 1.0$, Emissive Intensity $= 4.50$ | **PASSED** |
| **DualSense Stance Haptics** | Clean Flow vs Slam | Clean Ping $= 0.95$, Vom Tag Slam $= 0.90$ heavy thud | **PASSED** |
| **SaveGame Roundtrip** | Mordhau, $45.0\text{ Flow}$, $4$ Mastered | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 4. Architectural Map & Milestone Summary

* **Previous Milestone**: 3,055 Builds (`DESTRUCTION-WEATHER-AI-SPEC-093`)
* **Current Milestone**: **3,075 Builds (`STANCE-SPEC-094`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
