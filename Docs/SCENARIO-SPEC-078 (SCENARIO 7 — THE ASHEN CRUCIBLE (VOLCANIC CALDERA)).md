# SCENARIO-SPEC-078: SCENARIO 7 — THE ASHEN CRUCIBLE (VOLCANIC CALDERA)

**Canonical Document Identifier:** `SCENARIO-SPEC-078`  
**Master Batch:** #137 (Builds 2736–2755)  
**Total Production Builds:** 2,755 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Post-Process / MetaSounds / Gameplay Ability System (GAS) / DualSense Haptics  
**Architecture Domain:** Scenarios / Combat / AI / Audio / UI / World / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Scenario 7 Specification  
**V-Control:** 2026-08-24T09:58:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`SCENARIO-SPEC-078` implements the complete vertical slice for **Scenario 7: The Ashen Crucible** set within an active volcanic caldera:

1. **Extreme Volcanic Thermodynamics & Heat Exhaustion Gauge ($0.0 \leftrightarrow 1.0$)**:
   * Ambient volcanic caldera temperature ranges from $+45^\circ\text{C}$ (Caldera Rim) up to $+95^\circ\text{C}$ (Magma Core Chasm).
   * Outside cooling zones or cryo mist, Heat Exhaustion accumulates:
     $$\Delta\text{HeatExhaustion} = \left(\frac{T_{\text{ambient}} - 35^\circ\text{C}}{400}\right) \cdot \Delta t$$
   * Heat Exhaustion scales stamina consumption rate up to $+100\%$ ($1.00\times \to 2.00\times$) and inflicts up to $30\text{ Dmg/s}$ thermal burn at $>90\%$ heat:
     $$\text{StaminaDrainMultiplier} = 1.0 + 1.0 \cdot \text{HeatExhaustion}$$

2. **15-Second Magma Surge Hazard Cycles**:
   * Magma geysers and lava floor fissures erupt periodically on a 15-second cycle:
     * **Dormant Calm ($0\text{s} - 10\text{s}$)**: Low thermal risk.
     * **Telegraph Warning ($10\text{s} - 13\text{s}$)**: Ground fissures glow white-hot; AI evacuates radius ($450\text{uu}$).
     * **Active Eruption ($13\text{s} - 15\text{s}$)**: Lethal geysers dealing $150\text{ Heat Dmg/s}$ (`UAshenMagmaSurgeEruptionGASAbility`).

3. **Molten Weapon Tempering & Obsidian Piercing**:
   * Kaelen plunges his greatsword into active volcanic magma vents (`UAshenMoltenWeaponTemperingGASAbility`), heating the blade up to $800^\circ\text{C}$ for $+40\%$ fire damage and obsidian armor piercing.
   * Garrett drops alchemical cryo-mist traps (`UAshenGarrettCryoMistTrapGASAbility`), creating $300\text{uu}$ cooling oases that reverse heat exhaustion at $-0.05/\text{s}$.
   * Serafina conjures an Obsidian Thermal Barrier (`UAshenSerafinaObsidianBarrierGASAbility`) deflecting lava surge projectiles and absorbing $5000\text{ J}$ of heat.

4. **DualSense Searing Heat & Magma Explosion Haptics**:
   * Right Grip delivers high-frequency thermal vibrations ($90\text{ Hz}$) proportional to heat exhaustion and blade glow.
   * Left Trigger features heavy molten resistance ($0.85$).
   * Active magma geyser eruptions fire localized spatial explosion rumbles ($0.95$).

---

## 📐 2. Scenario 7 Thermodynamic Dataflow

```
[ Ambient Temp (+45°C ↔ +95°C) ] ──► [ Heat Exhaustion (0.0 ↔ 1.0) ]
                                             │
                                             ├──► Stamina Penalty (1.00x → 2.00x)
                                             ├──► Optical Heat Shimmer & Searing Vignette
                                             └──► DualSense 90Hz Thermal Vibration
                                             │
[ Magma Vent Interaction ] ────────► [ Blade Heating (20°C → 800°C) ]
                                             │
                                             └──► +40% Fire Damage & Molten Trigger Resistance
                                             │
[ Garrett Cryo Mist (300uu) ] ──────► Rapid Cooling Sanctuary (-0.05/s Heat Recovery)
```

---

