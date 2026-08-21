# SCENARIO-SPEC-069: SCENARIO 2 — THE SENTINEL'S GAMBIT (SPIRE OF ELDERS JAILBREAK)

**Canonical Document Identifier:** `SCENARIO-SPEC-069`  
**Master Batch:** #128 (Builds 2556–2575)  
**Total Production Builds:** 2,575 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / StateTree / Behavior Trees / MetaSounds / Gameplay Ability System (GAS)  
**Architecture Domain:** Scenarios / AI / Combat / Audio / UI / World / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Scenario Specification  
**V-Control:** 2026-08-21T19:22:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`SCENARIO-SPEC-069` translates Scenario 2 of the *Ashen Oath: Vertical Slice Scenario Reference Guide* into production C++:

1. **Garrett's "Architect of Chaos" Archetype**:
   * Validates tactical "arrangement" over martyrdom.
   * `UUAshenStateTreeTask_GarrettDeployTrap` directs Garrett's companion AI to assess vault corridors, arming Tension Wire Snares, Phosphor Flare Mines, and Sonic Ravine Lures (`AAshenGarrettPhysicalTrapWorldActor`).
2. **AI Pathfinding Disruption & The LAW-001 Circuit Breaker**:
   * `UAshenPathfindingDisruptionEvaluatorComponent` computes navigation utility degradation ($\text{Utility} = \text{clamp}(\text{Base} - 0.25 \cdot N_{\text{traps}}, 0.0, 1.0)$).
   * When utility drops below $0.15$, the **LAW-001 Circuit Breaker** trips, forcing enemy AI into a "Failed Recovery" panic state (`UBTTask_AshenGhoulPathfindingPanic`) where ghouls route erratically and fall into environmental ravine hazards.
3. **Whispering Sickness & Phosphor Silhouettes**:
   * `UAshenWhisperingSicknessEvaluatorComponent` modulates post-process desaturation across vault zones.
   * `UAshenPhosphorSilhouetteVFXComponent` modulates high-contrast enemy silhouettes against White Flame phosphor emitters.
4. **DualSense Dual-Channel Haptic Spatialization**:
   * `UAshenScenario2HapticBridge` routes asymmetric DualSense motor channels:
     * **Left Motor**: Low-frequency sub-rumble tracking environmental Corruption ($0.85 \cdot \text{Corruption}$).
     * **Right Motor**: Crisp high-frequency sparks ($0.90$) when White Flame phosphor flares detonate.
5. **Memory Thread Journal Profiling**:
   * `UAshenScenario2SaveGameAdapter` records Garrett's tactical profile (`Calculated_Pragmatic`) and silent takedown metrics.

---

## 📐 2. The Scenario 2 Tactical Dataflow

```
[ Choke Point Survey ] ──► [ UUAshenStateTreeTask_GarrettDeployTrap ]
                                          │
                                          ▼
[ Physicalized Trap Placed ] ──► [ AAshenGarrettPhysicalTrapWorldActor ]
                                          │
                                          ▼ (Enemy Patrol Intersect)
[ Navigation Mesh Disruption ] ─► [ UAshenPathfindingDisruptionEvaluatorComponent ]
                                          │
                                          ├── Utility < 0.15 (LAW-001 Circuit Breaker Tripped)
                                          │     └── [ UBTTask_AshenGhoulPathfindingPanic ]
                                          │           └── Funnels Ghouls into Ravine Hazard
                                          │
                                          ├── [ UAshenScenario2HapticBridge ]
                                          │     ├── Left Channel: Corruption Sub-Rumble
                                          │     └── Right Channel: White Flame Spark
                                          │
                                          └── [ UAshenScenario2DialogueBridge ]
                                                └── Garrett 'Calculated_Pragmatic' Barks
```

---

## 📦 3. Master Batch #128 Production Manifest (Builds 2556–2575)

