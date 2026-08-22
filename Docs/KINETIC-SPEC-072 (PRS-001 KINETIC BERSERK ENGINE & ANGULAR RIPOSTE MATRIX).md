# KINETIC-SPEC-072: THE COMPLETE PRS-001 KINETIC BERSERK ENGINE & ANGULAR RIPOSTE MATRIX

**Canonical Document Identifier:** `KINETIC-SPEC-072`  
**Master Batch:** #131 (Builds 2616–2635)  
**Total Production Builds:** 2,635 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Chaos Destruction / MetaSounds / Gameplay Ability System (GAS) / Niagara  
**Architecture Domain:** Combat / AI / Audio / UI / World / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Combat Engine Specification  
**V-Control:** 2026-08-22T11:19:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`KINETIC-SPEC-072` unifies the remaining specialized micro-solvers from the **PRS-001 Kinetic Berserk Engine** (`C:\Users\Chris\Where Light Fades\Ashen Oath\Design and Technical\Combat Design\PRS-001_Kinetic_Berserk_Engine`) into the core *Ashen Oath* C++ architecture:

1. **Angular Clock-Face Riposte Mapping (`UAshenAngularCounterComponent`)**:
   * Inverts an incoming hostile 3D attack vector, projects it onto the player's 2D local plane, and computes the clock-face angle ($0^\circ - 360^\circ$).
   * Maps into a 4-Zone counter-riposte matrix (`VerticalOverhead`, `HorizontalLeft`, `HorizontalRight`, `DiagonalUnderhand`) to ensure the counter-montage mirrors the exact plane of the deflected blade.
2. **Dynamic Chaos Debris Audio Occlusion Linker (`UAshenDynamicDebrisOcclusionAudioLinker`)**:
   * Continuous multi-raycast acoustic solver calculating low-pass filter (LPF) cutoffs ($400\text{ Hz} \leftrightarrow 20,000\text{ Hz}$) based on the physical volume of fractured stone rubble blocking the camera's line-of-sight.
3. **Geometry Back-Face Exit Vector Niagara Shearing (`UAshenMassKineticNiagaraBridgeComponent`)**:
   * Traces weapon trajectories through solid masonry to compute the exact back-face exit coordinate and velocity shear vector, spawning directionally accurate planar dust and spark sheets.
4. **Automated Sphere-Sweep Camera Lock Hijack (`UAshenBerserkTargetTrackingComponent`)**:
   * Executes periodic $1200\text{cm}$ sphere sweeps during Berserk/Unchained frenzy, smoothly overriding player control rotation towards the nearest hostile target while preserving independent directional locomotion.

---

## 📐 2. The PRS-001 Kinetic Convergence Pipeline

```
[ Incoming Hostile Strike ]
          │
          ▼
┌──────────────────────────────────────────────────────────────────────────┐
│ UAshenAngularCounterComponent:                                           │
│ • Projects inverted strike vector to local 2D plane: θ = atan2(Right, Fwd)│
│ • Maps 4-Zone Riposte: Overhead (315°-45°), Right (45°-135°), etc.       │
└──────────────────────────────────────────────────────────────────────────┘
          │
          ▼
┌──────────────────────────────────────────────────────────────────────────┐
│ UAshenMassKineticNiagaraBridgeComponent:                                 │
│ • Blade penetration entry -> ExitCoordinate = Entry + (Traj * Depth)    │
│ • Spawns NS_PlanarCleaveDust along ExitShearTrajectory vector            │
└──────────────────────────────────────────────────────────────────────────┘
          │
          ▼
┌──────────────────────────────────────────────────────────────────────────┐
│ UAshenDynamicDebrisOcclusionAudioLinker:                                 │
│ • Raycasts through AAshenPhysicalizedDebrisRubbleActor bounds            │
│ • LPF(N) = Lerp(20000Hz, 400Hz, (N / 6)^0.65)                             │
└──────────────────────────────────────────────────────────────────────────┘
```

---

## 📦 3. Master Batch #131 Production Manifest (Builds 2616–2635)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 2616–2620)
* **Build 2616 (`AshenKineticBerserkTypes.h`)**: Enums (3), Structs (3), Multicast Delegates (4).
* **Build 2617 (`UAshenKineticBerserkSubsystem`)**: Central world subsystem managing global kinetic combat events and riposte signals.
* **Build 2618 (`UAshenAngularCounterComponent`)**: Inverts 3D attack vectors, projects to 2D local space, and computes $0^\circ-360^\circ$ clock-face angles.
* **Build 2619 (`UAshenDynamicDebrisOcclusionAudioLinker`)**: Computes continuous LPF frequency ($400\text{ Hz} \leftrightarrow 20,000\text{ Hz}$) through Chaos rubble.
* **Build 2620 (`UAshenMassKineticNiagaraBridgeComponent`)**: Traces blade exit coordinates through geometry back-faces for Niagara particle sheets.

