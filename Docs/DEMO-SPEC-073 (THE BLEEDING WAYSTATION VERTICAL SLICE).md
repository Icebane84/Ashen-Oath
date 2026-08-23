# DEMO-SPEC-073: THE BLEEDING WAYSTATION (THE REPLAYABLE VERTICAL SLICE VIGNETTE)

**Canonical Document Identifier:** `DEMO-SPEC-073`  
**Master Batch:** #132 (Builds 2636–2655)  
**Total Production Builds:** 2,655 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / StateTree / Behavior Trees / MetaSounds / Gameplay Ability System (GAS)  
**Architecture Domain:** Scenarios / Combat / AI / Audio / UI / World / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Vertical Slice Vignette Specification  
**V-Control:** 2026-08-23T13:10:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`DEMO-SPEC-073` translates the 7-minute closed-loop micro-scenario blueprint (**"The Bleeding Waystation"**, `PRS-DOC-2026-0820-007` & `PRS-DOC-2026-0822-001`) into production C++:

1. **Causal Propagation over Branching Trees**:
   * Instead of 3 distinct narrative cutscenes, the game features **one physical space** (a ruined Heartstone waystation courtyard), **one pinned Order scout catalyst**, and **one 90-second combat problem** (1 Heavy Brute + 3 Grunts).
   * Consequence propagates continuously through the `FSoulStateVector`, companion StateTree formation spacing ($300\text{uu} \leftrightarrow 1200\text{uu}$), support hesitation latencies ($0\text{ms} \leftrightarrow 600\text{ms}$), and forensic Campfire Journal annotations.
2. **The 4-Run Relational Matrix**:
   * **Run A (Shadow Harvest)**: Kaelen absorbs residual taint (+35% damage, desaturated vision). Garrett approves pragmatically; Serafina retreats to $1000\text{uu}$ distance with a $300\text{ms}$ ward delay.
   * **Run B (Pure Grace)**: Sparing and proper stone burial (+0.15 Resolve). Serafina steps into tight $300\text{uu}$ formation with instant recovery auras; Garrett covers flanks.
   * **Run C (The Spiral)**: High Integration Debt ($\ge 0.75$) triggers auditory Oakhaven flashback hallucinations and an involuntary panic flash strike. Companions freeze in terror ($1200\text{uu}$ perimeter, $600\text{ms}$ panic lock).
   * **Run D (Avoidant Mercy / The Invariant Test)**: Sparing action identical to Run B, but executed with high debt ($0.80$). Diagnosed by `UAshenAvoidantMercyDiagnosisEvaluator` as *emotional dissociation/cowardice* (*"You couldn't even look him in the eye"*), maintaining $750\text{uu}$ guarded spacing.
3. **The Standardized "Knocked to One Knee" Benchmark**:
   * Holding the physical stagger event constant against the Heavy Brute proves relational computing:
     * **Run B**: Garrett executes a **Twin-Blade X-Lock Cross-Parry Deflect** (`UAshenGarrettTwinBladeXLockGASAbility`), locking the descending warhammer between crossed daggers with an upward torque scrape and point-blank kick!
     * **Run A**: Garrett throws an off-hand dagger peel to draw aggro.
     * **Run C**: Garrett draws twin daggers defensively against Kaelen (*"Garrett, STOP!"*).
     * **Run D**: Garrett holds a distant guarded stance.
4. **Forensic Campfire Journal**:
   * Replaces moral scorecard popups with multi-author forensic handwriting: Garrett's heavy charcoal marks, Serafina's fluid ink prayer, empty margins, or bleeding smudged text.

---

## 📐 2. The Bleeding Waystation Causal Dataflow

```
[ Catalyst: Pinned Scout ] ──► [ Player Choice / Soul State ]
                                      │
                                      ├── Run A (Harvest): Dmg +35%, Spacing 1000uu, Delay 300ms
                                      ├── Run B (Grace): Resolve +0.15, Spacing 300uu, Delay 0ms
                                      ├── Run C (Spiral): Involuntary Flash Strike, Spacing 1200uu, Delay 600ms
                                      └── Run D (Avoidant): Identical Sparing -> Diagnosed Dissociation (750uu)
                                      │
                                      ▼
[ 90s Combat Crucible ] ──────► [ Universal Benchmark: Knocked to One Knee ]
                                      │
                                      ├── Run B: Garrett Twin-Blade X-Lock Cross-Deflect + Serafina Ward
                                      ├── Run A: Garrett Dagger Flank Peel
                                      ├── Run C: Garrett Defensive Blade Abort Against Kaelen
                                      └── Run D: Garrett Hesitant Guarded Hold
                                      │
                                      ▼
[ Campfire Marginalia ] ──────► Charcoal Mark / Fluid Ink / Empty Margin / Smudged Text
```

