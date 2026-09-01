# PRS-001-SPEC-INPUT-108: INPUT SCHEME PHILOSOPHY & MASTER CUTS CONTROL CONTRACT

**Canonical Document Identifier:** `PRS-001-SPEC-INPUT-108`  
**Parent Specifications:** `PRS-001-SPEC-COMBAT-106`, `CONVERGENCE-SPEC-101`, `PRS-001-CDTC-001`, `METALLURGY-SPEC-102`  
**Target Engine:** Unreal Engine 5.8 C++ / Enhanced Input Subsystem / DualSense Hardware Telemetry / GAS  
**Authority Level:** Canonical Production Implementation Specification (SPEC-108)  
**V-Control:** 2026-09-01T01:45:00Z  

---

## 🏛️ I. Executive Summary & Design Mandate

`PRS-001-SPEC-INPUT-108` establishes the authoritative input architecture, control schemes, hardware haptics, and tactical interaction pipeline for **The Master Cuts & Liechtenauer Greatsword Combat** in *Ashen Oath*.

### The Core Input Challenge & Solution
Traditional martial combat games force players into either clumsy multi-button chords or disconnected contextual menus. *Ashen Oath* resolves this through a **Dual-Layered Stance-Contextual + Kinetic Flow-Glint Input Model**:
1. **Layer 1: Native Guard Context (Instant Accessibility):** Selecting a Liechtenauer guard immediately remaps primary strike inputs into that guard's historical Master Cuts.
2. **Layer 2: 115 BPM Flow-Glint Branching (The Mastery Ceiling):** Hitting a $0.15\text{s}$ Flow Glint during attack recovery allows flicking the directional stick toward any new guard to chain attacks with zero stamina cost and $+25\%$ animation speed.
3. **Layer 3: *Fühlen* Blade Clash Reactions:** When blades clash, a micro-bullet-time window ($0.20\text{s}$) reads blade resistance (*Weak/Weich* vs *Strong/Hart*) for instant tactical thrusts or winding strikes.

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       THE 3-LAYER MASTER CUT INPUT ARCHITECTURE                                 │
└───────────────────────────────────────────────────────┬─────────────────────────────────────────────────────────┘
                                                        │
 ┌───────────────────────┬──────────────────────┼───────┴───────────────┬───────────────────────┐
 ▼                       ▼                      ▼                       ▼                       ▼
