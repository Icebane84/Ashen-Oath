# MAP-SPEC-088: THE TACTICAL MAP OVERHAUL & FAST TRAVEL SANCTUARY WAYPOINT SUBSYSTEM

**Canonical Document Identifier:** `MAP-SPEC-088`  
**Master Batch:** #147 (Builds 2936–2955)  
**Total Production Builds:** 2,955 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / MetaSounds / DualSense Haptics  
**Architecture Domain:** World / Combat / AI / Audio / UI / Core / Orchestration / Narrative / QA  
**Authority Level:** Canonical Tactical Cartography, Fog of War & Fast Travel Specification  
**V-Control:** 2026-08-26T13:25:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`MAP-SPEC-088` implements the comprehensive **Tactical Map Overhaul & Fast Travel Sanctuary Waypoint Subsystem**, dynamic fog-of-war revelation grids, beacon attunement mechanics, and travel hazard encounters:

1. **Cartographic Fog of War & Elevation Revelation**:
   * Dynamic exploration unveil radius scaling ($500\text{uu} \leftrightarrow 2500\text{uu}$) based on party elevation and torch light.
   * High-ground lookout vantage survey clearing $3500\text{uu}$ fog chunks in a single gaze.
   * Cartographic parchment shader with procedural sepia tone, ink contour etching, and border vignetting.

2. **Sanctuary Beacon Attunement & 3.0s Fast Travel**:
   * Four distinct waypoint states: `UndiscoveredShadow`, `DiscoveredBeacon`, `AttunedSanctuary`, and `ContestedCorrupted`.
   * White Flame beacon brazier ignition unlocking permanent fast travel teleportation.
   * $3.0\text{s}$ channeled teleportation between attuned sanctuaries consuming $15\text{ stamina/km}$.

3. **Overland Travel Hazard & Ambush Skirmishes**:
   * Ambush risk formula ($0.0 \leftrightarrow 75.0\%$) based on route length ($3\%/\text{km}$) and regional corruption ($+40\%$).
   * Seasoned ember-salt provisions halve ambush probability by $50\%$.
   * Roadside ambush triggers instant combat transition with $-15\%$ surprise posture mitigation penalty.

4. **Audio & DualSense Cartographic Sensation Haptics**:
   * MetaSounds parchment map rustle, $432\text{Hz}$ harmonic sanctuary beacon resonance hums, and teleportation whoosh sweeps ($200\text{Hz}-1200\text{Hz}$).
   * DualSense map border drag friction resistance ($0.20 \leftrightarrow 0.85$), beacon attunement tactile heartbeat, and teleportation snap impulse.

---

## 📦 2. Master Batch #147 Production Manifest (Builds 2936–2955)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 2936–2940)
* **Build 2936 (`AshenTacticalMapTypes.h`)**: Enums (`EWaypointBeaconState`, `ETravelHazardType`, `EMapRegionBiome`), Structs (`FTacticalWaypointVector`, `FTravelHazardEncounterVector`), Multicast Delegates (4).
* **Build 2937 (`UAshenTacticalMapWaypointSubsystem`)**: Central world subsystem governing world map nodes, beacon attunement, and fast travel routing.
* **Build 2938 (`UAshenFogOfWarCartographyEvaluator`)**: Evaluator computing fog-of-war revelation radius ($500-2500\text{uu}$) and lookout unveil zones.
* **Build 2939 (`UAshenTravelHazardAmbushEvaluator`)**: Evaluator calculating travel ambush probability ($0-75\%$) based on region corruption and route length.
* **Build 2940 (`UAshenSanctuaryFastTravelDirectorComponent`)**: Component coordinating beacon ignition, provision consumption, and teleportation transitions.

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 2941–2945)
* **Build 2941 (`UAshenFastTravelTeleportGASAbility`)**: Ability channeling fast travel teleport between attuned campfire beacons.
* **Build 2942 (`UAshenIgniteSanctuaryBeaconGASAbility`)**: Ability igniting and attuning an ancient campfire beacon with White Flame.
* **Build 2943 (`UAshenGarrettCartographerSurveyGASAbility`)**: Garrett ability surveying surroundings from high ground, expanding fog unveil by $+50\%$.
* **Build 2944 (`UAshenTravelAmbushSurpriseGASAbility`)**: Hazard ability executing roadside ambush skirmish encounter.
* **Build 2945 (`UAshenSanctuaryRecallGASAbility`)**: Emergency recall ability warping the party back to the last visited hearth sanctuary.

