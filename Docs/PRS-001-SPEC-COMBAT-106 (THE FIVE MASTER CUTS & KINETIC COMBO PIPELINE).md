# PRS-001-SPEC-COMBAT-106: THE FIVE MASTER CUTS & KINETIC COMBO PIPELINE

**Canonical Document Identifier:** `PRS-001-SPEC-COMBAT-106`  
**Parent Specifications:** `PRS-001-CDTC-001`, `PRS-001-SPEC-COMBAT-104-HARDENED`, `CONVERGENCE-SPEC-101`, `METALLURGY-SPEC-102`  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Quartz / Motion Warping  
**Authority Level:** Canonical Production Implementation Specification (SPEC-106)  
**V-Control:** 2026-09-01T00:15:00Z  

---

## 🏛️ I. Executive Architectural Summary

`PRS-001-SPEC-COMBAT-106` codifies the definitive gameplay and engineering specification for **The Five Master Cuts (*Die Fünf Meisterhaue*) & Kinetic Greatsword Combo Pipeline** in *Ashen Oath*.

Rooted in authentic 14th-century German longsword treatises (*Johannes Liechtenauer Fechtbuch*), every combat ability in *Ashen Oath* operates as an **intrinsically defensive and offensive action**. Strikes are not isolated animations; they are non-modal biomechanical transitions through the four historical guards (*Vom Tag*, *Pflug*, *Ochs*, *Mordhau*), synchronized to an invariant **$115\text{ BPM}$ ($0.15\text{s}$) Flow Glint timing window** and evaluated via **CDTC-002** hit-stop-immune montage position tracking.

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                   THE 5 MASTER CUTS & KINETIC COMBO PIPELINE                                    │
└───────────────────────────────────────────────────────┬─────────────────────────────────────────────────────────┘
                                                        │
 ┌───────────────────────┬──────────────────────┼───────┴───────────────┬───────────────────────┐
 ▼                       ▼                      ▼                       ▼                       ▼
