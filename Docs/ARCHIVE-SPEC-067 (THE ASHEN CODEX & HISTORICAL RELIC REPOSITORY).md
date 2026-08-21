# ARCHIVE-SPEC-067: THE ASHEN CODEX & HISTORICAL RELIC REPOSITORY

**Canonical Document Identifier:** `ARCHIVE-SPEC-067`  
**Master Batch:** #126 (Builds 2516–2535)  
**Total Production Builds:** 2,535 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Behavior Trees / MetaSounds  
**Architecture Domain:** Archive / Combat / Audio / UI / AI / World / Narrative / Core / Orchestration / QA  
**Authority Level:** Canonical Master Specification  
**V-Control:** 2026-08-21T18:25:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`ARCHIVE-SPEC-067` delivers the comprehensive lore compendium and 3D relic examination system for *Ashen Oath*, connecting physical exploration with narrative depth and companion psychological growth:

1. **The Living Ashen Codex Chronicle**:
   * Archival lore repository tracking discovered Boss Anatomies, Sacred Relics, Faction Histories, Companion Chronicles, and World Geography (`UAshenCodexArchiveSubsystem`).
2. **Dynamic Companion Marginalia Commentary**:
   * `UAshenCodexMarginaliaEvaluatorComponent` injects companion-specific handwritten notes into the margins of unlocked lore pages based on Fellowship Trust ($\ge 0.60$) and personal history (e.g. Garrett's tactical vulnerability tips on boss wire joints).
3. **Interactive 3D Relic Examination & Solfeggio Resonance**:
   * Physicalized `AAshenHistoricalRelicPedestalWorldActor` with 3D orbital inspection camera (`UAshenInspectRelicGASAbility`).
   * `UAshenRelicInspectionEvaluatorComponent` detecting secret angle alignment ($|\theta_{\text{yaw}} - \theta_{\text{target}}| \le 15^\circ$) to reveal hidden pre-Fall runic scripts.
   * `UAshenCodexAudioSubsystem` synthesizing pure Solfeggio frequency hums ($396\text{ Hz}, 528\text{ Hz}, 741\text{ Hz}, 852\text{ Hz}$).
4. **Interactive Flashback Vignettes & Campfire Dialogue Openers**:
   * Examining key relics triggers memory flashback vignettes (`UAshenTriggerMemoryVignetteGASAbility`) and unlocks unique Campfire conversation topics via `UAshenCodexDialogueBridge`.

---

## 📐 2. The Archival Discovery & Examination Pipeline

```
[ Relic Pedestal In World ] ──► [ AAshenHistoricalRelicPedestalWorldActor ]
                                             │
                                             ▼
[ 3D Relic Examination Mode ] ─► [ UAshenInspectRelicGASAbility ]
                                             │
                                             ├──► Orbit Yaw Alignment (|Δθ| <= 15°)
                                             ├──► Solfeggio Resonance: 528 Hz / 741 Hz / 852 Hz
                                             └──► DualSense Haptic Tick Feedback (0.90)
                                             │
                                             ▼
[ Unlock Codex Lore Entry ] ───► [ UAshenCodexArchiveSubsystem ]
                                             │
                                             ├──► [ UAshenCodexMarginaliaEvaluatorComponent ]
                                             │     └── Companion Handwritten Margin Notes
                                             │
                                             └──► [ UAshenCodexDialogueBridge ]
                                                   └── Injects Campfire Topic Prompts
```

---

## 📦 3. Master Batch #126 Production Manifest (Builds 2516–2535)

### Phase 1: Data Contracts, Subsystems & Evaluators (Builds 2516–2520)
* **Build 2516 (`AshenCodexArchiveTypes.h`)**: Enums (3), Structs (2), Multicast Delegates (4).
* **Build 2517 (`UAshenCodexArchiveSubsystem`)**: Subsystem managing player-unlocked codex lore entries and relic discovery states.
* **Build 2518 (`UAshenRelicInspectionEvaluatorComponent`)**: Computes 3D inspection orbital angles, alignment tolerances, and decipher progress.
* **Build 2519 (`UAshenCodexMarginaliaEvaluatorComponent`)**: Injects companion-specific handwritten margin commentary based on trust.
* **Build 2520 (`UAshenHistoricalLoreRegistryComponent`)**: Manages master dictionary of canonical lore templates and relic definitions.

### Phase 2: Gameplay Ability System (GAS) & Archival Actuators (Builds 2521–2525)
* **Build 2521 (`UAshenInspectRelicGASAbility`)**: Ability engaging 3D relic examination mode with orbital camera and audio hum.
* **Build 2522 (`UAshenDecodeRunicInscriptionGASAbility`)**: Ability deciphering ancient runic scripts on relics.
* **Build 2523 (`UAshenTriggerMemoryVignetteGASAbility`)**: Ability activating interactive psychological flashback vignettes.
* **Build 2524 (`UAshenCodexBookmarkAnnotationGASAbility`)**: Ability placing player bookmarks and companion marginalia pins in the codex.
* **Build 2525 (`UAshenRelicResonancePurgeGASAbility`)**: Ability purging corrupted relic blight to yield purified soul embers.

### Phase 3: AI Behavior Trees, World Actors & HUD (Builds 2526–2530)
* **Build 2526 (`UBTTask_AshenCompanionExamineLoreRelic`)**: AI task directing companion to inspect discovered relic pedestal.
* **Build 2527 (`AAshenHistoricalRelicPedestalWorldActor`)**: Interactive world actor holding inspectable ancient relics with glowing glyphs.
* **Build 2528 (`UAshenUserWidget_CodexRepositoryHUD`)**: UMG widget rendering the Ashen Codex book interface with companion marginalia.
* **Build 2529 (`UAshenCodexAudioSubsystem`)**: MetaSounds audio subsystem generating parchment page flips and Solfeggio hums.
* **Build 2530 (`UAshenRelicGlowVFXComponent`)**: Component modulating dynamic emissive pulse on relics.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2531–2535)
* **Build 2531 (`UAshenCodexSaveGameAdapter`)**: Serializes unlocked lore catalog and discovered relics.
* **Build 2532 (`UAshenCodexDialogueBridge`)**: Generates Campfire narrative conversation prompts from discovered codex entries.
* **Build 2533 (`UAshenCodexHapticBridge`)**: Maps page turns, rotation detents, and secret glyph alignment into DualSense haptics.
* **Build 2534 (`UAshenCodexMasterBridge`)**: Master bridge coordinating codex UI, relic world actors, audio, and GAS abilities.
* **Build 2535 (`FAshenMasterBatch126AutomationTest`)**: Comprehensive QA test suite verifying lore unlocking, marginalia injection, 3D angles, and SaveGame persistence.

