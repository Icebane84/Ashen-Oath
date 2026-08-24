# QUARTZ-SPEC-084: THE QUARTZ DYNAMIC 6-STEM MUSIC CONDUCTOR & SYMBIOTIC FLOW STATE

**Canonical Document Identifier:** `QUARTZ-SPEC-084`  
**Master Batch:** #143 (Builds 2856–2875)  
**Total Production Builds:** 2,875 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / Quartz Audio Subsystem / MetaSounds / Gameplay Ability System (GAS) / DualSense Haptics  
**Architecture Domain:** Audio / Combat / Narrative / UI / World / Core / Orchestration / AI / QA  
**Authority Level:** Canonical Interactive Audio & Flow State Specification  
**V-Control:** 2026-08-24T11:15:00Z  

---

## 🏛️ 1. Executive Summary & Design Mandate

`QUARTZ-SPEC-084` implements the comprehensive 6-stem dynamic combat score, Garrett's alchemical audio interventions, and the 8-second "Symbiotic Resonance" flow state based on `WLF-AUD-001-RESONANCE`:

1. **6 Real-Time Audio Stems Matrix**:
   * Running on the **Unreal Engine Quartz Audio Subsystem** (115 BPM, $521.7\text{ms}$ per beat):
     * `Stem_01` (Heavy Industrial Drums & 808 Sub-Bass): Kaelen's Shadow Sickness ($0.10 \to 1.00$).
     * `Stem_02` (Discordant Nightsteel Hum): Oathbringer's Whispers ($0.00 \to 1.00$ at $C \ge 0.25$; **silenced completely** in Flow State).
     * `Stem_03` (Soaring Solo Violin & Fiddle): Serafina's Empathic Anchor ($0.80$ baseline $\to 0.30$ in crisis $\to 1.00$ triumphant ostinato).
     * `Stem_04` (Driving Electric Guitars): Garrett's Sentinel Pacing ($0.00$ baseline $\to 0.70$ syncopated $\to 1.00$ clean chords).
     * `Stem_05` (Ethereal Paladin Choir): The Order's Gilded Illusion ($1.00$ baseline $\to 0.30$ glitching $\to 0.00$ swapped for human vocals).
     * `Stem_06` (Afro-Pop Syncopated Percussion): The Rhythmic Core of the Pack ($0.20$ baseline $\to 1.00$ driving uplifting groove).

2. **Garrett's Alchemical Dynamic Audio Filters**:
   * **Burning Steel Caltrops**: High-pass filter cuts Kaelen's heavy bass weight.
   * **Sulfurous Smoke Balm**: Low-pass filter drops cutoff frequency to $450\text{ Hz}$ (sensory deprivation dense fog).
   * **Sentinel's Vigil (Physical Tackle Intercept)**: Master side-chain compression ducks soundtrack to $-24\text{ dB}$ for $1.2\text{s}$ with visceral bone/mud slam haptics.
   * **Gloomwood Sap Needle**: Freezes corruption and drops audio pitch by $-12\text{ semitones}$.

3. **The 8-Second "Symbiotic Resonance" Flow State**:
   * Quantized to the next musical bar boundary on the 115 BPM downbeat.
   * Silences Stem 02 (Oathbringer nightsteel parasite).
   * Grants the party $+100\%$ stamina regeneration ($2.0\times$), $+30\%$ combo burst damage, and triggers Serafina's vocal anchor: *"I am holding the center. You will not break."*

---

## 📦 2. Master Batch #143 Production Manifest (Builds 2856–2875)

### Phase 1: Data Contracts, Core Solvers & Subsystems (Builds 2856–2860)
* **Build 2856 (`AshenQuartzAudioTypes.h`)**: Enums (`EQuartzAudioStem`, `ECombatFlowState`, `EAlchemicalAudioFilter`), Structs (`FQuartzStemMatrixState`), Multicast Delegates (4).
* **Build 2857 (`UAshenQuartzMusicConductorSubsystem`)**: Central world subsystem managing 6-stem Quartz audio clock, 115 BPM quantization, and stem crossfading.
* **Build 2858 (`UAshenStemGainMatrixEvaluator`)**: Evaluator calculating dynamic volume gains ($0.0 \leftrightarrow 1.0$) for all 6 stems based on Corruption, Burnout, and Flow state.
* **Build 2859 (`UAshenAlchemicalAudioFilterEvaluator`)**: Evaluator computing dynamic LPF cutoff ($450\text{ Hz}$), HPF cutoff, side-chain ducking ($-24\text{ dB}$), and $-12\text{ ST}$ pitch shifts.
* **Build 2860 (`UAshenSymbioticFlowDirectorComponent`)**: Component managing the 8-second Symbiotic Flow window, stamina multiplier ($2.0\times$), and pack vocals.