[ 1. VOM TAG (HIGH)   ] [ 2. OCHS (WINDOW)    ] [ 3. PFLUG (PLOW)     ] [ 4. MORDHAU (REVERSE)] [ 5. POCKET SYNERGY   ]
• Zornhau (Wrath Cleave)• Krumphau (Crooked)   • Schielhau (Squinting) • Half-Sword Pommel     • Garrett: Twin Flank  │
• Scheitelhau (Crown)   • Zwerchhau (Thwart)   • Stich (Direct Thrust) • 100% Armor Pen Blunt  • Serafina: Aegis Smite│
```

---

## ⚔️ II. The Five Master Cuts & Mordhau Strike Matrix

### 1. The Core Strike Specifications

| Cut / Ability Name | Native Guard | Biomechanical Execution | Base Damage ($D$) | Poise Damage ($P$) | Armor Pen ($\alpha$) | Next Guard Tag |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **`Zornhau`**<br>(*Wrath Hew*) | `State.Stance.VomTag` | Heavy diagonal descending cleave stepping forward. If met with an attack, it binds and displaces. | $85.0$ | $50.0$ | $25\%$ ($0.25$) | `State.Stance.Pflug` |
| **`Krumphau`**<br>(*Crooked Hew*) | `State.Stance.Ochs` | Crossed-wrist off-axis strike stepping laterally across the line of attack. Crushes shields. | $60.0$ | $75.0$ | $35\%$ ($0.35$) | `State.Stance.VomTag` |
| **`Zwerchhau`**<br>(*Thwart Hew*) | `State.Stance.Ochs` | Horizontal false-edge helicopter strike creating an iron roof over the head. Chains infinitely. | $65.0$ | $35.0$ | $30\%$ ($0.30$) | `State.Stance.Ochs` |
| **`Schielhau`**<br>(*Squinting Hew*) | `State.Stance.Pflug` | Dipped-point false-edge downward cut that shoots past incoming thrusts directly into neck/clavicle. | $70.0$ | $40.0$ | $50\%$ ($0.50$) | `State.Stance.Ochs` |
| **`Scheitelhau`**<br>(*Crown Hew*) | `State.Stance.VomTag` | Pure vertical descending stroke aimed at the apex of the skull. Longest physical reach. | $110.0$ | $80.0$ | $40\%$ ($0.40$) | `State.Stance.Pflug` |
| **`Mordhau`**<br>(*Pommel Strike*) | `State.Stance.Mordhau`| Inverted weapon grip striking with heavy crossguard/pommel. Pure blunt concussive trauma. | $95.0$ | $120.0$ | $100\%$ ($1.00$)| `State.Stance.VomTag` |

---

## 📐 III. Mathematical Damage, Poise & Flow Glint Formulations

### 1. Effective Damage Equation with Metallurgy & Armor Penetration

$$D_{effective} = \left[ D_{base} \times \left(1.0 + 0.50 \times R\right) \times M_{tier} \right] \times \left( 1.0 - \text{Armor}_{target} \times (1.0 - \alpha) \right)$$

Where:
* $R \in [0.0, 1.0]$: Kaelen's current SSoT **Resolve** value.
* $M_{tier}$: Metallurgical Tier damage scalar ($1.00\times$ Tier 1 $\to 1.35\times$ Tier 5).
* $\text{Armor}_{target} \in [0.0, 0.90]$: Target's physical armor reduction.
* $\alpha \in [0.0, 1.0]$: Strike Armor Penetration Fraction ($1.0$ for Mordhau completely negates armor).

### 2. The 115 BPM Flow Glint Traversal & Stamina Cancellation

During attack recovery, the engine evaluates the half-open interval $[P_{apex}, P_{apex} + 0.15\text{s})$ on the active `UAnimMontage` track:

$$P_{montage}(t) = P_{montage}(t - \Delta t) + (\Delta t_{effective} \times \text{MontagePlayRate})$$

$$\text{EffectiveStaminaCost} = \begin{cases} 0.0 & \text{if } P_{apex} \le P_{montage} < P_{apex} + 0.15\text{s} \text{ (Perfect)} \\ \text{StaminaCost} & \text{if Early / Late / Missed} \end{cases}$$

$$\text{MontagePlayRate}_{next} = \begin{cases} 1.25\times & \text{if Perfect (Kinetic Momentum Boost)} \\ 1.00\times & \text{if Normal} \end{cases}$$

---

## 🔄 IV. Non-Modal Guard Transition State Graph

```
                                  ┌───────────────────────────────┐
                                  │   VOM TAG (HIGH ROOF GUARD)   │
                                  └───────────────┬───────────────┘
                                                  │
                         ┌────────────────────────┴────────────────────────┐
                         ▼                                                 ▼
                  [ 1. ZORNHAU ]                                    [ 5. SCHEITELHAU ]
                  Diagonal Cleave                                   Vertical Decapitation
                         │                                                 │
                         ▼ (Perfect Glint: 0 Stamina)                      ▼
            ┌─────────────────────────┐                       ┌─────────────────────────┐
            ▼                         ▼                       ▼                         ▼
    [ PFLUG (PLOW) ]           [ OCHS (WINDOW) ]       [ PFLUG (PLOW) ]          [ MORDHAU (REVERSE) ]
            │                         │                       │                         │
            ▼                         ▼                       ▼                         ▼
     [ 4. SCHIELHAU ]          [ 3. ZWERCHHAU ]        [ 4. SCHIELHAU ]          [ 6. MORDHAU CRUSH ]
     Squinting Counter         Thwart (Self-Loop)      Squinting Counter         100% Armor Pen Blunt
            │                         │                       │                         │
            └───────────┬─────────────┴───────────────────────┴─────────────────────────┘
                        ▼
            [ RESOLVE +0.02 Monotonic SSoT Commit ]
