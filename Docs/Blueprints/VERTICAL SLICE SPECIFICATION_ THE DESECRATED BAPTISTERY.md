# VERTICAL SLICE SPECIFICATION: THE DESECRATED BAPTISTERY

**Document ID:** `AOP-SLICE-BAPTISTERY-104-PROD`  
**V-Control:** `2026-08-30T15:30:00-04:00`  
**Primary Index:** `PRS-001` / `AOP-SLICE-BAPTISTERY-104`  
**Architecture Alignment:** `CONTRACT-SPEC-051` / `FSoulStateVector` / `TAM-001` / `RUNIC-FORGE-SPEC-098` / `AOP-COMBAT-SPEC-101` / `AOP-REWORK-HUNGER-103` / `AOP-MASTER-CONVERGENCE-SPEC-V2.0`  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Quartz Audio Subsystem / DualSense Hardware Actuators  
**Status:** Canon-Locked Production Blueprint (100% C++ Engine & QA Automation Alignment)  

---

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                VERTICAL SLICE SYSTEMIC CONVERGENCE FLOW                                         │
└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
                                                         │
 ┌───────────────────────────────────────────────────────┼───────────────────────────────────────────────────────┐
 ▼                                                       ▼                                                       ▼
[ BEATS 1–2: DISCIPLINE & BREACH ]             [ BEATS 3–4: LOSS OF CONTROL & BIND ]           [ BEATS 5–7: SYNCHRONIZATION ]
• Stance Weaving (Pflug ──► Vom Tag)           • Predatory Momentum (H = 0.65)                 • Asymmetric Companion Intercept
• 0.15s Flow Glint Transitions                 • Over-Swing (+0.35s) & Skew (+120uu)           • DualSense L2 Relief (245 ──► 0)
• Clean 150uu Formation                        • Soot Tunnel Vision / AI Buffer (650uu)        • 0.15s Cataclysm Vortex Finisher
• Martyrdom Trap (Break Formation)             • Calculated Deference Fulcrum (0.60s)          • Living Journal Commit (UMB-UI-004)
```

---

## 🏛️ SECTION I: Ontological Baseline & Constitutional Rectifications

Every mechanical subsystem within this vertical slice operates under the **Four Constitutional Laws** of Ashen Oath:

```
┌─────────────────────────────────────────────────────────────────────────────────────────────┐
│                          THE CLOSED-LOOP CAUSAL DATA PIPELINE                               │
└─────────────────────────────────────────────────────────────────────────────────────────────┘
                                               │
                                               ▼
   [ 1. PLAYER COMBAT ACTION ] ──► Over-swings, parries, posture breaks, deference binds
                                               │
                                               ▼
   [ 2. FMemoryImprintPayload ]  ──► Captures raw historical event + context tags
                                               │
                                               ▼
   [ 3. UAshenSoulPublisher ]    ──► Mutates CANONICAL PERSISTENT STATE ONLY:
                                     { Resolve R, Corruption C, Debt D, Isolation, GarrettTrust, SerafinaTrust }
                                               │
                                               ▼
   [ 4. FSomaticState ENGINE ]   ──► Evaluates DERIVED RUNTIME SIGNALS (Normalized Σ = 1.00):
                                     InternalFriction Φ = f(D, Isolation, Lens, Threat, R)
                                     ParasitePressure H = f(C, Φ, R)
                                     RelationalFlow   Ψ = f(TrioResonance, Threat, Proximity)
                                     IsolationPressure = f(Ψ, ProximityFactor)
                                               │
                                               ▼
   [ 5. SALIENCE GATE (Thalamus)]──► Enforces cooldowns & Meaningful Deltas (Δ >= 0.15)
                                               │
                                               ▼
   [ 6. DOWNSTREAM ACTUATORS ]   ──► THE EXPRESSION CONSISTENCY LAW:
                                     Input ──► Haptics ──► Audio ──► Shaders ──► Camera ──► AI ──► Journal