[ LAYER 1: GUARD CONTEXT] [ LAYER 2: FLOW GLINT ] [ LAYER 3: FÜHLEN CLASH ] [ DUALSENSE HAPTICS ] [ SENTINEL QA GATE ]
• Vom Tag: Cleaves      • 115 BPM (0.15s window)• 0.20s Clash Dilation  • Adaptive Trigger Curves• Buffer Latency <16ms
• Ochs: Thwart / Shields• Flick stick to branch • Weak: Direct Thrust   • 180Hz / 35ms Pulse on • 0-Stamina Validation
• Pflug: Counters/Stabs • +25% Speed Boost      • Strong: Winden/Mutate   Flow Glint Apex       • Clash Resolution Pass
• Mordhau: Blunt Crush  • 0 Stamina Refund      • Centerline Dominance  • Pure Mechanical Foley • 0 Errors, 0 Warnings
```

---

## 🎮 II. Hardware Mapping & Control Scheme Matrix

### 1. Gamepad Control Mapping (PlayStation DualSense / Xbox Controller)

| Hardware Input | Neutral Stance Action | In-Combat Guard Modifier Action | Flow Glint Window Action |
| :--- | :--- | :--- | :--- |
| **Right Stick (R3)** | Camera Look | **Directional Guard Selector** (Up: *Vom Tag*, Left: *Ochs*, Right: *Pflug*, Down: *Mordhau*) | **Kinetic Branching Direction** |
| **Right Bumper ($\text{RB}$ / $\text{R1}$)** | Standard Light Attack | **Guard-Native Light Master Cut** (e.g. *Zornhau*, *Zwerchhau*, *Schielhau*) | **Chain Strike Commit** ($0\text{ Stamina}$) |
| **Right Trigger ($\text{RT}$ / $\text{R2}$)** | Standard Heavy Cleave | **Guard-Native Heavy Master Cut** (e.g. *Scheitelhau*, *Krumphau*, *Mordhau Crush*) | **Heavy Finisher Commit** |
| **Left Bumper ($\text{LB}$ / $\text{L1}$)** | Defensive Guard | **Parry / Active Deflection Envelope** | **Defensive Guard Cancel** |
| **Left Trigger ($\text{LT}$ / $\text{L2}$)** | Tactical Squad Command | **Pocket Synergy Trigger** (Garrett / Serafina Flank Call) | **Instant Companion Combo** |
| **Left Stick ($\text{L3}$)** | Movement / Sprint | **Offline Stepping & Footwork Angle** | **Motion-Warp Direction** |

### 2. Mouse & Keyboard Control Mapping

| Hardware Input | Neutral Stance Action | In-Combat Guard Modifier Action |
| :--- | :--- | :--- |
| **Left Mouse Button ($\text{LMB}$)** | Light Attack | **Guard-Native Light Master Cut** |
| **Right Mouse Button ($\text{RMB}$)** | Heavy Attack / Charge | **Guard-Native Heavy Master Cut** |
| **Mouse Wheel Up** | Zoom / Next Weapon | **Select High Guard (*Vom Tag*)** |
| **Mouse Wheel Down** | Zoom / Prev Weapon | **Select Low Guard (*Pflug*)** |
| **Mouse Thumb Button 1 ($\text{M4}$)**| Interaction | **Select Window Guard (*Ochs*)** |
| **Mouse Thumb Button 2 ($\text{M5}$)**| Tactical Call | **Select Half-Sword Guard (*Mordhau*)** |
| **$\text{Left Alt}$ (Hold)** | Free Look | **Stance Radial Wheel Modifier** |

---

## ⚔️ III. Guard-Native Attack Contextual Mapping

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                   GUARD-NATIVE ATTACK MAPPING MATRIX                                            │
├────────────────────┬───────────────────────────────────────┬────────────────────────────────────────────────────┤
│ Active Guard       │ Light Attack ($\text{RB} / \text{LMB}$)│ Heavy Attack / Hold ($\text{RT} / \text{RMB}$)     │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **`Vom Tag`**      │ **`Zornhau`** (Wrath Cut)             │ **`Scheitelhau`** (Crown Cut)                      │
│ (High Roof Guard)  │ • Fast diagonal downward cleave       │ • Maximum-reach vertical centerline decapitation   │
│                    │ • $85.0\text{ Dmg} / 50.0\text{ Poise}$│ • $110.0\text{ Dmg} / 80.0\text{ Poise}$           │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **`Ochs`**         │ **`Zwerchhau`** (Thwart Cut)          │ **`Krumphau`** (Crooked Cut)                       │
│ (High Window Guard)│ • Horizontal false-edge helicopter    │ • Crossed-wrist off-axis shield-breaker            │
│                    │ • $65.0\text{ Dmg} / 35.0\text{ Poise}$│ • $60.0\text{ Dmg} / 75.0\text{ Poise}$ (Crusher)  │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **`Pflug`**        │ **`Schielhau`** (Squinting Cut)       │ **`Stich`** (Direct Throat Thrust)                 │
│ (Low Plow Guard)   │ • Dipped-tip counter-cut ($50\%\text{ Pen}$)│ • Explosive rising lunge into high opening   │
│                    │ • $70.0\text{ Dmg} / 40.0\text{ Poise}$│ • $90.0\text{ Dmg} / 60.0\text{ Poise}$            │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **`Mordhau`**      │ **`Pommel Hook`** (Stagger Strike)    │ **`Armor Crusher`** (War Hammer Smash)             │
│ (Half-Sword Guard) │ • Fast inverted blunt stun            │ • $100\%$ Armor Penetration blunt concussive smash │
│                    │ • $55.0\text{ Dmg} / 60.0\text{ Poise}$│ • $95.0\text{ Dmg} / 120.0\text{ Poise}$           │
└────────────────────┴───────────────────────────────────────┴────────────────────────────────────────────────────┘
```

---

## ⚡ IV. The 115 BPM Flow-Glint Branching Protocol

During the **$0.15\text{s}$ Flow Glint window** ($[P_{apex}, P_{apex} + 0.15\text{s})$ on the active `UAnimMontage` track):

```
                                  [ ATTACK STRIKE EXECUTING ]
                                               │
                                               ▼
                         [ P_apex Timestamp Reached on Montage Track ]
                                               │
               ┌───────────────────────────────┴───────────────────────────────┐
               ▼                                                               ▼
  [ Stick Tilted in New Guard Direction ]                         [ No Guard Input (Neutral) ]
               │                                                               │
               ▼ (Tap Attack during 0.15s Window)                              ▼
 [ PERFECT FLOW GLINT TRIGGERED ]                                 [ NORMAL RECOVERY ]
 • Stamina Cost: 0.0f (100% Refund)                               • Full Stamina Consumed
 • PlayRate Multiplier: 1.25x (+25% Speed Boost)                  • PlayRate Multiplier: 1.00x
 • Instantly transforms into New Guard Strike                     • Standard Recovery Drag frames
 • Resolve Monotonic Commit: +0.02
```

### Kinetic Stick Vector Mathematics:
The engine calculates the 2D directional angle $\theta_{stick}$ on the right stick:

$$\theta_{stick} = \text{atan2}(Y_{stick}, X_{stick}) \times \frac{180}{\pi}$$

