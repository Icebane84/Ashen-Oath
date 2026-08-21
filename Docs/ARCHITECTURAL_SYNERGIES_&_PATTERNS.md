# Ashen Oath: Architectural Synergies & Invariant Registry

**Canonical Document Identifier:** `SYNERGY-REGISTRY-001`  
**Master Milestone:** 2,455 Builds Clean (0 Errors, 0 Warnings)  
**Target Engine:** Unreal Engine 5.8 C++ / HTML5 Prototyping Harness / Automation Pre-Flight Arsenal  
**Authority Level:** Architectural Canon & Cross-Subsystem Knowledge Base  
**V-Control:** 2026-08-21T09:15:00Z  

---

## 🏛️ 1. Executive Mandate & Purpose

During the ongoing synthesis of **Ashen Oath's 2,455+ clean C++ production builds**, 12 domain-driven vertical slices, and live HTML5 mechanical prototypes, numerous **mathematical invariants, cross-domain synergies, and phenomenological design patterns** have been surfaced.

This registry serves as the **permanent, living knowledge base** to capture, preserve, and cross-reference these deep architectural patterns so they remain immutable across future development cycles, refactors, and expansions.

---

## 📚 2. Master Synergies & Invariant Index

| Synergy ID | Pattern Name | Target Domains / Specs | Core Impact & Subsystem Bridge |
| :--- | :--- | :--- | :--- |
| **`SYN-001`** | **The Companion Boundary Refusal Invariant** | `MIND-SPEC-058` / `ECOL-SPEC-053` / AI / BT | Companions refuse suicidal charges when Trust $<0.40$ or Debt $\ge 0.70$, eliminating robotic companion tropes. |
| **`SYN-002`** | **The Sandbox-to-SELT Telemetry Pipeline** | `SELT-001` / `Automation/` / HTML5 Harness | One-click clipboard export of browser simulation state directly into `Automation/selt_telemetry.jsonl` for pre-flight testing. |
| **`SYN-003`** | **Web Audio to MetaSounds Envelope Parity** | `BURDEN-SPEC-057` / Audio / MetaSounds | Auditioning high-frequency tinnitus curves ($3500\text{ Hz}$ un-mute at $>0.70$ burnout) in pure JS before baking into UE5 MetaSounds graphs. |
| **`SYN-004`** | **Radial Canvas Trigonometry to EQS Spatial Parity** | `CAMPFIRE-SPEC-062` / `COMPANION-SPEC-021` / World | Direct mapping between 2D canvas trigonometric staging and Unreal Engine 5 Environment Query System (EQS) radial tests ($250\text{uu} \leftrightarrow 800\text{uu}$). |
| **`SYN-005`** | **Kinetic Cleave Play-Rate Floor & FOV Dilation** | `KINETIC-SPEC-060` / Combat / Animation / Camera | Clamping weapon drag play-rate strictly to $\ge 0.08$ with dynamic FOV snap ($90^\circ \to 76^\circ \to 96^\circ$) to deliver massive weight without animation lockups. |
| **`SYN-006`** | **Tripartite 60 BPM DualSense Haptic Resonance** | `TRIO-SPEC-061` / Combat / Haptics / Audio | Synchronizing 60 BPM ($1.0\text{ Hz}$) auditory pulses with DualSense adaptive trigger resistance ($0.20 \to 0.60 \to 0.75 \to 1.00$) for 3-person finishers. |
| **`SYN-007`** | **Multi-Tier Chaos Sunder Obstruction Scaling** | `ARENA-SPEC-063` / World / Chaos / Boss | Structural pillar fracture plane ($Ax + By + Cz + D = 0$) directly driving arena obstruction scalars ($0\% \to 50\% \to 100\%$) and companion pinning crisis windows. |
| **`SYN-008`** | **Runic Mass-Momentum & Poise Scaling Invariant** | `RELIQUARY-SPEC-064` / `KINETIC-SPEC-060` / Crafting / Combat | Boss core and trauma hilt socketing dynamically scaling effective weapon mass ($45\text{kg} \leftrightarrow 220\text{kg}$), kinetic strike Joules, and Solfeggio harmonic chimes. |
| **`SYN-009`** | **Adaptive Trigger Priority & Directional Tactile Invariant** | `HAPTIC-SPEC-065` / Haptics / Narrative / Combat | Enforcing strict Priority 1 Dialogue Lockout ($100\%$) over combat stagger and ambient somatic resistance, with directional grip threat motor bias. |
| **`SYN-010`** | **Temporal Bullet-Time Dilation & Finisher Multiplier** | `TACTICAL-SPEC-066` / Tactics / Combat / Audio | Squad command wheel smoothly ramping time dilation ($1.00\times \to 0.20\times$) and low-pass audio ($450\text{ Hz}$), with $2.50\times$ synchronized finisher burst damage. |