### Phase 1: Data Contracts, Subsystems & Evaluators (Builds 2556–2560)
* **Build 2556 (`AshenScenario2SentinelsGambitTypes.h`)**: Enums (3), Structs (2), Multicast Delegates (4).
* **Build 2557 (`UAshenScenario2MissionSubsystem`)**: Subsystem managing Spire of Elders jailbreak state, trap grid, and funnel counters.
* **Build 2558 (`UAshenGarrettTrapGridEvaluatorComponent`)**: Evaluates trap placement geometry, detonation radii, and choke points.
* **Build 2559 (`UAshenPathfindingDisruptionEvaluatorComponent`)**: Computes AI navigation degradation and LAW-001 circuit breaker state.
* **Build 2560 (`UAshenWhisperingSicknessEvaluatorComponent`)**: Computes Whispering Sickness post-process contamination and silhouettes.

### Phase 2: StateTree Tasks, GAS & Actuators (Builds 2561–2565)
* **Build 2561 (`UUAshenStateTreeTask_GarrettDeployTrap`)**: StateTree task driving Garrett to survey and deploy traps.
* **Build 2562 (`UAshenGarrettCaltropSnareGASAbility`)**: Ability deploying barbed tension wire Caltrop Snares.
* **Build 2563 (`UAshenGarrettPhosphorFlareGASAbility`)**: Ability launching high-contrast White Flame phosphor flares.
* **Build 2564 (`UAshenRavineLureBaitGASAbility`)**: Ability throwing sonic distraction lures near ravine ledges.
* **Build 2565 (`UAshenStealthTakedownSilentGASAbility`)**: Ability executing synchronized silent garrote takedowns ($+0.15$ Trust).

### Phase 3: AI Behavior Trees, World Actors & HUD (Builds 2566–2570)
* **Build 2566 (`UBTTask_AshenGhoulPathfindingPanic`)**: AI Task directing ghouls in failed recovery to panic into ravines.
* **Build 2567 (`AAshenGarrettPhysicalTrapWorldActor`)**: Physicalized world trap actor with tension cables and caltrops.
* **Build 2568 (`UAshenUserWidget_SentinelsGambitHUD`)**: UMG widget displaying trap slots, AI utility, and funneled counter.
* **Build 2569 (`UAshenSpireAudioSubsystem`)**: MetaSounds audio subsystem generating vault echoes and tension wire snaps.
* **Build 2570 (`UAshenPhosphorSilhouetteVFXComponent`)**: Component modulating dynamic high-contrast silhouette lighting.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2571–2575)
* **Build 2571 (`UAshenScenario2SaveGameAdapter`)**: Serializes jailbreak outcome, stealth score, and Garrett's tactical profile.
* **Build 2572 (`UAshenScenario2DialogueBridge`)**: Injects Garrett's pragmatic tactical dialogue into narrative journals.
* **Build 2573 (`UAshenScenario2HapticBridge`)**: Evaluates DualSense dual-channel haptics (Left Corruption vs Right White Flame).
* **Build 2574 (`UAshenScenario2MasterBridge`)**: Master bridge coordinating StateTree tasks, trap actors, audio, and HUD.
* **Build 2575 (`FAshenMasterBatch128AutomationTest`)**: QA test suite verifying trap placement, circuit breaker tripping, and haptics.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Scenarios.MasterBatch128_Scenario2SentinelsGambit` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Trap Registration** | Register `Trap_TensionWire_Choke1` | `bRegistered = true`, count $= 1$, duplicate rejected | **PASSED** |
| **LAW-001 Circuit Breaker** | Utility $0.85 \to 0.50 \to 0.10$ | `Normal` $\to$ `Degraded` $\to$ `CircuitBreakerTripped` ($<0.15$) | **PASSED** |
| **Trap Proximity Trigger** | Enemy at $141\text{cm}$ vs $400\text{cm}$ (Radius $350\text{cm}$) | Inside triggers $= \text{true}$, Outside triggers $= \text{false}$ | **PASSED** |
| **Dual-Channel Haptics** | Corruption $0.80$, Phosphor Flare Active | Left Rumble $= 0.68$, Right Spark $= 0.90$ | **PASSED** |
| **SaveGame Persistence** | Silent $= \text{true}$, Funneled $= 5$, Profile $= \text{Calculated\_Pragmatic}$ | Exact restoration of all tactical attributes across save/load | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,555 Builds (`SCENARIO-SPEC-068`)
* **Current Milestone**: **2,575 Builds (`SCENARIO-SPEC-069`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