### Phase 2: Gameplay Ability System (GAS) & Actuators (Builds 2621–2625)
* **Build 2621 (`UAshenAngularRiposteGASAbility`)**: Executes mirrored angular ripostes with $+35\%$ counter damage.
* **Build 2622 (`UAshenPlanarDebrisShearGASAbility`)**: Kinetic ability cleaving through structural masonry with Niagara particle ejection.
* **Build 2623 (`UAshenBerserkCameraLockGASAbility`)**: Activates $1200\text{cm}$ sphere-sweep target tracking camera lock during frenzy.
* **Build 2624 (`UAshenSubBassKineticStrikeGASAbility`)**: Generates heavy strikes with $30 \leftrightarrow 60\text{ Hz}$ sub-bass audio transients.
* **Build 2625 (`UAshenElasticFOVSnapGASAbility`)**: Controls camera FOV compression ($90^\circ \to 76^\circ$) and elastic pop ($96^\circ \to 90^\circ$).

### Phase 3: AI Behavior Trees, Camera Control & HUD (Builds 2626–2630)
* **Build 2626 (`UBTTask_AshenParryReactionStagger`)**: Directs enemy AI to stagger upon receiving a high-precision angular deflection.
* **Build 2627 (`UAshenBerserkTargetTrackingComponent`)**: Smoothly overrides control rotation towards nearest target during frenzy.
* **Build 2628 (`UAshenUserWidget_KineticBerserkHUD`)**: UMG widget displaying counter-attack angle compass, debris LPF, and Joules.
* **Build 2629 (`UAshenKineticAudioSubsystem`)**: MetaSounds subsystem synthesizing sub-bass transients and pitch down-tuning.
* **Build 2630 (`AAshenPhysicalizedDebrisRubbleActor`)**: Physicalized rubble actor registering with audio occlusion raycasts.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2631–2635)
* **Build 2631 (`UAshenKineticBerserkSaveGameAdapter`)**: Serializes kinetic combat metrics, perfect ripostes, and max kinetic Joules.
* **Build 2632 (`UAshenKineticBerserkDialogueBridge`)**: Injects companion praise/reactions during angular ripostes and fractures.
* **Build 2633 (`UAshenKineticBerserkHapticBridge`)**: Maps cutting resistance and sub-bass transients to DualSense triggers.
* **Build 2634 (`UAshenKineticBerserkMasterBridge`)**: Master bridge coordinating all PRS-001 modules, audio, camera, and HUD.
* **Build 2635 (`FAshenMasterBatch131AutomationTest`)**: QA test suite verifying angular ripostes, debris LPF falloff, and camera tracking.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Combat.MasterBatch131_PRS001KineticBerserkConvergence` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Clean Audio Cutoff** | 0 Rubble Chunks | $20,000\text{ Hz}$ (Unoccluded State) | **PASSED** |
| **Muffled Debris Cutoff** | 6 Rubble Chunks (Max) | $400\text{ Hz}$ (BuriedUnderRubble State) | **PASSED** |
| **Geometry Back-Face Exit Raycast** | Entry at $(100, 0, 50)$, Depth $40\text{cm}$ | Exit at $(140, 0, 50)$, Forward Trajectory | **PASSED** |
| **Manual Free Look Camera** | Mode $=$ Manual | Preserves Current Player Rotation | **PASSED** |
| **Automated Sphere Lock Camera** | Mode $=$ Automated, Target at $(500, 500, 0)$ | Interpolates Rotation to $\sim 45^\circ\text{ Yaw}$ | **PASSED** |
| **DualSense Trigger Resistance** | Play Rate $= 0.08\times$ Floor | Trigger Resistance $= 0.92$ (Dense Cutting Drag) | **PASSED** |
| **SaveGame Persistence** | Ripostes $= 14$, MaxJoules $= 6800\text{J}$, Fractures $= 8$ | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,615 Builds (`SCENARIO-SPEC-071`)
* **Current Milestone**: **2,635 Builds (`KINETIC-SPEC-072`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