---

## 📦 3. Master Batch #132 Production Manifest (Builds 2636–2655)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 2636–2640)
* **Build 2636 (`AshenBleedingWaystationTypes.h`)**: Enums (4), Structs (1), Multicast Delegates (4).
* **Build 2637 (`UAshenBleedingWaystationSubsystem`)**: Subsystem managing 7-minute loop, run state, and 90-second combat crucible.
* **Build 2638 (`UAshenCompanionFormationSpacingEvaluator`)**: Evaluates companion formation distances ($300\text{uu} \leftrightarrow 1200\text{uu}$).
* **Build 2639 (`UAshenStateTreeReactionDelayEvaluator`)**: Computes companion StateTree support hesitation delays ($0\text{ms} \leftrightarrow 600\text{ms}$).
* **Build 2640 (`UAshenAvoidantMercyDiagnosisEvaluator`)**: Diagnoses sparing decisions as Pure Grace vs Dissociated Avoidance based on debt.

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 2641–2645)
* **Build 2641 (`UAshenShadowHarvestGASAbility`)**: Kaelen drains residual taint for +35% damage and desaturated vision.
* **Build 2642 (`UAshenMercifulReleaseGASAbility`)**: Kaelen grants clean death and burial, boosting Resolve by +0.15.
* **Build 2643 (`UAshenGarrettTwinBladeXLockGASAbility`)**: Garrett's dual-wield cross-blade parry deflecting brute strikes.
* **Build 2644 (`UAshenSerafinaTransferenceWardGASAbility`)**: Serafina deploys instant recovery ward when formation is tight.
* **Build 2645 (`UAshenPanicFlashStrikeGASAbility`)**: Involuntary panic swing triggered under high integration debt (450 damage).

### Phase 3: AI Behavior Trees, World Actors & HUD (Builds 2646–2650)
* **Build 2646 (`UBTTask_AshenGarrettWaystationTactics`)**: AI task directing Garrett to execute X-lock vs peel vs abort.
* **Build 2647 (`AAshenPinnedScoutWorldActor`)**: Physicalized pinned Order scout actor with 3 interactive catalyst options.
* **Build 2648 (`UAshenUserWidget_WaystationCrucibleHUD`)**: UMG widget displaying formation spacing radar and hesitation gauge.
* **Build 2649 (`UAshenWaystationAudioSubsystem`)**: MetaSounds subsystem synthesizing twin-blade metal scrape and healing chimes.
* **Build 2650 (`AAshenWaystationCourtyardAnchorActor`)**: Spatial anchor defining the ruined courtyard boundary (1500cm radius).

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2651–2655)
* **Build 2651 (`UAshenWaystationSaveGameAdapter`)**: Serializes 4-run completion, scout decisions, and companion formation metrics.
* **Build 2652 (`UAshenWaystationDialogueBridge`)**: Injects Garrett's dual-wield barks and Serafina's reactions across all 4 runs.
* **Build 2653 (`UAshenWaystationHapticBridge`)**: Maps twin-blade X-lock torque and panic tremor to DualSense triggers.
* **Build 2654 (`UAshenWaystationMasterBridge`)**: Master bridge coordinating all waystation subsystems, audio, and HUD.
* **Build 2655 (`FAshenMasterBatch132AutomationTest`)**: QA test suite verifying formation spacing, hesitation delays, X-lock, and Run D diagnosis.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Scenarios.MasterBatch132_BleedingWaystationCrucible` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Run B (Grace) Spacing** | Serafina & Garrett | $300\text{uu}$ (Tight Wedge) & $350\text{uu}$ | **PASSED** |
| **Run A (Harvest) Spacing** | Serafina Distance | $1000\text{uu}$ (Alienated Perimeter) | **PASSED** |
| **Run C (Spiral) Spacing** | Serafina Distance | $1200\text{uu}$ (Terrified Distance) | **PASSED** |
| **StateTree Hesitation Delay** | Run B ($0\text{ms}$) vs Run A ($300\text{ms}$) vs Run C ($600\text{ms}$) | Exact reaction latency scaling | **PASSED** |
| **Run D Invariant Diagnosis** | Sparing with Debt $= 0.20$ vs Debt $= 0.85$ | Pure Grace (Run B) vs Avoidant Mercy (Run D) | **PASSED** |
| **DualSense Trigger Resistance** | Run B (X-Lock Torque) vs Run C (Panic Tremor) | Resistance $= 0.85$ vs Tremor $= 0.95$ | **PASSED** |
| **SaveGame Persistence** | Run B, Clean Death, Distance $= 300\text{uu}$, Delay $= 0\text{ms}$ | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,635 Builds (`KINETIC-SPEC-072`)
* **Current Milestone**: **2,655 Builds (`DEMO-SPEC-073`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