---

## 🔬 3. Detailed Architectural Synergy Profiles

---

### `SYN-010`: Temporal Bullet-Time Dilation & Finisher Multiplier

* **Target Subsystems:** `UAshenSquadTacticalSubsystem`, `UAshenTemporalDilationEvaluatorComponent`, `UAshenCoOpComboSynchronizerComponent`, `UAshenTacticalAudioSubsystem`
* **Related Specifications:** [`TACTICAL-SPEC-066`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/TACTICAL-SPEC-066%20%28THE%20TEMPORAL%20CO-OP%20COMBO%20SYNCHRONIZER%20&%20SQUAD%20COMMAND%20WHEEL%29.md), [`TRIO-SPEC-061`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/TRIO-SPEC-061%20%28THE%20TRIPARTITE%20RESONANCE%20&%20HARMONIZED%20FINISHER%20MATRIX%29.md)

#### 📐 Mathematical Invariants:
$$\text{TimeDilation}(t) = \begin{cases} 0.20, & \text{if Squad Command Wheel Open} \\ 0.05, & \text{if Synchronized Tripartite Impact Freeze} \\ 1.00, & \text{otherwise (Realtime)} \end{cases}$$
$$\text{DamageMultiplier}(N, \Delta t) = \begin{cases} 2.50\times, & \text{if } N=3 \land \Delta t \le 0.60\text{s} \\ 1.80\times, & \text{if } N=2 \land \Delta t \le 0.60\text{s} \\ 1.00\times, & \text{otherwise} \end{cases}$$
$$\text{AudioCutoff}(t) = \text{MapRangeClamped}(\text{TimeDilation}, 0.20 \to 1.00, 450\text{ Hz} \to 20,000\text{ Hz})$$

#### 💡 Architectural Insight & Impact:
* **Tactical Agency Without Interruption:** Rather than pausing gameplay, temporal bullet-time preserves the visceral kinetic momentum of combat while providing exact tactical control.
* **Audio-Visual Submersion:** Sweeping the audio filter down to $450\text{ Hz}$ when the wheel opens gives an immediate psychoacoustic sensation of deep tactical focus.

---

---

### `SYN-009`: Adaptive Trigger Priority & Directional Tactile Invariant

* **Target Subsystems:** `UAshenDualSenseHapticSubsystem`, `UAshenAdaptiveTriggerArbitratorComponent`, `UAshenDirectionalTactileTickComponent`, `UAshenControllerSpeakerWhisperComponent`
* **Related Specifications:** [`HAPTIC-SPEC-065`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/HAPTIC-SPEC-065%20%28THE%20DUALSENSE%20SOMATIC%20TACTILE%20WHISPER%20&%20CONTROLLER%20FEEDBACK%20ENGINE%29.md), [`SOMATIC-SPEC-050`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/SOMATIC-SPEC-050%20%28SOMATIC%20FRICTION%20&%20INPUT%20DELAY%20MATRIX%29.md)