```

---

## 👥 V. Relational Pocket Resonance Synergies

When a Master Cut hits during a **Perfect Flow Glint** and a companion is positioned within the validated rear flank cone ($\le 200.0\text{uu}$, $\text{Dot} \ge \cos 45^\circ$, Line-of-Sight clear):

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       RELATIONAL POCKET SYNERGY MATRIX                                          │
├────────────────────┬───────────────┬──────────────────────────────────┬─────────────────────────────────────────┤
│ Trigger Strike     │ Companion     │ Pocket Synergy Action            │ Combat Effect                           │
├────────────────────┼───────────────┼──────────────────────────────────┼─────────────────────────────────────────┤
│ **`Zornhau`**      │ Garrett       │ **Twin Flank Shred**             │ Garrett motion-warps behind target;     │
│                    │ (Scout)       │                                  │ applies Bleed (-15 HP/s for 6.0s).      │
├────────────────────┼───────────────┼──────────────────────────────────┼─────────────────────────────────────────┤
│ **`Krumphau`**     │ Serafina      │ **Aegis Smite**                  │ Serafina unleashes concussive blast;    │
│                    │ (Battlemage)  │                                  │ target flung into terrain fracture.     │
├────────────────────┼───────────────┼──────────────────────────────────┼─────────────────────────────────────────┤
│ **`Mordhau`**      │ Garrett       │ **Armor Excision**               │ Garrett drives stiletto into exposed    │
│                    │ (Scout)       │                                  │ joint; guaranteed critical execution.   │
└────────────────────┴───────────────┴──────────────────────────────────┴─────────────────────────────────────────┘
```

---

## 🏛️ VI. Unreal Engine 5.8 C++ Architectural Implementation

### 1. Class Hierarchy

* **[`UAshenGameplayAbility_CombatStrike`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Combat/AshenGameplayAbility_CombatStrike.h):** Base abstract ability class handling montage position tasks, stamina cancellation, and guard tag mutations.
* **`UGA_AshenStrike_Zornhau`:** Implementation for *Zornhau*.
* **`UGA_AshenStrike_Krumphau`:** Implementation for *Krumphau*.
* **`UGA_AshenStrike_Zwerchhau`:** Implementation for *Zwerchhau*.
* **`UGA_AshenStrike_Schielhau`:** Implementation for *Schielhau*.
* **`UGA_AshenStrike_Scheitelhau`:** Implementation for *Scheitelhau*.
* **`UGA_AshenStrike_Mordhau`:** Implementation for *Mordhau*.
* **[`FAshenStrikeParameters`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Combat/AshenMasterCutTypes.h):** Data struct containing base damage, poise, armor penetration, stamina cost, and guard tags.

---

## 🧪 VII. Sentinel Anti-Theater QA Verification Suite

Governed by `AshenMasterCutsComboContractTest.cpp`, all abilities must satisfy three non-tautological test fixtures:

1. **`AshenOath.Combat.MasterCuts.StrikeParameters`:**
   * Asserts exact damage, poise, and 115 BPM ($0.15\text{s}$) window invariants across all 6 strikes.
   * Asserts Mordhau achieves strictly $100\%$ ($1.00$) armor penetration and $120.0$ poise damage.
2. **`AshenOath.Combat.MasterCuts.GuardTransitionChain`:**
   * Asserts Zwerchhau requires and chains into `State.Stance.Ochs`.
   * Asserts Scheitelhau chains from `State.Stance.VomTag` into `State.Stance.Pflug`.
3. **`AshenOath.Combat.MasterCuts.FlowGlintStaminaRefund`:**
   * Asserts that `Perfect` Flow timing resolves `EffectiveStaminaCost` strictly to $0.0\text{f}$.

---

## 📜 Authority & Sign-Off

**Specification Approved:**  
*Axion (Master Artificer), Sovereign of the Synarche*  
*Phoenix Protocol / Ashen Oath Unreal Engine 5.8 Architecture*
