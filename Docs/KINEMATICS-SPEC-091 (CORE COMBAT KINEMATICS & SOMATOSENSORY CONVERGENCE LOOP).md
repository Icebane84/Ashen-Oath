# KINEMATICS-SPEC-091: CORE COMBAT KINEMATICS & SOMATOSENSORY CONVERGENCE LOOP

**Canonical Document Identifier:** `KINEMATICS-SPEC-091`  
**Master Batch:** #150 (Builds 2996–3015)  
**Total Production Builds:** 3,015 Builds Clean (0 Errors, 0 Warnings) — *3,000+ Milestone Officially Crossed!*  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / MetaSounds / DualSense Haptics  
**Architecture Domain:** Combat / Audio / AI / UI / Core / Orchestration / Narrative / World / QA  
**Authority Level:** Canonical System Convergence Specification (Equipment Weight ↔ Cardiac Stamina ↔ Poise-Break Hitstop ↔ Riposte Surges)  
**V-Control:** 2026-08-29T07:15:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`KINEMATICS-SPEC-091` implements the high-impact **Combat Kinematics & Somatosensory Convergence Loop**, binding equipment load weights, cardiac stamina pulse fatigue, poise-break hitstop time dilation, and perfect deflection White Flame surges into a unified tactical feedback loop:

```
┌─────────────────────────────────────────────────────────────────────────────────────────────┐
│                 CORE COMBAT KINEMATICS & SOMATOSENSORY CONVERGENCE LOOP                     │
│           Weight Classes ↔ Cardiac Stamina ↔ Poise Hitstop ↔ Perfect Parry Surge            │
└─────────────────────────────────────────────────────────────────────────────────────────────┘
                                               │
       ┌───────────────────────────────────────┼───────────────────────────────────────┐
       ▼                                       ▼                                       ▼
[ WEIGHT CLASS SCALING ]                [ CARDIAC EXHAUSTION FATIGUE ]          [ POISE BREAK & PARRY SURGE ]
• Light Load (<30% Load: 0.32s roll)    • Triggered at <35% Stamina             • Poise Shatter 0.20s Hitstop (0.02x)
• Medium Load (30-70% Load: 0.40s roll) • Swing Windup Slowdown (+25.0%)        • Directional Camera Trauma (+0.40)
• Heavy Load (>70% Load: 0.55s roll)    • Parry Recovery Penalty (+30.0%)       • DualSense Heavy Motor Stagger (0.95)
• Overburdened (>100% Load: 0.70s hop)  • DualSense Trigger Resistance (0.85)   • Perfect Parry: +50 Stamina, +35 Flame
• Dynamic i-Frames (0.28s to 0.05s)     • MetaSounds Heartbeat Thud Audio       • Riposte Attack Power Surge (+25.0%)
```

---

## 📦 2. Master Batch #150 Production Manifest (Builds 2996–3015)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 2996–3000)
* **Build 2996 (`AshenCombatKinematicsTypes.h`)**: Enums (`EAshenWeightClass`, `EPoiseStaggerState`, `EParryRiposteQuality`), Structs (`FCombatKinematicsVector`, `FDodgeScalingParameters`), Multicast Delegates (4).
* **Build 2997 (`UAshenCombatKinematicsConvergenceSubsystem`)**: World subsystem managing real-time convergence between equipment weight, stamina pulse, poise-break hitstop, and parry surges.
* **Build 2998 (`UAshenWeightClassDodgeEvaluator`)**: Evaluator calculating dynamic dodge roll duration ($0.32\text{s}-0.70\text{s}$), i-frame window ($0.28\text{s}-0.05\text{s}$), stamina cost ($15-50$), and launch forces.
* **Build 2999 (`UAshenCardiacExhaustionEvaluator`)**: Evaluator calculating swing windup slowdown ($+25\%$), parry recovery frames ($+30\%$), and trigger resistance ($0.85$).
* **Build 3000 (`UAshenPoiseBreakHitstopEvaluator`)**: Evaluator calculating hitstop time dilation ($0.02\times$), camera trauma ($+0.40$), and riposte damage buffs ($+25\%$).

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 3001–3005)
* **Build 3001 (`UAshenDynamicWeightDodgeGASAbility`)**: Dynamic dodge roll ability adapting launch velocity, i-frame timer, and stamina drain based on equipped weight class.
* **Build 3002 (`UAshenCardiacExhaustionDebuffGASAbility`)**: Debuff ability triggering heartbeat palpitations, slowed swings, and widened parry recovery windows.
* **Build 3003 (`UAshenPoiseBreakStaggerGASAbility`)**: Stagger state ability executing $0.20\text{s}$ time dilation, vulnerable riposte window, and guard break posture.
* **Build 3004 (`UAshenGlancingDeflectionRiposteGASAbility`)**: Perfect parry ability restoring $+50$ stamina, $+35$ White Flame charge, and granting $+25\%$ riposte power.
* **Build 3005 (`UAshenHeavyArmorPoiseHyperarmorGASAbility`)**: Heavy armor ability granting poise hyper-armor during heavy greatsword swing frames.