### Phase 3: AI Behavior Trees, Audio & HUD (Builds 2946–2950)
* **Build 2946 (`UBTService_AshenRoadsideAmbushAITactics`)**: AI service driving coordinated roadside bandit/wraith ambush tactics during travel interruptions.
* **Build 2947 (`UAshenUserWidget_TacticalMapHUD`)**: UMG full-screen interactive cartographic map with fog mask, beacon markers, and fast travel prompts.
* **Build 2948 (`UAshenTacticalMapAudioSubsystem`)**: MetaSounds subsystem synthesizing parchment unfold, beacon attunement hums ($432\text{Hz}$), and fast travel whooshes.
* **Build 2949 (`UAshenMapParchmentPostProcessAdapter`)**: Post-process adapter driving cartographic sepia ink shader and boundary vignetting.
* **Build 2950 (`AAshenSanctuaryBeaconWorldActor`)**: Spatial world actor representing the stone campfire beacon with glowing hearth fire and waypoint collider.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2951–2955)
* **Build 2951 (`UAshenTacticalMapSaveGameAdapter`)**: Serializes discovered beacons, fog-of-war revelation bitmask grids, and active waypoint pins.
* **Build 2952 (`UAshenTacticalMapNarrativeBridge`)**: Companion fast travel barks and region lore observations upon beacon discovery.
* **Build 2953 (`UAshenTacticalMapHapticBridge`)**: Maps DualSense parchment map boundary friction ($0.20 \leftrightarrow 0.85$) and beacon attunement heartbeat pulse.
* **Build 2954 (`UAshenTacticalMapMasterBridge`)**: Master orchestrator connecting tactical map subsystem, GAS travel abilities, UMG map HUD, and audio.
* **Build 2955 (`FAshenMasterBatch147AutomationTest`)**: QA test suite validating fog unveil math, ambush hazard calculations, beacon attunement state transitions, and SaveGame persistence.

---

## 🧪 3. Value-Asserting Verification Matrix

The test suite `AshenOath.World.MasterBatch147_TacticalMapFastTravelSanctuaryWaypoint` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Base Fog Unveil Radius** | No torch, ground level | Radius $= 800.0\text{uu}$ | **PASSED** |
| **Torch Fog Unveil Radius** | Torch lit | Radius $= 1200.0\text{uu}$ | **PASSED** |
| **Lookout Vantage Survey** | High ground spyglass | Radius $= 3500.0\text{uu}$ | **PASSED** |
| **Travel Ambush Probability** | $10\text{km} @ 0.50$ corruption | Ambush Risk $= 50.0\%$ | **PASSED** |
| **Ember-Salt Provision Risk** | Seasoned rations active | Ambush Risk $= 25.0\%$ ($-50\%$) | **PASSED** |
| **Surprise Posture Penalty** | Roadside Ambush | Posture Mitigation $= 0.85\times$ ($-15\%$) | **PASSED** |
| **Fast Travel Stamina Cost** | $5\text{km}$ journey | Stamina $= 75.0$ ($15/\text{km}$) | **PASSED** |
| **DualSense Boundary Friction** | Map cursor at edge | Resistance $= 0.85$ | **PASSED** |
| **SaveGame Roundtrip** | Caldera waypoint, $8$ disc, $5$ att | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 4. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,935 Builds (`COOKING-SPEC-087`)
* **Current Milestone**: **2,955 Builds (`MAP-SPEC-088`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