#### 📐 Mathematical Invariant:
$$\text{WinningTriggerMode} = \begin{cases} \text{WeaponLockout (100\% hard stop)}, & \text{if Priority 1 (Dialogue Will Struggle)} \\ \text{SpringCollapse (0\% give-way)}, & \text{if Priority 2 (Poise Break)} \\ \text{SomaticFeedback}(m_{\text{weapon}}, \text{Dysreg}), & \text{if Priority 3 (Ambient Somatic)} \end{cases}$$
$$\text{DirectionalBias}(L, R) = \text{Norm}(\vec{F}_{\text{forward}} \times \vec{T}_{\text{threat}})_Z \implies \begin{cases} L = 1.0, R = 0.2, & \text{if Threat Left} \\ L = 0.2, R = 1.0, & \text{if Threat Right} \end{cases}$$

#### 💡 Architectural Insight & Impact:
* **The Physicalized Impasse:** When Kaelen enters a crisis dialogue, the player's physical trigger locks solid, converting emotional and narrative resistance into literal physical impedance.
* **Directional Subconscious Warning:** Off-screen flanking enemies pulse the corresponding controller grip motor before visual UI markers appear, creating instinctive player dodges based on tactile reflexes.

---

---

### `SYN-008`: Runic Mass-Momentum & Poise Scaling Invariant

* **Target Subsystems:** `UAshenRunicReliquarySubsystem`, `UAshenWeaponAttunementEvaluatorComponent`, `UAshenWeaponWeightSomaticAdapter`, `UAshenRunicChimeAudioSubsystem`
* **Related Specifications:** [`RELIQUARY-SPEC-064`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/RELIQUARY-SPEC-064%20%28THE%20RUNIC%20RELIQUARY%20&%20SOUL-FORGED%20WEAPON%20TRANSMUTATION%20MATRIX%29.md), [`KINETIC-SPEC-060`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/KINETIC-SPEC-060%20%28THE%20MASS%20KINETIC%20CLEAVE%20&%20ENVIRONMENTAL%20FRACTURE%20ENGINE%29.md)

#### 📐 Mathematical Invariants:
$$m_{\text{effective}} = \text{clamp}\left(m_{\text{base}} + \sum \Delta m_{\text{runes}}, 45.0\text{ kg}, 220.0\text{ kg}\right)$$
$$E_k = \frac{1}{2} \cdot m_{\text{effective}} \cdot \left(\frac{v}{100}\right)^2 \cdot \prod \text{PoiseMultiplier}$$
$$\text{SomaticResistance} = \text{MapRangeClamped}(m_{\text{effective}}, 45\text{kg}\to 200\text{kg}, 0.10 \to 0.95)$$

#### 💡 Architectural Insight & Impact:
* **The Transmutation Loop:** When a player defeats a boss, the raw kinetic thrill translates into permanent weapon weight and poise mastery.
* **Harmonic Resonance Tones:** Socketing attunement tiers emit pure Solfeggio harmonic frequencies in MetaSounds:
  * Resonant Tier 1: $528\text{ Hz}$ (Somatic Repair Tone)
  * Overcharged Tier 2: $741\text{ Hz}$ (Intuition / Clarity Tone)
  * Master-Forged Tier 3: $852\text{ Hz}$ (Boss Core Spiritual Transcendence)

---

---

### `SYN-001`: The Companion Boundary Refusal Invariant

* **Target Subsystems:** `UAshenSomaticSilenceClassifierSubsystem`, `UBTTask_AshenCompanionRespondToCrisis`, `UAshenEcologyOfFellowshipSubsystem`
* **Related Specifications:** [`MIND-SPEC-058`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/MIND-SPEC-058%20%28THE%20SOMATIC%20SILENCE%20CLASSIFIER%20&%20AMBIENT%20INTENT%20READING%20MATRIX%29.md), [`ECOL-SPEC-053`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/ECOL-SPEC-053%20%28THE%20ECOLOGY%20OF%20FELLOWSHIP%20%E2%80%94%20PATTERN%20CONTINUITY%2C%20ASYMMETRIC%20TRUST%20&%20REMEMBERED%20REPAIR%20MATRIX%29.md)
* **Live Interactive Prototype:** [`somatic_silence_classifier.html`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/somatic_silence_classifier.html)

