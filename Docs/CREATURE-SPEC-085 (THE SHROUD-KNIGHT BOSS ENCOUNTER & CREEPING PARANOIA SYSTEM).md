# CREATURE-SPEC-085: THE SHROUD-KNIGHT BOSS ENCOUNTER & CREEPING PARANOIA SYSTEM

**Canonical Document Identifier:** `CREATURE-SPEC-085`  
**Master Batch:** #144 (Builds 2876–2895)  
**Total Production Builds:** 2,895 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / MetaSounds / AI BehaviorTree / DualSense Haptics  
**Architecture Domain:** Combat / AI / Audio / UI / World / Core / Orchestration / Narrative / QA  
**Authority Level:** Canonical Boss Encounter & Creeping Paranoia Specification  
**V-Control:** 2026-08-24T11:28:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`CREATURE-SPEC-085` implements the full **Shroud-Knight Boss Encounter**, dynamic phase-shifting translucency, the **Creeping Paranoia** sensory infection system, and the coordinated 3-way **Trinity Strike** finisher based on `WLF-CREA-SHROUD-KNIGHT`:

1. **The 2.1-Meter Corrupted Shroud-Knight**:
   * Towering commander of Greywatch Outpost with rusted plate armor, weeping Nyx bile breastplate, and 5 twitching green-and-violet visor eyes.
   * **Phase-Shift Translucency Shader (`MAT_ShroudKnight_Base`)**:
     * Material dithering opacity switches from $1.00$ (Physical Solid) down to $0.15$ (Spectral Phasing).
     * Disables collision dynamically, allowing the boss to glide through solid stone obstacles and take $90\%$ reduced damage from standard physical strikes.

2. **Creeping Paranoia Sensory Infection**:
   * Inflicted dynamically on Kaelen as infection scales from $0.0 \to 1.0$:
     * **Dark Oily Vignette**: Heavy screen edge constriction ($0.0 \leftrightarrow 0.85$).
     * **Chromatic Aberration Jitter**: Real-time RGB channel displacement ($0.0 \leftrightarrow 4.5$).
     * **Peripheral False Phantoms**: Hallucinatory silhouettes spawn strictly in the player's peripheral vision ($\ge 45^\circ$). If Kaelen turns his camera to look directly at them ($< 35^\circ$), they vanish into thin air!
     * **Companion Eye-Contact Grounding**: Aligning gaze directly with Garrett or Serafina physically bleeds off paranoia at $-0.15/\text{s}$.

3. **Coordinated 3-Way "Trinity Strike" Finisher**:
   * **Step 1 (Kaelen)**: Heavy kinetic guard break cleave shattering the knight's physical poise.
   * **Step 2 (Garrett)**: Shadow Thread piton anchor tethering the knight to the stones, locking out phase-shifting for $6.0\text{s}$.
   * **Step 3 (Serafina)**: White Flame Purge beam disintegrating the corrupted core for $3.5\times$ burst damage.

---

## 📦 2. Master Batch #144 Production Manifest (Builds 2876–2895)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 2876–2880)
* **Build 2876 (`AshenShroudKnightTypes.h`)**: Enums (`EShroudKnightPhaseState`, `EParanoiaInfectionTier`, `ETrinityStrikeStep`), Structs (`FShroudKnightBossVector`), Multicast Delegates (4).
* **Build 2877 (`UAshenShroudKnightBossSubsystem`)**: Central world subsystem managing boss phases, health gates (100% -> 66% -> 33%), and phase-shifting state.
* **Build 2878 (`UAshenCreepingParanoiaEvaluator`)**: Evaluator computing paranoia infection scalar ($0.0 \leftrightarrow 1.0$), peripheral phantom spawn angles ($\ge 45^\circ$), and eye-contact grounding.
* **Build 2879 (`UAshenPhaseShiftDitherEvaluator`)**: Evaluator calculating material dithering opacity mask ($1.00 \to 0.15$), collision passability, and mist trail velocity.
* **Build 2880 (`UAshenTrinityStrikeCoordinatorComponent`)**: Component tracking the 3-step Trinity Strike combo sequence (Guard Break -> Thread Anchor -> Flame Purge).

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 2881–2885)
* **Build 2881 (`UAshenShroudKnightPhaseShiftGASAbility`)**: Boss ability transitioning to intangible spectral mist (disables collision, dither 0.15).
* **Build 2882 (`UAshenCreepingParanoiaInfectionGASAbility`)**: Boss attack inflicting Creeping Paranoia on Kaelen (+0.25 infection).
* **Build 2883 (`UAshenTrinityGuardBreakGASAbility`)**: Kaelen step 1 ability breaking the knight's physical poise.
* **Build 2884 (`UAshenGarrettShadowAnchorGASAbility`)**: Garrett step 2 ability anchoring the knight with shadow threads (locks out phasing for 6s).
* **Build 2885 (`UAshenSerafinaTrinityPurgeGASAbility`)**: Serafina step 3 ability executing the White Flame Purge (3.5x finisher).