```

### 1. Constitutional Law IV: The Expression Consistency Law
> *"A canonical psychological or relational state transition must never manifest through only a single gameplay subsystem when multiple valid modalities exist."*
* A state transition synchronously manifests across the full matrix:
  $$\text{Input Agency} \longleftrightarrow \text{DualSense Haptics} \longleftrightarrow \text{Quartz Audio} \longleftrightarrow \text{Procedural Shaders} \longleftrightarrow \text{Camera Frustum} \longleftrightarrow \text{Companion AI} \longleftrightarrow \text{Living Journal}$$

### 2. Normalized Mathematical Manifolds ($\sum \text{coefficients} = 1.00$)
Governed by [`UAshenSoulDerivationSubsystem`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Soul/AshenSoulDerivationSubsystem.h):
* **Internal Friction ($\Phi_{\text{internal}}$):**
  $$\Phi_{\text{internal}} = \text{Clamp}\Big(0.25 \cdot D + 0.25 \cdot \text{Isolation} + 0.20 \cdot \text{LensShift} + 0.15 \cdot \text{Threat} + 0.15 \cdot (1.0 - R), \,\, 0.0, \,\, 1.0\Big)$$
* **Parasite Pressure ($H$ — Blade Hunger):**
  $$H = \text{Clamp}\Big(0.40 \cdot C + 0.35 \cdot \Phi_{\text{internal}} + 0.25 \cdot (1.0 - R), \,\, 0.0, \,\, 1.0\Big)$$
* **Relational Flow ($\Psi_{\text{relational}}$):**
  $$\Psi_{\text{relational}} = \text{Clamp}\Big(0.45 \cdot \text{TrioResonance} + 0.25 \cdot \text{ProximityFactor} + 0.20 \cdot (1.0 - \text{Threat}) + 0.10 \cdot \text{bSupportActive}, \,\, 0.0, \,\, 1.0\Big)$$
* **Isolation Pressure ($I$):**
  $$I = \text{Clamp}\Big(0.55 \cdot (1.0 - \Psi_{\text{relational}}) + 0.45 \cdot (1.0 - \text{ProximityFactor}), \,\, 0.0, \,\, 1.0\Big)$$

### 3. Rejection of "Clean Purging" (Contained vs. Purged)
Trauma is never erased or zeroed out. The climax of Beat 6 stabilizes at **$H = 0.28$ (Contained, never Purged)**, permanently integrating scars into Kaelen's recovery frames, weapon shaders, and journal marginalia.

---

## ⚔️ SECTION II: The Canonical 7-Beat Vertical Slice

* **Encounter Classification:** **Tier II (Trauma Inflection Point / Structural Fracture)**
* **Target Scenario:** Encounter with an **Inquisitorial Cinder-Justiciar** and two **Grief-Sworn Sentinels** within the flooded undercroft of a desecrated Eldorian Baptistery.
* **Active Weapon Morphology:** **Tier 3 (*Sundered Sovereign*)** — All 4 Quillon sockets unlocked (*Vom Tag, Pflug, Ochs, Mordhau*); central fuller pulsing pale cyan.
* **Baseline State (Pre-Combat):**
  * *Canonical Persistent State:* $R = 0.65, C = 0.15, D = 0.10, \text{Isolation} = 0.10, \text{GarrettTrust} = 0.70, \text{SerafinaTrust} = 0.70$ (Attuned Baseline).
  * *Derived Somatic State:* $\Phi_{\text{internal}} = 0.14, \Psi_{\text{relational}} = 0.72, H = 0.19, \text{IsolationPressure} = 0.22$.

---

### Beat 1: The Attuned Vanguard (Disciplined Martial Competence)

```
┌─────────────────────────────────────────────────────────────────────────────────────────────┐
│ Posture: Pflug (Low Lunge) ──► Stance Shift ──► [0.15s Flow Glint] ──► Vom Tag (High Cleave)│
│ State: Attuned (0.70)      ──► Spacing: 150uu   ──► DualSense: 30/255 Crisp Spring Tension  │
└─────────────────────────────────────────────────────────────────────────────────────────────┘
```

#### Narrative & Choreographic Execution:
Kaelen advances across the flooded flagstones of the baptistery in a disciplined **Pflug (Plow Guard)**, *Oathbringer's* five-foot blade extended like a spear leveled at an advancing Grief-Sworn Sentinel. The fuller glows a clear **Gale Cyan** (`0.20, 0.85, 0.95`).
* Kaelen delivers a clean, low-angle thrust that punctures the sentinel’s guard.
* On the **115 BPM Quartz audio downbeat**, the player inputs a stance shift into **Vom Tag (Roof Guard)**.
* An optical lens flare (**0.15s Flow Glint**) flashes across the cutting edge. The player presses Attack during the glint: Kaelen smoothly levers his body weight over his right shoulder, shifting the fuller to **Molten Ember Orange** (`0.95, 0.35, 0.05`) and shattering the sentinel's wooden shield with pure gravitational momentum.

#### Expression Across Subsystems:
* **Spatial AI Buffer:** Garrett and Serafina hold a disciplined **$150\text{uu}$ formation**. Garrett covers the right blind spot; Serafina maintains an active line-of-sight tether.
* **DualSense Telemetry:** The L2 Guard trigger exhibits crisp, baseline resistance ($30/255$); controller audio mix is quiet and balanced.
* **Internal Dialogue:** Kaelen’s thoughts are cold, methodical Order training: *"Point on line. Weight on the back heel. Hold the center."*

---

### Beat 2: The Tactical Disruption & The Martyrdom Trap

```
[ Inquisitorial Cinder-Justiciar Breaches Nave with Consecrated Poleaxe ]
                               │
                               ▼
        [ Kaelen Reverts to Solo Protective Fatalism ]
        • Breaks party formation to absorb consecrated fire alone
        • UAshenSoulPublisher: ΔD = +0.15, ΔC = +0.10, ΔIsolation = +0.20, ΔResonance = -0.36
                               │
                               ▼
        [ Derived Somatic Shift: Φ = 0.52, H = 0.65, TrioResonance = 0.34 (Discordant) ]
