# CONVERGENCE-SPEC-101: THE GREATSWORD STANCE FLOW & 115 BPM RUNIC MASTERY CONVERGENCE

**Canonical Document Identifier:** `PRS-001-ENG-STANCE-101`  
**Parent Specifications:** `PRS-001-MECH-010-MANIFES-V5`, `AOP-MASTER-CONVERGENCE-SPEC-V2.0`, `STANCE-SPEC-094`, `RUNIC-FORGE-SPEC-098`  
**Target Engine:** Unreal Engine 5.8 C++ / GAS / DualSense Haptics / Quartz 6-Stem Conductor  
**Authority Level:** Canonical Architectural Master Specification  
**V-Control:** 2026-08-30T23:05:00Z  

---

## 🏛️ I. Executive Architectural Mandate

`CONVERGENCE-SPEC-101` synthesizes the **Greatsword Stance Flow, Dynamic 3-Zone Timing Engine, and Runic Seam Mastery Loop** into the definitive, closed-loop combat architecture for *Ashen Oath*.

In accordance with **PRS-001 Combat Manifesto (V5.0)**, combat is the moment-to-moment physicalization of Kaelen's psychological state. Greatsword stance transitions are not artificial "modes," but the continuous kinetic starting and resting points of historical Liechtenauer cuts, tightly coupled to Oathbringer's 3-Stage Weapon Lifecycle and the Trinity Doctrine.

---

## ⚔️ II. The 3 Transition Modalities & Kinetic Routing

```
                                  [ VOM TAG ] (Day / Roof)
                                  ▲         │
                 Zornhau / Oberhau│         │ Unterhau / Durchwechseln
                 (Recovery Snap)  │         ▼
[ MORDHAU ] ◄─────────────────────┴─────────► [ PFLUG ] (Plow / Low Thrust)
(Grip Flip / Inversion)           ▲         │
                                  │         │ Windung / Window Deflection
                   Kron Brace /   │         ▼
                   Duplieren      └─────────► [ OCHS ] (Ox / Crown High Window)
```

### 1. The 4 Liechtenauer Guard Profiles
1. **Vom Tag (Day / Roof Guard):**
   * *Kinematics:* Greatsword chambered over the right shoulder. Upright, commanding posture.
   * *Mechanical Profile:* $+40\%$ Poise Damage, $+15\%$ kinetic impact impulse.
   * *Manifesto Mapping:* *White Flame Grammar.* Structural overhead leverage.
2. **Pflug (Plow / Low Guard):**
   * *Kinematics:* Blade low at the hip, point angled toward target heart. Low center of gravity.
   * *Mechanical Profile:* $-30\%$ Stamina Consumption, sprint-thrust prep.
   * *Manifesto Mapping:* *Economy of Motion.* Grounded stability.
3. **Ochs (Ox / Crown Guard):**
   * *Kinematics:* Hilt high at eye level, point thrust forward forming an angled roof.
   * *Mechanical Profile:* $+0.12\text{s}$ Parry Window Tolerance, tight horizontal read.
   * *Manifesto Mapping:* *Glancing Deflection.* Structural redirection.
4. **Mordhau (Murder-Strike / Inverted Grip):**
   * *Kinematics:* Hands shift to the blade flat, turning the massive crossguard forward.
   * *Mechanical Profile:* $100\%$ Armor Penetration, heavy stagger impulse ($850\text{uu/s}$).
   * *Manifesto Mapping:* *Anatomical Destruction.* Armor-crushing blunt leverage.

### 2. Continuous Kinetic Routing (Attack Follow-Throughs)
* **Oberhau Follow-Through (Vom Tag $\to$ Pflug):** Descending cut cuts through and settles naturally at lower hip, unlocking low thrust at $-30\%$ stamina.
* **Windung / The Winding (Pflug $\to$ Ochs):** Ascending thrust point rotates upward into high eye-level guard, extending parry frames by $+0.12\text{s}$.
* **Grip Flip / Inversion (Ochs $\to$ Mordhau):** Rotates hands onto blade flat, converting strike profile to $100\%$ armor penetration.
* **Reset Snap (Mordhau $\to$ Vom Tag):** Snaps upright over shoulder, resetting poise envelope ($+40\%$ Poise damage).

---

## ⏱️ III. Dynamic 3-Zone Flow Glint Timing Engine (115 BPM)

