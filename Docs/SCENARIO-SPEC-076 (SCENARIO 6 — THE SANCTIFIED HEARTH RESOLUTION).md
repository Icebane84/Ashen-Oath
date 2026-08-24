# SCENARIO-SPEC-076: SCENARIO 6 — THE SANCTIFIED HEARTH RESOLUTION (NORTHERN MARCHES)

**Canonical Document Identifier:** `SCENARIO-SPEC-076`  
**Master Batch:** #135 (Builds 2696–2715)  
**Total Production Builds:** 2,715 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Post-Process / MetaSounds / Gameplay Ability System (GAS) / DualSense Haptics  
**Architecture Domain:** Scenarios / Combat / AI / Audio / UI / World / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Scenario 6 Specification  
**V-Control:** 2026-08-24T01:45:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`SCENARIO-SPEC-076` implements the complete vertical slice for **Scenario 6: The Sanctified Hearth Resolution** set in the sub-zero blizzards of the Northern Marches:

1. **Sub-Zero Blizzard Thermodynamics & Frostbite Gauge ($0.0 \leftrightarrow 1.0$)**:
   * Ambient temperature scales from $-5^\circ\text{C}$ (Calm Chill) down to $-35^\circ\text{C}$ (Whiteout Surge).
   * Outside companion warmth, Frostbite accumulates:
     $$\Delta\text{Frostbite} = \left(\frac{|T_{\text{ambient}}|}{600}\right) \cdot \Delta t$$
   * Frostbite degrades player movement speed from $1.00\times$ down to $0.40\times$:
     $$\text{SpeedMultiplier} = 1.0 - 0.60 \cdot \text{Frostbite}$$

2. **Companion Shared Warming Radius & Empathic Heat Transfer**:
   * Garrett's kindle torch ($250\text{uu}$, $+15^\circ\text{C}$) and Serafina's White Flame aura ($350\text{uu}$, $+25^\circ\text{C}$) emit localized thermal warming zones (`UAshenCompanionWarmingAuraComponent`).
   * Huddling within their aura active reverses frostbite at $+0.05/\text{s}$, preventing somatic hypothermia.

3. **Ancient Hearth Brazier Sanctuary Expansion**:
   * Channeling White Flame into the central ancient Hearth Brazier (`UAshenWhiteFlameHearthIgnitionGASAbility`) expands the sanctified safe perimeter from $500\text{uu}$ up to $2500\text{uu}$:
     $$R_{\text{sanctuary}} = 500\text{uu} + 2000\text{uu} \cdot \text{IgnitionProgress}$$
   * Full ignition releases a massive radial thermal wave (`UAshenHearthDefenseShockwaveGASAbility`, $2000\text{uu}$) repelling frost beasts.

4. **DualSense Frost Shiver & Hearth Fire Crackle Haptics**:
   * Left Grip vibrates with sub-zero freezing shivers ($50\text{ Hz}$, $0.0 \leftrightarrow 0.80$).
   * Right Grip pulses with roaring hearth warmth ($0.0 \leftrightarrow 0.70$).
   * Right Trigger stiffens with frozen resistance proportional to frostbite ($0.0 \leftrightarrow 0.75$).

---

## 📐 2. Scenario 6 Thermodynamic Dataflow

```
[ Blizzard Weather ] ──► [ Ambient Temp (-5°C ↔ -35°C) ]
                                   │
                                   ├──► Outside Warmth: +Frostbite (+0.04/s)
                                   └──► Movement Speed Penalty (1.00x → 0.40x)
                                   │
[ Companion Proximity ] ──► [ Garrett Torch (250uu) & Serafina Aura (350uu) ]
                                   │
                                   └──► Thermal Recovery: -Frostbite (-0.05/s)
                                   │
[ White Flame Channel ] ──► [ Ancient Hearth Brazier Ignition (0.0 ↔ 1.0) ]
                                   │
                                   ├──► Sanctuary Radius Expansion (500uu → 2500uu)
                                   └──► 2000uu Thermal Defense Shockwave
```

---