```

#### Narrative & Choreographic Execution:
The **Inquisitorial Cinder-Justiciar** breaches the baptismal archway, swinging a massive poleaxe that sweeps a line of white consecrated fire across the flooded floor, threatening to ignite the suspended timber scaffolding above Serafina.
* Defaulting to his core psychological pathology—**Protective Fatalism (The Glass Shield Protocol)**—Kaelen shouts: *"Fall back! I have the center!"*
* He breaks formation, surging forward alone into the consecrated pyre. He chains three heavy solo strikes against the Justiciar’s armor, refusing to yield ground or wait for Garrett’s frost snares.

#### Expression Across Subsystems:
* **Spatial AI Buffer:** Alarmed by the wild fire and Kaelen’s erratic aggression, Garrett and Serafina retreat to a defensive **$650\text{uu}$ buffer**.
* **Quartz Audio & Stem 02:** Battlefield spatialization ducks by **$-14\text{dB}$**. Ambient sound is replaced by high-frequency ringing and the scraping dissonance of **Stem 02 (Eldrin's parasite whisper)** rasping through the controller speaker: *"...They are too fragile, Kaelen... Put your weight into the steel... Let it bite..."*
* **Shader Seam Creep (`MPC_Oathbringer`):** The fuller’s embers turn dark; pulsing, hyper-saturated crimson vein tendrils crawl out of the crossguard and latch across Kaelen's gauntlets.

---

### Beat 3: The Loss of Agency (Predatory Momentum Takes the Reins)

```
┌─────────────────────────────────────────────────────────────────────────────────────────────┐
│                            PREDATORY MOMENTUM ACTIVATION (H = 0.65)                         │
├──────────────────────────────────────┬──────────────────────────────────────────────────────┤
│ Kinematic Expression                 │ Somatosensory & Spatial Cost                         │
├──────────────────────────────────────┼──────────────────────────────────────────────────────┤
│ • RootMotion Skew-Warp (+120uu)      │ Kaelen lunges uncontrollably into melee              │
│ • Recovery Frame Lock (+0.35s)       │ Over-swings bury blade tip into masonry              │
│ • Soot Tunnel Vision Post-Process    │ Screen edges blacken; companion tells obscured       │
│ • Flow Glint Locked Out              │ Companions at 650uu cannot bridge the gap            │
└──────────────────────────────────────┴──────────────────────────────────────────────────────┘
```

#### Narrative & Choreographic Execution:
The player inputs a horizontal slash in **Mordhau**, but Kaelen does not execute a measured strike:
* **The Predatory Lunge:** `URootMotionModifier_SkewWarp` seizes Kaelen’s skeleton, forcibly pulling him **$+120\text{uu}$ forward** directly into the Justiciar's bleeding chest. The player feels the disturbing sensation that the sword is dragging Kaelen's feet across the stone.
* **The Over-Swing:** The strike violently cleaves through the boss's side, but the unmanaged kinetic inertia over-torques Kaelen’s center of gravity. **Recovery frames expand by $+0.35\text{s}$** as Kaelen stumbles forward, burying *Oathbringer's* squared tip into the submerged floorstones.
* **The Soot Tunnel:** Dark, churning soot-smoke shaders (`MPC_PostProcess_SootVignette`) constrict the screen perimeter, completely obscuring peripheral threats.
* **Flow Glint Failure:** The player attempts a stance transition, but the optical flare flashes and instantly dies—Garrett and Serafina are $650\text{uu}$ away, unable to participate in team maneuvers.

#### Companion Appraisal (Relational Separation, Not Rejection):
* **Garrett’s Internal Model:** $\text{InterpersonalTrust} = 0.85$ (High), $\text{SomaticDread} = 0.72$ (Severe), $\text{TacticalConfidence} = 0.35$ (Degraded).
* **Garrett's AI Behavior:** He stays at $650\text{uu}$ not because he has stopped loving Kaelen, but out of tactical self-regulation: *"I can't step into his blind spot while that broadsword is flailing wild."*

---

### Beat 4: The Crisis Point & The Martial Fulcrum (Calculated Deference)

```
[ Justiciar Winds Up Lethal Execution Cleave on Trapped Garrett ]
                               │
                               ▼
     [ Player Inputs: L2 Guard + R-Stick Flick Left toward Garrett ]
                               │
            ┌──────────────────┴──────────────────┐
            ▼                                     ▼
 [ Dynamic Camera Framing ]            [ GA_CalculatedDeference_Bind ]
 • SpringArm pulls back +150uu         • Kaelen roots in Low Mordhau / Ochs Bind
 • FOV expands 85° ──► 95°             • Absorbs 80% Poise Strain
 • Action centered in 3-actor frame    • 0.60s Offensive Lockout Committed
