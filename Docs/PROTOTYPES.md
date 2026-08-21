# Ashen Oath: Interactive Specification Registry

**Authority:** `PRS-001 / Interactive Prototyping & Repository Integration Standard`  
**Status:** Active Production Testbed (Zero-Dependency Vanilla HTML5 + Web Audio API)  
**V-Control:** 2026-08-21T08:15:00Z  

---

## 🏛️ Executive Overview

The **Ashen Oath Interactive Specification Registry** houses double-clickable, zero-dependency HTML5/Canvas/WebAudio prototypes that allow designers, engineers, and collaborators to interactively feel and test core gameplay math in real-time ($< 10\text{ms}$ startup) without requiring full Unreal Engine 5.8 shader cooking or compilation passes.

All prototypes are strictly non-destructive, offline-first (Faraday Cage compliant), and maintain 100% mathematical parity with our C++ production subsystems.

---

## 🎮 Master Interactive Catalog

| Prototype Name | Target C++ Subsystem | Spec ID | Core Mechanics Simulated | Direct Prototype Link |
| :--- | :--- | :--- | :--- | :--- |
| **Kinetic Cleave & Drag Sandbox** | [`UAshenMassKineticCleaveComponent`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Combat/AshenMassKineticCleaveComponent.h) | [`KINETIC-SPEC-060`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/KINETIC-SPEC-060%20%28THE%20MASS%20KINETIC%20CLEAVE%20&%20ENVIRONMENTAL%20FRACTURE%20ENGINE%29.md) | Mass kinetic energy ($E_k = \frac{1}{2}mv^2$), AnimMontage volume drag ($0.08$ floor), camera FOV snap ($90^\circ \to 76^\circ \to 96^\circ \to 90^\circ$), and blade whoosh audio synthesis. | [Launch Sandbox](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/kinetic_cleave_sandbox.html) |
| **Tripartite 60 BPM Resonance Sim** | [`UAshenTripartiteResonanceSubsystem`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Combat/AshenTripartiteResonanceSubsystem.h) | [`TRIO-SPEC-061`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/TRIO-SPEC-061%20%28THE%20TRIPARTITE%20RESONANCE%20&%20HARMONIZED%20FINISHER%20MATRIX%29.md) | 3-Step combo window progression, 60 BPM ($1.0\text{ Hz}$) Web Audio metronome pulse, DualSense haptic trigger resistance curves, and $3.5\times$ damage finisher resolution. | [Launch Simulator](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/tripartite_resonance_sim.html) |
| **Campfire Integration Hearth Sim** | [`UAshenCampfireHearthSubsystem`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Narrative/AshenCampfireHearthSubsystem.h) | [`CAMPFIRE-SPEC-062`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/CAMPFIRE-SPEC-062%20%28THE%20SOUL%20RECOVERY%20&%20INTEGRATION%20HEARTH%20ENGINE%29.md) | Three-Tier Integration Debt transmutation (`MinorRest`, `ReflectiveTransmute`, `SolemnVigil`), dynamic proximity seating ($250\text{uu} \leftrightarrow 800\text{uu}$), and living journal marginalia inspection. | [Launch Simulator](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/campfire_integration_sim.html) |
| **Sundered Sanctuary Boss Sim** | [`UAshenBossEncounterSubsystem`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Combat/AshenBossEncounterSubsystem.h) | [`ARENA-SPEC-063`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/ARENA-SPEC-063%20%28THE%20SUNDERED%20SANCTUARY%20BOSS%20ENCOUNTER%20ENGINE%29.md) | 3-Phase Multi-Tier escalation, Chaos destructible pillar sundering, companion pinning crisis window, and Empathic Transference rescue ($+0.20$ Trust). | [Launch Simulator](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/sundered_sanctuary_sim.html) |
| **Empathic Transference Sim** | [`UAshenEmpathicTransferenceSubsystem`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Combat/AshenEmpathicTransferenceSubsystem.h) | [`BURDEN-SPEC-057`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/BURDEN-SPEC-057%20%28THE%20EMPATHIC%20TRANSFERENCE%20&%20SHADOW%20BURNOUT%20MATRIX%29.md) | Damage absorption channeling, Shadow Burnout threshold scaling ($>0.70$ crisis), Web Audio 3500 Hz tinnitus ringing, and SELT telemetry clipboard export. | [Launch Simulator](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/empathic_transference_sim.html) |
| **Somatic Silence Classifier Sim** | [`UAshenSomaticSilenceClassifierSubsystem`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Companions/AshenSomaticSilenceClassifierSubsystem.h) | [`MIND-SPEC-058`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/MIND-SPEC-058%20%28THE%20SOMATIC%20SILENCE%20CLASSIFIER%20&%20AMBIENT%20INTENT%20READING%20MATRIX%29.md) | 3 Silence Modes (`Contemplative`, `TraumaticAftermath`, `DestabilizingCrisis`), wordless support path clearing, and "Nobody Follows" boundary refusal gates. | [Launch Simulator](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/somatic_silence_classifier.html) |

---

## 🛠️ Architecture & Development Standard

### 1. Zero-Dependency Mandate
Every prototype is built using standard:
* **HTML5 Canvas 2D**: 60 FPS visual simulations.
* **Web Audio API**: Real-time synthesized blade swooshes, metronome pulses, and crackling fire embers without external `.wav` or `.mp3` files.
* **Inline CSS/JS**: Instant double-click offline execution in any modern web browser.

### 2. State Vector Parity (`FSoulStateVector`)
All prototype telemetry binds to the shared 28-byte state vector mirror:
* [`Docs/Prototypes/shared/soul_kernel.js`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/shared/soul_kernel.js)