#### 📐 Mathematical Invariant:
$$\text{BoundaryRefusal} = \begin{cases} \text{true}, & \text{if } (\text{IntegrationDebt} \ge 0.70) \lor (\text{Isolation} \ge 0.70) \lor (\text{FellowshipTrust} < 0.40) \\ \text{false}, & \text{otherwise} \end{cases}$$

#### 💡 Architectural Insight & Impact:
* **The Problem in Conventional Games:** In standard action RPGs, AI companions blindly follow the player into suicidal hazards, instantly destroying the illusion of human agency and emotional weight.
* **The Ashen Oath Solution:** When Kaelen is in acute psychological crisis or has alienated his fellowship, companions establish an explicit boundary standoff. They physically halt at an $800\text{uu}$ perimeter and refuse to participate in self-destructive charges.
* **C++ Implementation:** Injected as a Behavior Tree Decorator (`UBTDecorator_AshenCompanionBoundaryRefusal`) checking `FSoulStateVector` before executing movement tasks.

---

### `SYN-002`: The Sandbox-to-SELT Telemetry Pipeline

* **Target Subsystems:** `Automation/selt_audit.py`, `Automation/selt_telemetry.jsonl`, `Docs/Prototypes/*`
* **Related Specifications:** `SELT-001 (Sovereign Telemetry Protocol)`

#### 📐 Data Invariant:
```json
{
  "timestamp": "2026-08-21T09:00:00.000Z",
  "event_type": "EMPATHIC_TRANSFERENCE_INTERCEPT",
  "actor": "Kaelen",
  "burnout_level": 0.500,
  "garrett_trust": 0.650,
  "serafina_trust": 0.650,
  "coherence_index": 0.950
}
```

#### 💡 Architectural Insight & Impact:
* **The Pipeline Bridge:** Every HTML5 prototype is equipped with a `[Copy SELT Telemetry]` clipboard generator. 
* **Workflow Acceleration:** Designers can play a combat encounter in the web browser, generate real transaction event logs, and append them to `Automation/selt_telemetry.jsonl`.
* **Zero Entropy Pre-Flight:** Running `python Automation/run_all_checks.py` validates that the mean coherence index satisfies the $\ge 0.90$ threshold in $< 1\text{s}$.

---

### `SYN-003`: Web Audio to MetaSounds Envelope Parity

* **Target Subsystems:** `UAshenShadowBurnoutAudioEffectComponent`, `UAshenBossTensionAudioSubsystem`, Web Audio API
* **Related Specifications:** [`BURDEN-SPEC-057`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/BURDEN-SPEC-057%20%28THE%20EMPATHIC%20TRANSFERENCE%20&%20SHADOW%20BURNOUT%20MATRIX%29.md), [`ARENA-SPEC-063`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/ARENA-SPEC-063%20%28THE%20SUNDERED%20SANCTUARY%20BOSS%20ENCOUNTER%20ENGINE%29.md)
* **Live Interactive Prototype:** [`empathic_transference_sim.html`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/empathic_transference_sim.html)

#### 📐 Auditory Curve Invariant:
$$\text{TinnitusGain}(b) = \begin{cases} 0.0, & \text{if } b < 0.30 \\ 0.08 \cdot \frac{b - 0.30}{0.40}, & \text{if } 0.30 \le b < 0.70 \\ 0.25, & \text{if } b \ge 0.70 \end{cases} \quad (\text{Carrier Freq} = 3500\text{ Hz})$$

#### 💡 Architectural Insight & Impact:
* **The MetaSounds Rapid-Prototyping Loop:** Auditioning parametric audio filters in Unreal Engine requires setting up SoundCues, compiling MetaSounds graphs, and triggering gameplay events.
* **The Web Audio Advantage:** Using the browser's Web Audio API allows us to listen to and tune logarithmic volume ramps and cutoff frequencies in real-time, then transfer the exact mathematical float curves directly into Unreal Engine MetaSounds source nodes.