```

#### Narrative & Choreographic Execution:
The Justiciar capitalizes on Kaelen’s over-extension, pivoting to unleash a lethal, unblockable overhead execution stroke aimed directly at Garrett, who is cornered against a collapsed baptismal font. Garrett's voice cuts through the **DualSense controller speaker**: *"Brother. Now."*
* Realizing brute solo attacks cannot save his brother, the player **rejects the panic of the Shadow**.
* The player executes the dedicated input: **Holds L2 (Guard) and flicks the Right-Stick left toward Garrett’s position**.

#### Camera & Kinetic Intercept:
* **Camera Frustum (`UAshenCameraModifier_DeferenceFraming`):** The camera smoothly extends its SpringArm by **$+150\text{uu}$** and expands FOV to **$95^\circ$**, pulling back to capture Kaelen, Garrett, and the Justiciar in a single composition.
* **The Bind:** Kaelen dashes into the trajectory and drops into a rooted **Low Mordhau / Ochs Bind**, planting his steel gauntlets and left pauldron beneath the Justiciar’s poleaxe haft, catching the crushing blow on *Oathbringer's* crossguard.
* **The Somatic Cost:** Kaelen takes **zero direct health damage**, but his stamina drops by **$-40$** and his poise bar takes **$80\%$ strain**. His offensive inputs are **locked for $0.60\text{s}$**—he has surrendered his agency entirely to create Garrett's opening.
* **DualSense Haptics:** The L2 trigger **locks rigidly to $245/255$**, forcing the player's finger to physically support the immovable weight of the enemy's descending weapon.

---

### Beat 5: Asymmetric Companion Payoff & Thermal Cleansing

```
[ Kaelen Holds the Fulcrum (0.60s Lockout) ]
                     │
     ┌───────────────┴───────────────┐
     ▼                               ▼