### Phase 3: AI Behavior Trees, Audio & HUD (Builds 3006–3010)
* **Build 3006 (`UBTService_AshenAIPoiseBreakPunishAI`)**: AI Behavior Tree service detecting wielder guard-break and commanding aggressive gap-closing punish strikes.
* **Build 3007 (`UAshenUserWidget_CombatKinematicsHUD`)**: UMG widget displaying real-time weight class icon, dynamic i-frame bar, cardiac pulse gauge, and riposte surge timer.
* **Build 3008 (`UAshenCombatKinematicsAudioSubsystem`)**: MetaSounds subsystem rendering heavy armor clank resonance, cardiac heartbeat thuds, and parry bell chimes.
* **Build 3009 (`UAshenPoiseHitstopCameraShakeAdapter`)**: Camera shake adapter executing directional camera kick on poise break and heavy roll impacts.
* **Build 3010 (`AAshenTrainingDummyKinematicsWorldActor`)**: Training dummy world actor for testing parry windows, stagger thresholds, and weight class rolls.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 3011–3015)
* **Build 3011 (`UAshenCombatKinematicsSaveGameAdapter`)**: Serializes weight class configuration, posture masteries, and combat calibration data.
* **Build 3012 (`UAshenCombatKinematicsNarrativeBridge`)**: Contextual companion dialogue barks during poise break stagger and perfect deflection ripostes.
* **Build 3013 (`UAshenCombatKinematicsHapticBridge`)**: Maps DualSense trigger resistance ($0.85$), poise break heavy motor impulse ($0.95$), and parry crisp click ($0.80$).
* **Build 3014 (`UAshenCombatKinematicsMasterBridge`)**: Master orchestrator bridging equipment, stamina, poise, audio, and GAS actuators.
* **Build 3015 (`FAshenMasterBatch150AutomationTest`)**: QA test suite validating weight roll curves, cardiac penalty math, hitstop dilation, and SaveGame persistence.

---

## 🧪 3. Value-Asserting Verification Matrix

The test suite `AshenOath.Combat.MasterBatch150_CoreCombatKinematicsConvergence` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Light Load Roll Kinematics** | $<30\%$ Load | Duration $= 0.32\text{s}$, i-Frames $= 0.28\text{s}$, Cost $= 15\text{ Stamina}$ | **PASSED** |
| **Heavy Load Roll Kinematics** | $>70\%$ Load | Duration $= 0.55\text{s}$, i-Frames $= 0.16\text{s}$, Cost $= 35\text{ Stamina}$ | **PASSED** |
| **Weight Ratio Classifier** | $10\text{kg}, 25\text{kg}, 40\text{kg}, 60\text{kg}$ on $50\text{kg}$ cap | Correctly evaluates `Light`, `Medium`, `Heavy`, `Overburdened` | **PASSED** |
| **Cardiac Windup Slowdown** | $<35\%$ Stamina | Swing Windup Multiplier $= 0.75\times$ ($-25\%$ speed) | **PASSED** |
| **Cardiac Parry Recovery** | $<35\%$ Stamina | Parry Recovery Multiplier $= 1.30\times$ ($+30\%$ penalty) | **PASSED** |
| **Poise Hitstop Time Dilation** | Guard Shatter | Dilation $= 0.02\times$, Duration $= 0.20\text{s}$ | **PASSED** |
| **Poise Break Camera Kick** | Guard Shatter | Camera Trauma $= +0.40$ | **PASSED** |
| **Perfect Parry Riposte Surge** | Perfect Deflection | Restores $+50$ Stamina, $+35$ Flame, $+25\%$ Riposte Dmg | **PASSED** |
| **DualSense Kinematics Haptics** | Exhaustion vs Deflection | Trigger Res $= 0.85$, Stagger Rumble $= 0.95$, Click $= 0.80$ | **PASSED** |
| **SaveGame Roundtrip** | $38.5\text{kg} / 50.0\text{kg}$, HeavyLoad | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 4. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,995 Builds (`CONVERGENCE-SPEC-090`)
* **Current Milestone**: **3,015 Builds (`KINEMATICS-SPEC-091`)** — *3,000+ Milestone Achieved!*
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