---

## 🧪 4. Value-Asserting Verification Matrix

The test suite `AshenOath.Archive.MasterBatch126_CodexRepository` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Codex Entry Unlocking** | Unlock `Lore_Titan_Nightsteel` | `bIsUnlocked = true`, count $= 1$, duplicate unlock rejected | **PASSED** |
| **Relic 3D Alignment** | Yaw $= 185^\circ$, Target $= 180^\circ$, Tol $= 15^\circ$ | `bAligned = true`, Dwell $2.5\text{s} / 5.0\text{s} = 0.50$ | **PASSED** |
| **Companion Marginalia** | Garrett Trust $= 0.85$ ($\ge 0.60$) | Note contains `"tension wires"` (Tactical vulnerability insight) | **PASSED** |
| **Solfeggio Resonance** | Rare Artifact / Sacred Heirloom / Titan Core | Rare $= 528\text{ Hz}$, Sacred $= 741\text{ Hz}$, Titan $= 852\text{ Hz}$ | **PASSED** |
| **SaveGame Serialization** | Unlocked Lore List $= 2$ Entries | Exact restoration of lore IDs and count across save/load | **PASSED** |

---

## 🏛️ 5. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,515 Builds (`TACTICAL-SPEC-066`)
* **Current Milestone**: **2,535 Builds (`ARCHIVE-SPEC-067`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