[ GA_Garrett_VaultFlank ]       [ GA_Serafina_ConduitBurst ]
• Skew-Warp Vault (1100uu/s)    • Stave strikes fuller grounding socket
• Twin-Dagger Tendon Sever      • MPC_ThermalSlag = 1.0 (4.0s)
• 100% Critical Stagger         • Soot shaders instantly incinerated
                     │
                     ▼
  [ DUALSENSE L2 TENSION DROPS TO 0/255 (TACTILE RELIEF) ]
```

#### Narrative & Choreographic Execution:
1. **Garrett’s Tendon Sever (`GA_Garrett_VaultFlank`):** Using `URootMotionModifier_SkewWarp` targeting `Socket_PauldronVault`, Garrett covers the $650\text{uu}$ distance in $0.45\text{s}$ ($1100\text{uu/s}$). He vaults directly off Kaelen's braced pauldron, clearing the locked poleaxe, and drives twin daggers into the Justiciar's rear cervical armor seams, triggering a **100% Critical Stagger**.
2. **Serafina’s Thermal Cleansing (`GA_Serafina_ConduitBurst`):** Serafina drives the ferrule of her catalyst stave onto *Oathbringer’s* exposed fuller grounding socket (`Socket_FullerGrounding`).
   * *Oathbringer* grounds her raw *Inner Flame*, channeling a concentrated White Flame lance through the steel into the boss's sternum.
   * `MPC_Oathbringer.ThermalSlag` sets to **$1.0$**. The blade glows incandescent white-hot, instantly burning off dark soot shaders and calcified red veins.

#### Somatosensory Payoff:
* **Haptics:** The L2 trigger tension **instantly collapses from $245 \to 0/255$**, delivering a sharp mechanical snap of physical relief.
* **Audio:** The rusted grinding resolves into an **$850\text{Hz}$ clean harmonic chime**. **Stem 02 (Eldrin's whisper) is ducked by $-24\text{dB}$** into dead silence.
* **Spatial AI:** The companion buffer **snaps from $650\text{uu}$ back to $150\text{uu}$**.

---

### Beat 6: The Climax — Relational Hybrid Finisher (Flow Glint Resolution)

```
[ Spatial Buffer Restored: 150uu ] ──► [ Quantized 115 BPM Downbeat ]
                                              │
                                              ▼
                             [ 0.15s Flow Glint Optical Flare ]
                                              │
                     ┌────────────────────────┴────────────────────────┐
                     ▼ (Player Inputs Attack: Vom Tag + Pflug)         ▼
      [ CATACLYSM VORTEX EXECUTED ]                       [ FSoulStateVector Commit ]
      • Vacuum pulls remaining minions into drop zone     • ParasitePressure: Resolves to 0.28 (Contained)
      • Downward Cleave detonates thermal shockwave       • IntegrationDebt:  -0.15
      • Boss & minions disintegrated into gray ash        • TrioResonance:    Reaches 0.95 (Synchronized)