### Phase 2: Gameplay Ability System (GAS) & Combat Actuators (Builds 2861–2865)
* **Build 2861 (`UAshenSymbioticResonanceFlowGASAbility`)**: Activates the 8-second Symbiotic Flow state ($+100\%$ stamina regen, Stem 02 silence, $+30\%$ combo damage).
* **Build 2862 (`UAshenGarrettCaltropAudioGASAbility`)**: Deploys burning caltrops engaging the HPF bass-cut filter.
* **Build 2863 (`UAshenGarrettSmokeBalmAudioGASAbility`)**: Throws sulfurous smoke triggering the $450\text{ Hz}$ sensory deprivation LPF.
* **Build 2864 (`UAshenGarrettSentinelTackleAudioGASAbility`)**: Executes Sentinel's Vigil tackle triggering $-24\text{ dB}$ side-chain audio ducking.
* **Build 2865 (`UAshenSerafinaPackVocalsBuffGASAbility`)**: Triggers Serafina's vocal anchor aura buff granting $+20\%$ poise recovery.

### Phase 3: AI Behavior Trees, Audio & HUD (Builds 2866–2870)
* **Build 2866 (`UBTService_AshenQuartzRhythmCoordinator`)**: AI service synchronizing companion attack timings to the Quartz 115 BPM downbeat.
* **Build 2867 (`UAshenUserWidget_QuartzStemMatrixHUD`)**: UMG widget displaying 6-stem audio visualizer bars, BPM metronome, Flow state indicator, and active filters.
* **Build 2868 (`UAshenQuartzMetaSoundsGraphAdapter`)**: Audio adapter feeding real-time stem gain parameters and filter cutoffs into UE5 MetaSounds graphs.
* **Build 2869 (`UAshenSymbioticFlowPostProcessAdapter`)**: Post-process adapter driving warm golden radiant bloom and chromatic stabilization during Flow state.
* **Build 2870 (`AAshenQuartzAudioConductorActor`)**: Spatial world actor managing audio source localization and Quartz clock synchronization in combat arenas.

### Phase 4: SaveGame, Bridges & QA Automation Test Suite (Builds 2871–2875)
* **Build 2871 (`UAshenQuartzAudioSaveGameAdapter`)**: Serializes music transition preferences, unlocked vocal tracks, and rhythm metrics.
* **Build 2872 (`UAshenQuartzDialogueBridge`)**: Contextual companion barks triggered precisely on musical bar downbeats during Flow states.
* **Build 2873 (`UAshenQuartzHapticBridge`)**: Maps 115 BPM rhythm pulses to DualSense adaptive triggers and side-chain tackle rumble.
* **Build 2874 (`UAshenQuartzMasterBridge`)**: Master orchestrator linking Quartz music subsystem, GAS abilities, UI visualizers, and haptics.
* **Build 2875 (`FAshenMasterBatch143AutomationTest`)**: QA test suite validating 6-stem gain calculations, filter cutoffs, Flow state timing, and SaveGame persistence.

---

## 🧪 3. Value-Asserting Verification Matrix

The test suite `AshenOath.Audio.MasterBatch143_QuartzDynamic6StemConductorSymbioticFlow` verifies:

| Test Case | Scenario | Expected Value / Result | Status |
| :--- | :--- | :--- | :--- |
| **Baseline 6-Stem Gains** | $C = 0.00, B = 0.00$ | Stems: $[0.10, 0.00, 0.80, 0.00, 1.00, 0.20]$ | **PASSED** |
| **Flow State Parasite Silence** | Symbiotic Resonance Active | Stem 02 (Nightsteel) $= 0.00$ (Silenced) | **PASSED** |
| **Flow State Pack Convergence** | Symbiotic Resonance Active | Stems: $[0.05, 0.00, 1.00, 1.00, 0.00, 1.00]$ | **PASSED** |
| **Smoke Balm LPF Cutoff** | Sulfurous Smoke Active | LPF Cutoff $= 450.0\text{ Hz}$ | **PASSED** |
| **Sentinel Tackle Side-Chain** | Sentinel's Vigil Tackle | Side-Chain Gain $= -24.0\text{ dB}$ | **PASSED** |
| **Gloomwood Chemical Pitch** | Gloomwood Sap Chill | Pitch Offset $= -12.0\text{ semitones}$ | **PASSED** |
| **Flow State Stamina Regen** | Flow State Active | Multiplier $= 2.0\times$ ($+100\%$) | **PASSED** |
| **DualSense 115 BPM Rhythm** | Flow State Active | Pulse Gain $= 0.85$, Harmonic Vibe $= 0.60$ | **PASSED** |
| **SaveGame Roundtrip** | 115 BPM, Vocals True, 7 Flows | Exact state restoration across save/load | **PASSED** |

---

## 🏛️ 4. Architectural Map & Milestone Summary

* **Previous Milestone**: 2,855 Builds (`BLADE-SPEC-083`)
* **Current Milestone**: **2,875 Builds (`QUARTZ-SPEC-084`)**
* **Compilation Status**: **0 Errors, 0 Warnings** via UnrealBuildTool (UE 5.8 Development Win64).
