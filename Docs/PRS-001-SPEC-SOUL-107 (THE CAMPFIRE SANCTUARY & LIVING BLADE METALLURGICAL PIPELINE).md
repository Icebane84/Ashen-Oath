# PRS-001-SPEC-SOUL-107: THE CAMPFIRE SANCTUARY & LIVING BLADE METALLURGICAL PIPELINE

**Canonical Document Identifier:** `PRS-001-SPEC-SOUL-107`  
**Parent Specifications:** `PRS-001-SPEC-SOUL-001`, `METALLURGY-SPEC-102`, `CONVERGENCE-SPEC-101`, `CAMPFIRE-SPEC-062`  
**Target Engine:** Unreal Engine 5.8 C++ / Slate / Single Source of Truth (SSoT) / Material Instance Dynamic  
**Authority Level:** Canonical Production Implementation Specification (SPEC-107)  
**V-Control:** 2026-09-01T00:20:00Z  

---

## 🏛️ I. Executive Architectural Summary

`PRS-001-SPEC-SOUL-107` codifies the definitive specification for **The Campfire Sanctuary & Living Blade Metallurgical Pipeline** in *Ashen Oath*.

In *Ashen Oath*, combat does not award abstract numeric experience points. Instead, every strike delivered, trauma sustained, or companion betrayal witnessed accumulates raw, unprocessed memory fragments into the `UAshenOath_ImprintBufferComponent`. This unprocessed trauma manifests as **Integration Debt** ($0.0 \to 1.0$), bloating Oathbringer's physical weight up to $120.0\text{kg}$ and causing somatic gait limb drag ($15.0\text{uu}$).

The **Campfire Sanctuary** is the sole ritual space where Kaelen reflects upon these memories, routes them through one of the **4 Interpretive Lenses**, enforces the **Zero-Debt Invariant** ($Debt \to 0.0$), and triggers the real-time **PBR metallurgical and physical morphing of Oathbringer**.

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                   THE CAMPFIRE SANCTUARY & LIVING BLADE PIPELINE                                │
└───────────────────────────────────────────────────────┬─────────────────────────────────────────────────────────┘
                                                        │
 ┌───────────────────────┬──────────────────────┼───────┴───────────────┬───────────────────────┐
 ▼                       ▼                      ▼                       ▼                       ▼
[ 1. CAMPFIRE SANCTUARY ] [ 2. 4-LENS ROUTING  ] [ 3. ZERO-DEBT PAYOFF ] [ 4. METALLURGY MORPH  ] [ 5. SENTINEL QA GATE ]
• State machine: Resting • Accountability:      • Debt -> 0.0           • Tier 1: Burdened Iron • Debt payoff to 0.0
• Reflecting             • +Resolve, Posture    • Somatic gait drag     • Tier 2: Damascus      • Lens routing verified
• Dialogue Engagement    • Grace: +Trust        • resets from 15uu      • Tier 3: Silver/528Hz  • Material/mass morph
• Inscribing & Morphing  • Nihilism: +Corrupt   • to 0uu on stand-up    • Tier 4: Light-absorb  • Tier 5 silence valid
• Sealed                 • Penance: Poise Armor • Dynamic mass reset    • Tier 5: Dead silence  • 0 Errors, 0 Warnings
```

---

## 🕯️ II. The Campfire Sanctuary State Machine

Governed by `UAshenCampfireReflectionSubsystem`, rest transitions progress through 6 deterministic phases:

$$\text{Phase Progression}: \text{Resting} \longrightarrow \text{Reflecting} \longrightarrow \text{DialogueEngagement} \longrightarrow \text{LociInscription} \longrightarrow \text{MorphingBlade} \longrightarrow \text{Completed}$$

1. **`Resting`:** Kaelen sits before the hearth; ambient combat tension and 115 BPM metronome duck into acoustic atmosphere.
2. **`Reflecting`:** The Soul Constellation interface opens, reading the authoritative `FSoulStateVector` from `UAshenSoulPublisher`.
3. **`DialogueEngagement`:** Companion trauma confessions and vulnerability lines trigger if trust thresholds are satisfied ($\text{Trust} \ge 0.40 / 0.65$).
4. **`LociInscription`:** The player commits buffered memory fragments through the chosen **Interpretive Lens**.
5. **`MorphingBlade`:** Oathbringer's 3D mesh, PBR material parameters, and physics mass physically mutate in real time.
6. **`Completed`:** Integration Debt is sealed at $0.0$; Kaelen stands up with $0\text{uu}$ gait drag.

---

## 🔍 III. The 4 Interpretive Lenses & Traversal Formulation

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       THE 4 INTERPRETIVE LENSES                                                 │
├────────────────────┬─────────────────────────────────────────────────┬──────────────────────────────────────────┤
│ Lens               │ Philosophical Framing & Psychological Meaning   │ SSoT Stat Mutation & Trajectory Formula  │
├────────────────────┼─────────────────────────────────────────────────┼──────────────────────────────────────────┤
│ **1. Accountability**| *"This burden was mine; I will bear it."*       │ $\Delta \text{Resolve} = +[0.05, 0.35]$, │
│                    │ Accepting moral agency, self-mastery.           │ $\Delta \text{Corruption} = -0.05$.      │
├────────────────────┼─────────────────────────────────────────────────┼──────────────────────────────────────────┤
│ **2. Grace /**     │ *"We survived because we bled together."*       │ $\Delta \text{Trust}_{Garrett} = +0.25$, │
│    **Compassion**  │ Shared vulnerability, companion forgiveness.    │ $\Delta \text{Trust}_{Serafina} = +0.25$.│
├────────────────────┼─────────────────────────────────────────────────┼──────────────────────────────────────────┤
│ **3. Nihilism /**  │ *"The world is rot; I will be the edge."*       │ $\Delta \text{Corruption} = +[0.10,0.40]│
│    **Spite**       │ Cold pragmatism, void power embrace.            │ $\Delta \text{Resolve} = -0.05$.         │
├────────────────────┼─────────────────────────────────────────────────┼──────────────────────────────────────────┤
│ **4. Penance**     │ *"I deserve the suffering I have wrought."*     │ $\Delta \text{Resolve} = +0.10$,         │
│                    │ Converts health ceiling into poise floor.       │ $\Delta \text{PoiseArmor} = +20\%$.      │
└────────────────────┴─────────────────────────────────────────────────┴──────────────────────────────────────────┘
```