## 📦 3. Master Batch #137 Production Manifest (Builds 2736–2755)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 2736–2740)
* **Build 2736 (`AshenScenario7Types.h`)**: Enums (3), Structs (1), Multicast Delegates (4).
* **Build 2737 (`UAshenScenario7MissionSubsystem`)**: Subsystem managing quest progression, volcanic caldera temperature, magma eruption cycles, and weapon tempering.
* **Build 2738 (`UAshenCalderaThermodynamicsEvaluator`)**: Evaluator calculating heat exhaustion rates, stamina drain multipliers ($1.00\times \leftrightarrow 2.00\times$), and thermal burn.
* **Build 2739 (`UAshenMoltenTemperingEvaluator`)**: Evaluator computing blade heat ($20^\circ\text{C} \leftrightarrow 800^\circ\text{C}$) and fire damage bonus ($0\% \to 40\%$).
* **Build 2740 (`UAshenMagmaSurgeHazardDirectorComponent`)**: Component coordinating 15-second magma surge eruption cycles.

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 2741–2745)
* **Build 2741 (`UAshenMoltenWeaponTemperingGASAbility`)**: Kaelen tempers blade in magma vent, raising blade heat to $800^\circ\text{C}$ for $+40\%$ fire damage.
* **Build 2742 (`UAshenGarrettCryoMistTrapGASAbility`)**: Garrett drops rapid-cooling cryo mist trap ($300\text{uu}$) reversing heat exhaustion.
* **Build 2743 (`UAshenSerafinaObsidianBarrierGASAbility`)**: Serafina conjures an obsidian wall deflecting lava projectiles ($5000\text{ J}$ absorption).
* **Build 2744 (`UAshenHeatExhaustionDebuffGASAbility`)**: Somatic debuff increasing stamina consumption and blurring peripheral vision.
* **Build 2745 (`UAshenMagmaSurgeEruptionGASAbility`)**: Environmental ability dealing $150\text{ Heat Dmg/s}$ in active eruption zones.

### Phase 3: AI Behavior Trees, Audio & HUD (Builds 2746–2750)
* **Build 2746 (`UBTService_AshenMagmaHazardAvoidance`)**: AI Behavior Tree service instructing companions to evade magma eruption fissures ($450\text{uu}$).
* **Build 2747 (`UAshenUserWidget_Scenario7CrucibleHUD`)**: UMG widget displaying Heat Exhaustion gauge, caldera temperature, and blade heat.
* **Build 2748 (`UAshenScenario7AudioSubsystem`)**: MetaSounds subsystem synthesizing bubbling magma, roaring geysers, and steam hiss audio.
* **Build 2749 (`UAshenHeatDistortionPostProcessAdapter`)**: Post-process adapter driving optical heat shimmer distortion and combustion vignette.
* **Build 2750 (`AAshenMagmaVentCrucibleActor`)**: Spatial world actor representing the central volcanic caldera crucible.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2751–2755)
* **Build 2751 (`UAshenScenario7SaveGameAdapter`)**: Serializes Scenario 7 completion state, highest heat survived, and tempered blade status.
* **Build 2752 (`UAshenScenario7DialogueBridge`)**: Injects contextual companion banter regarding extreme heat, cryo mist, and magma eruptions.
* **Build 2753 (`UAshenScenario7HapticBridge`)**: Maps searing thermal vibration ($90\text{ Hz}$), molten trigger resistance, and magma explosion rumble.
* **Build 2754 (`UAshenScenario7MasterBridge`)**: Master bridge orchestrating caldera thermodynamics, magma hazard cycles, and quest milestones.
* **Build 2755 (`FAshenMasterBatch137AutomationTest`)**: QA test suite validating heat exhaustion math, tempering damage scaling, magma surge cycles, and SaveGame persistence.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Scenarios.MasterBatch137_AshenCrucibleVolcanicCaldera` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Caldera Heat Exhaustion Rate** | $T = 75^\circ\text{C}$, outside cooling zone | Rate $\approx 0.10/\text{s}$ | **PASSED** |
| **Cryo Mist Heat Recovery** | $T = 75^\circ\text{C}$, inside cryo mist | Rate $=-0.05/\text{s}$ (Recovery) | **PASSED** |
| **Stamina Drain Multiplier** | Heat Exhaustion $= 0.50$ | Stamina Multiplier $= 1.50\times$ | **PASSED** |
| **Severe Thermal Burn Damage** | Heat Exhaustion $= 1.00$ | Thermal Burn $= 30.0\text{ Dmg/s}$ | **PASSED** |
| **Molten Blade Fire Bonus** | Blade Heat $= 800^\circ\text{C}$ | Fire Bonus $= +40\%$ ($0.40$) | **PASSED** |
| **Magma Surge Cycle Timing** | Time $= 11\text{s}$ vs $14\text{s}$ | Telegraph Warning vs Active Eruption | **PASSED** |
| **DualSense Thermal Haptics** | Heat $= 0.80$, Blade $= 800^\circ\text{C}$ | $90\text{ Hz}$ Pulse $\ge 0.70$, Trigger Resistance $= 0.85$ | **PASSED** |
| **SaveGame Roundtrip** | Max Temp $= 92^\circ\text{C}$, Blade $= 800^\circ\text{C}$ | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,735 Builds (`CHAOS-SPEC-077`)
* **Current Milestone**: **2,755 Builds (`SCENARIO-SPEC-078`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