---

### `SYN-004`: Radial Canvas Trigonometry to EQS Spatial Parity

* **Target Subsystems:** `UAshenProximitySeatingStagingComponent`, `UAshenShepherdsGambitSubsystem`, `AAshenCampfireHearthActor`
* **Related Specifications:** [`CAMPFIRE-SPEC-062`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/CAMPFIRE-SPEC-062%20%28THE%20SOUL%20RECOVERY%20&%20INTEGRATION%20HEARTH%20ENGINE%29.md), `COMPANION-SPEC-021`
* **Live Interactive Prototype:** [`campfire_integration_sim.html`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/campfire_integration_sim.html)

#### 📐 Spatial Staging Invariant:
$$R_{\text{seating}} = \begin{cases} 250\text{ uu} \text{ (Intimate Fireside)}, & \text{if } (\text{Trust} \ge 0.65) \land (\text{IntegrationDebt} < 0.40) \\ 800\text{ uu} \text{ (Guarded Standoff)}, & \text{if } (\text{IntegrationDebt} \ge 0.70) \lor (\text{Trust} < 0.35) \\ 450\text{ uu} \text{ (Standard Proximity)}, & \text{otherwise} \end{cases}$$

#### 💡 Architectural Insight & Impact:
* **The EQS Connection:** Unreal Engine’s Environment Query System (EQS) relies on radial donut generators (`EnvQueryItemType_Point`).
* **Visual Calibration:** Calibrating companion angular offsets ($120^\circ$ Tripartite vs $45^\circ$ Fireside) on a 2D HTML5 canvas gives us the exact radial constraints needed for EQS query templates without trial-and-error in 3D level viewports.

---

### `SYN-005`: Kinetic Cleave Play-Rate Floor & FOV Dilation

* **Target Subsystems:** `UAshenMassKineticCleaveComponent`, `UAshenWeaponResistanceWarperComponent`
* **Related Specifications:** [`KINETIC-SPEC-060`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/KINETIC-SPEC-060%20%28THE%20MASS%20KINETIC%20CLEAVE%20&%20ENVIRONMENTAL%20FRACTURE%20ENGINE%29.md)
* **Live Interactive Prototype:** [`kinetic_cleave_sandbox.html`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/Prototypes/kinetic_cleave_sandbox.html)

#### 📐 Kinetic Drag Invariant:
$$\text{PlayRate}(V) = \max\left(0.08, 1.0 - \left(\frac{V_{\text{submerged}}}{V_{\text{max}}}\right) \cdot 0.92\right)$$
$$\text{CameraFOV}(t) = 90^\circ \xrightarrow{\text{drag}} 76^\circ \xrightarrow{\text{sunder snap}} 96^\circ \xrightarrow{\text{settle}} 90^\circ$$

#### 💡 Architectural Insight & Impact:
* **The Hit-Stop Dilemma:** Pure animation freeze (playrate $= 0.0$) feels like a glitch; linear slowdown feels weightless.
* **The Logarithmic Solution:** Clamping play-rate to a non-zero floor ($0.08\times$) combined with camera FOV contraction ($90^\circ \to 76^\circ$) simulates the blade violently biting through bone and stone while maintaining forward animation momentum.

---

## 🛠️ 4. Maintenance & Contribution Protocol

1. **When to Add a New Entry:**
   * Whenever a new Master Batch surfaces a cross-subsystem formula or invariant.
   * Whenever a new HTML5 prototype exposes an intuitive tuning curve or game feel principle.
2. **Standard Entry Format:**
   * Identifier (`SYN-XXX`)
   * Mathematical Invariant formula
   * Cross-Subsystem Bridge
   * Phenomenological Game Feel Impact
3. **Commit Mandate:**
   * Must be committed to Git alongside the relevant `Docs/*-SPEC-*.md` or `Docs/Prototypes/*.html` deliverables.