### Phase 3: AI Behavior Trees, Audio & HUD (Builds 2886–2890)
* **Build 2886 (`UBTService_AshenShroudKnightAITactics`)**: AI service controlling boss glitch-lurch strafing, wall phasing, and paranoia target prioritization.
* **Build 2887 (`UAshenUserWidget_ShroudKnightBossHUD`)**: UMG widget displaying 3-segment boss health bar, Creeping Paranoia meter, and Trinity Strike prompt.
* **Build 2888 (`UAshenShroudKnightAudioSubsystem`)**: MetaSounds subsystem synthesizing high-frequency paranoia ringing, glitch audio clicks, and howling wind.
* **Build 2889 (`UAshenParanoiaPostProcessAdapter`)**: Post-process adapter driving oily dark vignette, chromatic channel jitter (0.0-4.5), and peripheral phantom rendering.
* **Build 2890 (`AAshenShroudKnightEncounterBossActor`)**: Spatial 2.1m boss actor with 5 socketed twitching visor eyes, cloth shroud cards, and dynamic Nyx bile weeping.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2891–2895)
* **Build 2891 (`UAshenShroudKnightSaveGameAdapter`)**: Serializes boss encounter completion, Trinity Strike execution grade, and paranoia best times.
* **Build 2892 (`UAshenShroudKnightDialogueBridge`)**: Contextual companion barks and Eldrin whispers during boss phasing and Trinity Strike coordination.
* **Build 2893 (`UAshenShroudKnightHapticBridge`)**: Maps DualSense haptic jitter, phase-shift intangibility trigger release, and Trinity finisher impact.
* **Build 2894 (`UAshenShroudKnightMasterBridge`)**: Master orchestrator connecting boss encounter subsystem, paranoia shaders, AI behavior, and GAS abilities.
* **Build 2895 (`FAshenMasterBatch144AutomationTest`)**: QA test suite validating phase-shift dithering math, paranoia peripheral calculations, Trinity sequence flow, and SaveGame persistence.

---

## 🧪 3. Value-Asserting Verification Matrix

The test suite `AshenOath.Combat.MasterBatch144_ShroudKnightBossCreepingParanoiaTrinityStrike` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Physical Solid Dither** | Boss in Physical State | Opacity $= 1.00$, Collision $=$ Enabled | **PASSED** |
| **Spectral Phasing Dither** | Boss in Spectral Phasing | Opacity $= 0.15$, Collision $=$ Disabled | **PASSED** |
| **Peripheral Phantom Angle** | Gaze Angle $= 50.0^\circ$ | Visible $=$ True (Peripheral Gaze) | **PASSED** |
| **Focused Camera Angle** | Gaze Angle $= 20.0^\circ$ | Visible $=$ False (Phantom Vanishes) | **PASSED** |
| **Chromatic Aberration Jitter** | Infection $= 100\%$ | Jitter $= 4.50$ | **PASSED** |
| **Companion Eye Grounding** | Eye Contact $=$ True | Decay Rate $= -0.15/\text{s}$ | **PASSED** |
| **Trinity Strike Sequence** | None $\to$ Break $\to$ Lock $\to$ Purge | Step transitions validated | **PASSED** |
| **Trinity Finisher Burst** | Step 3 Purge Beam | Damage Multiplier $= 3.50\times$ | **PASSED** |
| **DualSense Trigger Slack** | Phasing State Active | Resistance $= 0.05$ (Completely Slack) | **PASSED** |
| **SaveGame Roundtrip** | Boss Defeated, Max Paranoia $= 0.65$ | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 4. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,875 Builds (`QUARTZ-SPEC-084`)
* **Current Milestone**: **2,895 Builds (`CREATURE-SPEC-085`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
