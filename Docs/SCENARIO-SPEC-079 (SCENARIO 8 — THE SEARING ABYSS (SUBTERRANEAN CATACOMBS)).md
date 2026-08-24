# SCENARIO-SPEC-079: SCENARIO 8 — THE SEARING ABYSS (SUBTERRANEAN CATACOMBS)

**Canonical Document Identifier:** `SCENARIO-SPEC-079`  
**Master Batch:** #138 (Builds 2756–2775)  
**Total Production Builds:** 2,775 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Post-Process / MetaSounds / Gameplay Ability System (GAS) / DualSense Haptics  
**Architecture Domain:** Scenarios / Combat / AI / Audio / UI / World / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Scenario 8 Specification  
**V-Control:** 2026-08-24T10:10:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`SCENARIO-SPEC-079` implements the complete vertical slice for **Scenario 8: The Searing Abyss** set within the pitch-black subterranean catacombs:

1. **Subterranean Darkness Blindness & Torch Fuel Endurance**:
   * Torch fuel / White Flame lantern endurance depletes over $120\text{s}$ ($-0.83\%/\text{s}$).
   * Illumination radius scales with remaining fuel:
     $$R_{\text{light}} = \text{clamp}(100\text{uu} + 700\text{uu} \cdot \text{TorchFuel01}, 100\text{uu}, 800\text{uu})$$
   * At $0\%$ fuel (Pitch Black Darkness, $\le 100\text{uu}$), soft lock-on is disabled, attack miss penalty rises to $+60\%$, and fear spikes Integration Debt at $+0.02/\text{s}$.

2. **Acoustic Echolocation & Sonar Propagation**:
   * Sound impulses physically echo through the catacombs revealing geometry contours:
     * **Footstep Echo**: $350\text{uu}$ radius.
     * **Blade Clang Echo** (`UAshenGarrettEcholocationTapGASAbility`): $900\text{uu}$ radius.
     * **Radiant Flare Pulse** (`UAshenSerafinaRadiantFlareGASAbility`): $1200\text{uu}$ radius for $6\text{s}$.
     * **Ground Slam Sonar** (`UAshenGroundSlamEcholocationGASAbility`): $1800\text{uu}$ shockwave revealing lurking predators.

3. **Subterranean AI Stalking & Ambush Mechanics**:
   * Abyss lurkers (`UBTService_AshenAbyssLurkerStalk`) actively stalk players outside the light perimeter ($>600\text{uu}$) and ambush in darkness.
   * Attacks on sonar-tagged enemies inflict $+75\%$ critical damage (`UAshenAbyssShadowStrikeGASAbility`).

4. **DualSense Pitch-Black Tactile Sonar & Lurker Heartbeat Haptics**:
   * Controller motors pulse with delicate tactile ticks synchronized with acoustic sonar wave expansion.
   * Lurking enemy proximity generates low-frequency heartbeats ($40\text{ Hz}$) scaling up to $0.85$ intensity within $800\text{uu}$.
   * Left Trigger stiffens with darkness fear resistance ($0.90$) in pitch black.

---

## 📐 2. Scenario 8 Darkness & Echolocation Dataflow

```
[ Torch Fuel Decay (120s) ] ──► [ Light Radius (800uu → 100uu) ]
                                          │
                                          ├──► Outside Light: +60% Miss Penalty & +0.02/s Fear Debt
                                          └──► Left Trigger Darkness Fear Resistance (0.90)
                                          │
[ Acoustic Impulse (Slam/Tap) ] ──► [ Echolocation Sonar Wave (350uu ↔ 1800uu) ]
                                          │
                                          ├──► Wireframe Terrain Contour Reveal
                                          ├──► Tag Stalking Abyss Lurkers (+75% Crit Damage)
                                          └──► DualSense 40Hz Lurker Heartbeat Haptics
```

---