```

#### Narrative & Choreographic Execution:
With the Justiciar staggered and the party unified within $150\text{uu}$, Kaelen pivots from his low bind into **Vom Tag** on the Quartz 115 BPM downbeat.
* The **0.15s Flow Glint** flares across the superheated, white-hot edge.
* Because the Trio is in tight spatial proximity ($\le 200\text{uu}$), the **Relational Hybrid Finisher (*Cataclysm Vortex*)** is fully accessible.
* The player presses Attack during the glint:
  * Serafina's light ward collapses inward, creating an $800\text{uu}$ gravitational vacuum that pulls the staggered Justiciar and surrounding Grief-Sworn into a tight cluster.
  * Garrett severs the primary counter-balance chains overhead, dropping a suspended iron chandelier onto the group.
  * Kaelen brings *Oathbringer* down in a seismic, two-handed vertical smite. The impact detonates the thermal slag in the fuller, releasing a blinding shockwave that shatters the Justiciar's armor and disintegrates the minions into harmless ash.

---

### Beat 7: Aftermath Synthesis & Living Journal Inscription (`UMB-UI-004`)

```
┌─────────────────────────────────────────────────────────────────────────────────────────────┐
│                            LIVING JOURNAL POST-COMBAT COMMIT                                │
├─────────────────────────────────────────────────────────────────────────────────────────────┤
│  [Kaelen's Hand - Crisp, unhurried black ink]:                                              │
│  "The iron wanted to drag me into the dark. I stopped swinging. I locked into Ochs and      │
│   waited. The steel held. Garrett took the flank; Serafina cleared the soot."               │
│                                                                                             │
│  [Garrett's Margin - Technical charcoal diagram of the pauldron vault]:                     │
│  "Clean fulcrum, brother. Keep your pauldron tucked like that on the intercept and we       │
│   won't have to keep patching your breastplate."                                            │
│                                                                                             │
│  [Serafina's Margin - Pressed silver-ash leaf sealed with dried resin]:                     │
│  "The White Flame didn't burn you because you didn't carry it alone. The line held."        │
└─────────────────────────────────────────────────────────────────────────────────────────────┘
```

---

## 📊 SECTION III: Systemic State Transformation Matrix

| Runtime Parameter / Vector | Prologue (Beat 1) | High Hunger Crisis (Beat 3) | Deference & Payoff (Beat 5) | Encounter Climax (Beat 6) |
| :--- | :--- | :--- | :--- | :--- |
| **Parasite Pressure ($H$)** | $0.19$ (Dormant) | **$0.65$ (Predatory Over-Swing)** | $0.30$ (Stabilizing) | **$0.28$ (CONTAINED, NOT PURGED)** |
| **Internal Friction ($\Phi$)** | $0.14$ (Fluid) | **$0.52$ (Kinetic Drag)** | $0.22$ (Calming) | **$0.15$ (Harmonized)** |
| **Relational Flow ($\Psi$)** | $0.72$ (Attuned) | **$0.24$ (Alienated)** | $0.65$ (Rebuilding) | **$0.92$ (Synchronized)** |
| **Isolation Pressure ($I$)** | $0.22$ (Connected) | **$0.60$ (Detached)** | $0.25$ (Reconnecting) | **$0.08$ (Unified)** |
| **Trio Resonance** | $0.70$ (Attuned) | **$0.34$ (Discordant)** | $0.65$ (Rebuilding) | **$0.95$ (Synchronized)** |
| **Companion Spacing** | $150\text{uu} - 200\text{uu}$ | **$650\text{uu}$ (Guarded Buffer)** | $150\text{uu}$ (Intercept Warp) | **$150\text{uu}$ (Tight Pocket)** |
| **DualSense L2 Tension** | $30/255$ (Standard) | **$220/255$ (Cardiac Drag)** | **$245 \to 0/255$ (Snap Relief)** | $0/255$ (Fluid Flow) |
| **Audio Master Mix** | Balanced (115 BPM) | Stem 02 Active / Ambience $-14\text{dB}$ | $850\text{Hz}$ Harmonic Chime | Stem 02 Silenced ($-24\text{dB}$) |
| **Flow Glint Status** | Active ($0.15\text{s}$ Window) | **LOCKED OUT ($650\text{uu}$ Gate)** | Re-arming | **EXECUTED (Cataclysm Vortex)** |

---

## 🧪 SECTION IV: C++ Automation Test Verification Mapping

This vertical slice is verified by our Tri-Partite QA Automation Suite [`Source/AshenOath/QA/AshenMasterConvergenceV2AutomationTest.cpp`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenMasterConvergenceV2AutomationTest.cpp):

1. **`AshenOath.Unit.SoulDerivationMath`:** Asserts 28-byte `FSoulStateVector` packing and non-saturating manifold derivations ($\sum \text{coefficients} = 1.00$).
2. **`AshenOath.Integration.CalculatedDeference`:** Simulates Beat 3 $\to$ Beat 4 $\to$ Beat 5:
   * Sets pre-state ($C=0.25, D=0.25, \text{Isolation}=0.30$).
   * Executes Calculated Deference on Garrett ($0.60\text{s}$ lockout).
   * Delivers companion strike, asserting $\Delta D = -0.15$, $\text{Trust} \uparrow$, and Parasite Pressure stabilizing at $0.28$ (Contained).
3. **`AshenOath.Contract.SingleSourceOfTruth`:** Reflection audit confirming `ParasitePressure` and `InternalFriction` do NOT exist as persistent struct fields.