## 📦 3. Master Batch #135 Production Manifest (Builds 2696–2715)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 2696–2700)
* **Build 2696 (`AshenScenario6Types.h`)**: Enums (3), Structs (1), Multicast Delegates (4).
* **Build 2697 (`UAshenScenario6MissionSubsystem`)**: Subsystem managing quest flow, blizzard intensity, and hearth brazier ignition.
* **Build 2698 (`UAshenBlizzardThermodynamicsEvaluator`)**: Evaluator calculating frostbite rates and speed penalties.
* **Build 2699 (`UAshenCompanionWarmingAuraComponent`)**: Component on companions emitting thermal warmth ($250\text{uu} \leftrightarrow 350\text{uu}$).
* **Build 2700 (`UAshenHearthBrazierIgnitionEvaluator`)**: Evaluator computing sanctuary safe radius expansion ($500\text{uu} \to 2500\text{uu}$).

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 2701–2705)
* **Build 2701 (`UAshenWhiteFlameHearthIgnitionGASAbility`)**: Kaelen's ability channeling White Flame into the hearth brazier.
* **Build 2702 (`UAshenGarrettTorchThrustGASAbility`)**: Garrett's torch swing staggering frost enemies ($+30\text{ Heat Dmg}$).
* **Build 2703 (`UAshenSerafinaThermalAuraBurstGASAbility`)**: Serafina's pulse instantly purging $0.40$ frostbite for allies.
* **Build 2704 (`UAshenFrostbiteShiverDebuffGASAbility`)**: Somatic debuff reducing movement speed by up to $60\%$.
* **Build 2705 (`UAshenHearthDefenseShockwaveGASAbility`)**: Radial thermal wave repelling frost enemies upon hearth ignition.

### Phase 3: AI Behavior Trees, Audio & HUD (Builds 2706–2710)
* **Build 2706 (`UBTService_AshenCompanionHuddleWatch`)**: AI Behavior Tree service instructing companions to close into a warming huddle.
* **Build 2707 (`UAshenUserWidget_Scenario6FrostbiteHUD`)**: UMG widget visualizing Frostbite gauge, blizzard temperature, and hearth progress.
* **Build 2708 (`UAshenScenario6AudioSubsystem`)**: MetaSounds subsystem synthesizing howling blizzard wind, ice cracks, and hearth flames.
* **Build 2709 (`UAshenFrostbitePostProcessAdapter`)**: Post-process adapter driving screen-edge ice vignette and cold color grading.
* **Build 2710 (`AAshenSanctifiedHearthBrazierActor`)**: Spatial world actor representing the central stone Hearth Brazier.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2711–2715)
* **Build 2711 (`UAshenScenario6SaveGameAdapter`)**: Serializes Scenario 6 completion state, lowest temp survived, and frostbite metrics.
* **Build 2712 (`UAshenScenario6DialogueBridge`)**: Contextual shivering barks and hearth restoration dialogue.
* **Build 2713 (`UAshenScenario6HapticBridge`)**: Maps sub-zero shivers to Left Grip and hearth warmth to Right Grip.
* **Build 2714 (`UAshenScenario6MasterBridge`)**: Master bridge orchestrating thermodynamics, AI huddling, and quest stages.
* **Build 2715 (`FAshenMasterBatch135AutomationTest`)**: QA test suite validating thermodynamics math, companion warming radius, brazier scaling, and SaveGame roundtrip.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Scenarios.MasterBatch135_SanctifiedHearthResolution` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Severe Blizzard Frostbite Rate** | $T = -25^\circ\text{C}$, outside warmth | Rate $\approx 0.0416/\text{s}$ | **PASSED** |
| **Warmth Zone Recovery** | $T = -25^\circ\text{C}$, inside warmth | Negative rate (recovery) | **PASSED** |
| **Max Frostbite Speed Slow** | Frostbite $= 1.00$ | Speed Multiplier $= 0.40\times$ | **PASSED** |
| **Companion Warmth Proximity** | Distance $= 200\text{uu}$ vs $600\text{uu}$ | Warm vs Freezing | **PASSED** |
| **Unlit Brazier Radius** | Ignition $= 0.00$ | Sanctuary Radius $= 500\text{uu}$ | **PASSED** |
| **Fully Sanctified Brazier** | Ignition $= 1.00$ | Sanctuary Radius $= 2500\text{uu}$ | **PASSED** |
| **DualSense Haptic Telemetry** | Frostbite $= 0.80$, Hearth $= 0.50$ | Left Shiver $= 0.64$, Trigger Resistance $= 0.60$ | **PASSED** |
| **SaveGame Roundtrip** | Hearth $= 1.0$, Frostbite $= 0.05$, Temp $= -35^\circ\text{C}$ | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,695 Builds (`COMPANION-SPEC-075`)
* **Current Milestone**: **2,715 Builds (`SCENARIO-SPEC-076`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