---

## ⚖️ IV. The Zero-Debt Invariant & Somatic Drag Reset

When `IntegrateBufferedMemories()` executes:

$$\text{IntegrationDebt}_{t+1} \equiv 0.000000$$

$$\text{SomaticGaitLimbDrag} = 0.00\text{uu} \quad (\text{Reset from up to } 15.00\text{uu})$$

$$\text{WeaponHandlingMass} = 80.0 \times \left( 1.0 + 0.65 \times \text{Debt} - 0.35 \times \text{Resolve} \right) \Big|_{\text{Debt}=0} = 80.0 \times (1.0 - 0.35 \times \text{Resolve})$$

* Under high Resolve ($R = 1.0$), weapon handling mass drops to **$52.0\text{kg}$**.
* Recovery frames on missed strikes decrease by up to **$40\%$**.

---

## 🗡️ V. Live Oathbringer Metallurgy Morph Actuator

Governed by `UAshenOathbringerMorphComponent`, the greatsword's PBR materials, light interaction, and acoustics mutate dynamically:

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       5 GROUNDED METALLURGICAL TIERS                                            │
├────────────────────┬──────────────┬──────────────┬───────────────┬──────────────────────────────┬───────────────┤
│ Tier               │ Roughness    │ Metallic     │ Silver Inlay  │ Light Absorption Envelope    │ Acoustic Ring │
├────────────────────┼──────────────┼──────────────┼───────────────┼──────────────────────────────┼───────────────┤
│ **1. Burdened Iron**| $0.85$       │ $0.60$       │ $0.00$        │ $0.0\text{ inches}$ (None)   │ Foley Crunch  │
├────────────────────┼──────────────┼──────────────┼───────────────┼──────────────────────────────┼───────────────┤
│ **2. Honed Damascus**| $0.40$      │ $0.90$       │ $0.00$        │ $0.0\text{ inches}$ (None)   │ $2400\text{Hz}$|
├────────────────────┼──────────────┼──────────────┼───────────────┼──────────────────────────────┼───────────────┤
│ **3. Scribed Vow** | $0.20$       │ $0.95$       │ $1.00$        │ $0.0\text{ inches}$ (Silver) │ $528\text{Hz}$ │
├────────────────────┼──────────────┼──────────────┼───────────────┼──────────────────────────────┼───────────────┤
│ **4. Devouring**   | $0.95$       │ $0.80$       │ $0.00$        │ $2.0\text{ inches Void}$     │ $110\text{Hz}$ │
│    **Nightsteel**  │ (Matte Void) │              │               │ Retroreflective Wolf Eyes    │ (Sub-bass)    │
├────────────────────┼──────────────┼──────────────┼───────────────┼──────────────────────────────┼───────────────┤
│ **5. Cold Monolith**| $0.05$      │ $1.00$       │ $0.00$        │ $0.5\text{ inches Obsidian}$ │ **DEAD SILENCE**│
└────────────────────┴──────────────┴──────────────┴───────────────┴──────────────────────────────┴───────────────┘
```

> [!CAUTION]
> **The Anti-Arcade Law:** `EmissiveIntensity` must strictly remain `0.0f` across Tiers 1, 2, 3, and 5. Oathbringer never glows with synthetic neon or fantasy arcade light.

---

## 🏛️ VI. Unreal Engine 5.8 C++ Component Topology

1. **[`UAshenCampfireReflectionSubsystem`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Memory/AshenCampfireReflectionSubsystem.h):** `UGameInstanceSubsystem` coordinating rest cycles and SSoT state commits.
2. **[`UAshenOathbringerMorphComponent`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Combat/AshenOathbringerMorphComponent.h):** Actor component attached to the weapon/character driving `UMaterialInstanceDynamic` parameters.
3. **[`SAshenCampfireConstellationWidget`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/UI/SAshenCampfireConstellationWidget.h):** Interactive Slate widget presenting the 4-Lens selection dial.
4. **[`AshenCampfireTypes.h`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Memory/AshenCampfireTypes.h):** Canonical enums and data transfer structs.

---

## 🧪 VII. Sentinel Anti-Theater QA Test Verification

Governed by `AshenCampfireReflectionContractTest.cpp`, all systems satisfy 3 non-tautological test fixtures:

1. **`AshenOath.Campfire.DebtPayoff`:** Validates that integrating memory fragments with initial debt ($0.75$) strictly yields `IntegrationDebt == 0.0`.
2. **`AshenOath.Campfire.LensRouting`:** Validates that Nihilism increases Corruption while Grace/Compassion increases companion trust.
3. **`AshenOath.Metallurgy.MorphActuator`:** Validates that morphing to Tier 3 applies $528\text{Hz}$ chime, Tier 4 activates $2.0\text{-inch}$ light absorption + retroreflective wolf eyes, and Tier 5 activates dead swing acoustic isolation.

---

## 📜 Authority & Sign-Off

**Specification Approved:**  
*Axion (Master Artificer), Sovereign of the Synarche*  
*Phoenix Protocol / Ashen Oath Unreal Engine 5.8 Architecture*