## 📦 3. Master Batch #138 Production Manifest (Builds 2756–2775)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 2756–2760)
* **Build 2756 (`AshenScenario8Types.h`)**: Enums (3), Structs (1), Multicast Delegates (4).
* **Build 2757 (`UAshenScenario8MissionSubsystem`)**: Subsystem managing quest progression, torch fuel decay, illumination zones, and echolocation pings.
* **Build 2758 (`UAshenDarknessIlluminationEvaluator`)**: Evaluator calculating light radius ($100\text{uu} \leftrightarrow 800\text{uu}$), darkness miss penalty ($0\% \to 60\%$), and fear debt.
* **Build 2759 (`UAshenAcousticEcholocationEvaluator`)**: Evaluator computing sound wave propagation radius ($350\text{uu} \leftrightarrow 1800\text{uu}$) and sonar contour opacity.
* **Build 2760 (`UAshenTorchEnduranceComponent`)**: Component managing torch fuel burn rate over $120\text{s}$ and rekindling with resin.

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 2761–2765)
* **Build 2761 (`UAshenGroundSlamEcholocationGASAbility`)**: Kaelen's heavy sword strike sending an $1800\text{uu}$ sonar shockwave.
* **Build 2762 (`UAshenGarrettEcholocationTapGASAbility`)**: Garrett's twin-blade tap pinging lurking enemies in darkness ($900\text{uu}$).
* **Build 2763 (`UAshenSerafinaRadiantFlareGASAbility`)**: Serafina's radiant White Flame flare illuminating $1200\text{uu}$ and blinding abyss wights.
* **Build 2764 (`UAshenPitchBlackBlindnessDebuffGASAbility`)**: Somatic debuff applied in absolute darkness (miss chance $+60\%$).
* **Build 2765 (`UAshenAbyssShadowStrikeGASAbility`)**: Combat ability dealing $+75\%$ critical damage against sonar-revealed enemies.

### Phase 3: AI Behavior Trees, Audio & HUD (Builds 2766–2770)
* **Build 2766 (`UBTService_AshenAbyssLurkerStalk`)**: AI Behavior Tree service for abyss lurkers stalking outside the light perimeter ($600\text{uu}$).
* **Build 2767 (`UAshenUserWidget_Scenario8AbyssHUD`)**: UMG widget displaying Torch Fuel gauge, light radius meter, and sonar ping indicator.
* **Build 2768 (`UAshenScenario8AudioSubsystem`)**: MetaSounds subsystem synthesizing cavern reverberation, distant dripping, and sonar pings.
* **Build 2769 (`UAshenPitchBlackPostProcessAdapter`)**: Post-process adapter driving darkness screen vignette and sonar wireframe contour glow.
* **Build 2770 (`AAshenSubterraneanChasmActor`)**: Spatial world actor representing catacomb chasm drops and echo boundaries.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2771–2775)
* **Build 2771 (`UAshenScenario8SaveGameAdapter`)**: Serializes Scenario 8 completion state, remaining fuel, and discovered catacomb nodes.
* **Build 2772 (`UAshenScenario8DialogueBridge`)**: Contextual companion whispers, echoing guidance, and fear warnings in pitch black.
* **Build 2773 (`UAshenScenario8HapticBridge`)**: Maps acoustic sonar ticks, lurking heartbeats ($40\text{ Hz}$), and trigger fear resistance.
* **Build 2774 (`UAshenScenario8MasterBridge`)**: Master bridge orchestrating darkness illumination, echolocation sonar, audio, and quest flow.
* **Build 2775 (`FAshenMasterBatch138AutomationTest`)**: QA test suite validating light radius math, sonar propagation, darkness miss penalty, and SaveGame persistence.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Scenarios.MasterBatch138_SearingAbyssSubterraneanCatacombs` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Full Torch Illumination Radius** | $100\%$ fuel | Light Radius $= 800\text{uu}$ | **PASSED** |
| **Empty Torch Darkness Radius** | $0\%$ fuel | Light Radius $= 100\text{uu}$ | **PASSED** |
| **Pitch Black Attack Miss Penalty** | Light Radius $= 100\text{uu}$ | Miss Penalty $= 60\%$ ($0.60$) | **PASSED** |
| **Darkness Fear Integration Debt** | Light Radius $= 100\text{uu}$ | Debt Rate $= +0.02/\text{s}$ | **PASSED** |
| **Footstep Sonar Radius** | Footstep Echo | Radius $= 350\text{uu}$ | **PASSED** |
| **Ground Slam Sonar Radius** | Ground Slam | Radius $= 1800\text{uu}$ | **PASSED** |
| **Torch Fuel Burn & Rekindle** | $60\text{s}$ burn, $+0.30$ resin | $1.00 \to 0.50 \to 0.80$ | **PASSED** |
| **DualSense Lurker Heartbeat** | Lurker Proximity $= 200\text{uu}$ | Heartbeat $\approx 0.64$ ($40\text{ Hz}$) | **PASSED** |
| **SaveGame Roundtrip** | Fuel $= 0.65$, Light $= 555\text{uu}$, $5$ lurkers | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,755 Builds (`SCENARIO-SPEC-078`)
* **Current Milestone**: **2,775 Builds (`SCENARIO-SPEC-079`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