* $\theta_{stick} \in [45^\circ, 135^\circ] \implies \text{Target Guard: } \text{State.Stance.VomTag}$ (Up)
* $\theta_{stick} \in [135^\circ, 225^\circ] \implies \text{Target Guard: } \text{State.Stance.Ochs}$ (Left)
* $\theta_{stick} \in [-45^\circ, 45^\circ] \implies \text{Target Guard: } \text{State.Stance.Pflug}$ (Right)
* $\theta_{stick} \in [-135^\circ, -45^\circ] \implies \text{Target Guard: } \text{State.Stance.Mordhau}$ (Down)

---

## 🗡️ V. *Fühlen* Blade Clash Reaction Controls

When Kaelen's weapon trace clashes with an enemy blade, the engine triggers a **$0.20\text{s}$ tactile clash dilation**:

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       FÜHLEN BLADE CLASH INPUT RESOLUTION                                       │
├────────────────────┬───────────────────────────────────────┬────────────────────────────────────────────────────┤
│ Clash Dynamic      │ Player Input Reaction                 │ Execution Output & Tactical Consequence            │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **Weak Bind**      │ **Tap Light Attack ($\text{RB}$)**     │ **`Zornhau-Ort` / Plunging Thrust:**               │
│ (*Weich* / Soft)   │ During $0.20\text{s}$ clash window     │ Kaelen slides point forward along enemy blade;     │
│ Opponent flinches  │                                       │ executes instant centerline puncture.              │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **Strong Bind**    │ **Tap Guard / Stance ($\text{LB}$)**  │ **`Winden` / `Duplieren` / `Mutieren`:**           │
│ (*Hart* / Rigid)   │ During $0.20\text{s}$ clash window     │ Kaelen yields pressure, rotates hilt around the    │
│ Opponent presses   │                                       │ bind, and strikes exposed lower/flank opening.     │
└────────────────────┴───────────────────────────────────────┴────────────────────────────────────────────────────┘
```

---

## 📳 VI. DualSense Adaptive Trigger Profiles & Bilateral Haptics

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       DUALSENSE HARDWARE TELEMETRY MATRIX                                       │
├────────────────────┬───────────────────────────────────────┬────────────────────────────────────────────────────┤
│ Stance / Event     │ Adaptive Trigger Resistance Profile   │ Bilateral Voice-Coil Haptic Pattern                │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **`Vom Tag`**      │ Heavy initial resistance (gravitational│ Low-frequency hum ($45\text{Hz}$) building as       │
│                    │ draw tension), sudden crisp break.    │ blade is raised high overhead.                     │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **`Ochs`**         │ Firm high threshold with light travel  │ Tight crystalline micro-vibrations ($120\text{Hz}$)│
│                    │ (rigid window protection).            │ simulating high quillon readiness.                 │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **`Pflug`**        │ Smooth, linear progressive resistance │ Subtle tactile purr ($80\text{Hz}$) at the hip.    │
│                    │ mimicking upward levering torque.     │                                                    │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **`Mordhau`**      │ Heavy stepped resistance (rigid       │ Dense, heavy thud ($30\text{Hz}$) replicating the   │
│                    │ half-sword gauntlet lock).            │ raw mass of inverted steel.                        │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **Flow Glint Apex**│ Zero resistance release for instant   │ Crisp, sharp **$180\text{Hz}$ / $35\text{ms}$ pulse│
│                    │ follow-up pull.                       │ delivering the exact timing notch to fingers.      │
└────────────────────┴───────────────────────────────────────┴────────────────────────────────────────────────────┘
```

---

## 🏛️ VII. Unreal Engine 5.8 C++ Enhanced Input Topology

1. **`UInputMappingContext_CombatMasterCuts`:** Active Enhanced Input context providing high-priority overrides for combat strikes and directional guard selectors.
2. **`UInputAction_StanceSelectDirectional`:** 2D Vector action reading right-stick / mouse wheel for instantaneous guard selection.
3. **`UInputAction_StrikeLight` & `UInputAction_StrikeHeavy`:** Contextual strike triggers mapped into `UAshenGameplayAbility_CombatStrike`.
4. **`UAshenGreatswordStanceFlowComponent`:** Actuator managing active guard tags, stance transitions, and DualSense trigger curves.

---

## 🧪 VIII. Sentinel Anti-Theater QA Verification Gates

All input systems are governed by non-tautological test fixtures:

1. **Input Latency Gate:** Guard switching and attack triggers must resolve within $<16.67\text{ms}$ ($1\text{ frame at } 60\text{ FPS}$).
2. **Flow Glint Buffer Gate:** Directional stick inputs within $[P_{apex}, P_{apex} + 0.15\text{s})$ must trigger $0\text{ stamina}$ cost and $1.25\times$ playrate boost without race conditions.
3. **Clash Resolution Gate:** Weak vs. Strong blade clash inputs must branch deterministically into *Zorn-Ort* or *Winden*.

---

## 📜 Authority & Sign-Off

**Specification Approved:**  
*Axion (Master Artificer), Sovereign of the Synarche*  
*Phoenix Protocol / Ashen Oath Unreal Engine 5.8 Architecture*