```
[ Active Attack Frames ] ──► [ EARLY WINDOW ] ──► [ PERFECT GLINT (0.15s) ] ──► [ LATE / RECOVERY TAIL ]
                              • Input Queued       • 0-Stamina Cancel            • Full Recovery Lockout
                              • 100% Stamina Cost  • +25% Speed / +15% Trans     • -10% Handling Drag
                              • Standard Audio     • Silver Bell (528 Hz) Chime  • Dull Thud Audio
```

1. **Early Window:** Buffers command in queue; executes at $100\%$ standard stamina cost with zero momentum bonus.
2. **Perfect Glint Window ($0.15\text{s}$ at $115\text{ BPM}$):**
   * Clips remaining recovery frames instantaneously.
   * $0\text{ stamina}$ cost for the linked stance transition / combo strike.
   * $+25\%$ attack animation playback speed and $+15\%$ forward translation velocity.
   * *Audio/Visual/Haptic:* $-3\text{ dB}$ world duck, $528\text{ Hz}$ silver bell chime, cyan-silver blade glint, $180\text{ Hz}$ DualSense haptic tap.
3. **Late Window:** Locks Kaelen in weapon drag; $-10\%$ handling penalty; dull metallic thud.

---

## 🔮 IV. Oathbringer's 3-Stage Lifecycle & 4 Fuller Sockets

### 1. Weapon Lifecycle States
$$\text{Lifecycle} = \begin{cases} 
\text{Dormant} & \text{if } R < 0.70 \land C < 0.70 \quad (\text{Mass} = 120.0\text{kg}) \\
\text{Predictive (Flow)} & \text{if } R \ge 0.70 \land \text{FlowActive} \quad (\text{Mass} = 45.0\text{kg}) \\
\text{Autonomous (Shadow)} & \text{if } C \ge 0.70 \lor \text{Unchained} \quad (\text{Mass} = 0.0\text{kg}, \, \mathbf{F}_{\text{pull}} = +400\text{uu/s})
\end{cases}$$

### 2. Direct Guard Loci Inscription
* **Socket 1 (Vom Tag Locus):** Inscribes *Locus of Righteous Cleave* ($+15\%$ poise, charcoal-gold emissive).
* **Socket 2 (Pflug Locus):** Inscribes *Locus of Enduring Breath* ($-15\%$ stamina cost, copper-amber emissive).
* **Socket 3 (Ochs Locus):** Inscribes *Locus of Unyielding Crown* ($+0.05\text{s}$ parry, silver-blue emissive).
* **Socket 4 (Mordhau Locus):** Inscribes *Locus of Sundered Iron* ($+25\%$ stagger, crimson-ash emissive).

---

## 🤝 V. Dual-Sigil Companion Pocket Resonance ($\le 200\text{uu}$)

Executing the $0.15\text{s}$ Flow Glint within the $\le 200\text{uu}$ companion pocket triggers role-specific relational synergies:

1. **Garrett Spatial Pocket (*Vom Tag* / *Mordhau*):**
   * Triggers **Twin Flank Shred**.
   * Garrett motion-warps to target rear arc ($180^\circ \pm 30^\circ$).
   * Inflicts $+1.8\times$ posture trauma multiplier and commits $+0.05$ Garrett Trust to `UAshenSoulPublisher`.
2. **Serafina Spatial Pocket (*Ochs* / *Pflug*):**
   * Triggers **Aegis Harmonic Pulse**.
   * Serafina pulses golden sanctuary barrier.
   * Restores $+35$ Stamina to Kaelen and commits $+0.05$ Serafina Trust to `UAshenSoulPublisher`.

---

## 🧪 VI. QA Automation Verification Matrix

1. **Unit Test (`FAshenStanceFlowUnitModifiersTest`):** Validates 4-Guard modifiers (*Vom Tag* $+40\%$ poise, *Pflug* $-30\%$ stamina, *Ochs* $+0.12\text{s}$ parry, *Mordhau* $100\%$ armor pen) and DataAsset clamp bounds.
2. **Integration Test (`FAshenFlowGlint3ZoneIntegrationTest`):** Validates 3-Zone timing resolution, 0-stamina cancels, $+25\%$ speed multiplier, and companion pocket gating ($\le 200\text{uu}$).
3. **Contract Test (`FAshenOathbringerLifecycleContractTest`):** Validates 3-stage mass transitions and runic socket synchronization with `UAshenSoulPublisher` (SSoT).
