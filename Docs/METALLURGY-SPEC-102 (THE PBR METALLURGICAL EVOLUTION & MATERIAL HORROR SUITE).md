# METALLURGY-SPEC-102: THE PBR METALLURGICAL EVOLUTION & MATERIAL HORROR SUITE

**Canonical Document Identifier:** `PRS-001-ENG-METAL-102`  
**Parent Specifications:** `PRS-001-MECH-010-MANIFES-V5`, `AOP-MASTER-CONVERGENCE-SPEC-V2.0`, `CONVERGENCE-SPEC-101`  
**Target Engine:** Unreal Engine 5.8 C++ / Lumen / PBR Anisotropic Shaders / MetaSounds  
**Authority Level:** Canonical Architectural Master Specification  
**V-Control:** 2026-08-30T23:25:00Z  

---

## 🏛️ I. Executive Aesthetic Mandate: The Anti-Arcade Law

`METALLURGY-SPEC-102` establishes the definitive material, acoustic, and psychological reality for **Oathbringer**, completely eliminating arcade "MMO Rarity Syndrome" (RGB neon power-ups, glowing LED pommel eyes, and floating visual vanity).

Oathbringer is an 8-pound, high-carbon steel greatsword—a lethal instrument of trauma, discipline, and biological horror. Progression is expressed through **metallurgy, physical finish, light absorption, and organic decay**, not cosmetic glows.

---

## ⚔️ II. The 5 Grounded Metallurgical Tiers

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       THE 5 GROUNDED METALLURGICAL TIERS                                        │
├──────┬──────────────────────┬────────┬─────────────────────────────┬────────────────────────────────────────────┤
│ Tier │ Name                 │ Mass   │ PBR Metallurgy & Visuals    │ Acoustic Foley & Dynamics                  │
├──────┼──────────────────────┼────────┼─────────────────────────────┼────────────────────────────────────────────┤
│ **1**│ **Burdened Iron**    │ 120 kg │ Rough carbon steel, mill    │ Coarse, grating steel-on-steel friction;   │
│      │ (Neglected Trauma)   │        │ scale, dried tallow in seam │ clumsy, heavy recovery drag.               │
├──────┼──────────────────────┼────────┼─────────────────────────────┼────────────────────────────────────────────┤
│ **2**│ **Honed Damascus**   │ 85 kg  │ Acid-etched folded steel;   │ Clean, razor-thin 2400 Hz wind hiss;       │
│      │ (Disciplined Form)   │        │ 4 Liechtenauer guard marks  │ tight balance snapping back to crossguard. │
├──────┼──────────────────────┼────────┼─────────────────────────────┼────────────────────────────────────────────┤
│ **3**│ **The Scribed Vow**  │ 50 kg  │ Hammered cold silver wire   │ 528 Hz pure silver bell chime with long    │
│      │ (Physical Memory)    │        │ inlays catching real light  │ acoustic decay on successful parries.      │
├──────┼──────────────────────┼────────┼─────────────────────────────┼────────────────────────────────────────────┤
│ **4**│ **Devouring**        │ 0 kg   │ Light-absorbing matte black │ Vacuum suction on swings; wet, tearing     │
│      │ **Nightsteel**       │ (+400) │ 2" suppression envelope;    │ organic crunch on impacts; tapetum lucidum │
│      │ (Parasitic Horror)   │        │ organic muscle veining      │ retroreflective animal eye glare on wolf.  │
├──────┼──────────────────────┼────────┼─────────────────────────────┼────────────────────────────────────────────┤
│ **5**│ **Cold Monolith**    │ 35 kg  │ Monolithic obsidian-steel,  │ **Total acoustic isolation.** Dead vacuum  │
│      │ (Absolute Stillness) │        │ surgical 2D edge, zero rust │ silence during swings until impact point.  │
└──────┴──────────────────────┴────────┴─────────────────────────────┴────────────────────────────────────────────┘
```

---

## 🎨 III. PBR Shader Architecture & Physics Invariants

1. **The Zero-Neon Invariant:** `EmissiveIntensity == 0.0f` is strictly enforced for Tiers 1, 2, 3, and 5.
2. **Cold Silver Wire Inlay Reflection (Tier 3):**
   * High specular reflectance ($0.95$) with near-zero roughness ($0.15$).
   * Inlaid runes illuminate **only** when reflecting real in-world light sources (campfires, torchlight, moonlight).
3. **Light-Absorption Envelope (Tier 4):**
   * Shaders implement an active lumen light-absorption envelope ($2.0\text{ inches}$) around the blade mesh, suppressing ambient light in proximity.
   * Seam normal map generates a subtle heat-haze distortion simulating vaporizing black bile.
4. **Tapetum Lucidum Wolf Eyes (Tier 4):**
   * Pommel eyes use a retroreflective micro-facet shader.
   * They reflect dull crimson-green **only** when the camera angle aligns with an active incident light vector, mimicking predatory eyes caught in a lantern beam.

---

## 🔊 IV. Acoustic MetaSounds & Foley Realism

* **Tier 1 (Burdened Iron):** Low-frequency heavy thuds, coarse whetstone drag.
* **Tier 2 (Honed Damascus):** High-frequency aerodynamic slicing ($2400\text{ Hz}$).
* **Tier 3 (The Scribed Vow):** Harmonically tuned $528\text{ Hz}$ silver bell transient on parry.
* **Tier 4 (Devouring Nightsteel):** Sub-bass vacuum whoosh ($45\text{ Hz}$) and wet anatomical cleave.
* **Tier 5 (Cold Monolith):** **Absolute swing silence.** All blade aerodynamic sound is suppressed, emphasizing the stark sound of the environment until bone is severed.

---

## 🧪 V. QA Automation Verification Matrix

1. **`AshenOath.Metallurgy.Contract.ZeroNeonEmissive`:** Asserts `EmissiveIntensity == 0.0f` for Tiers 1, 2, 3, 5.
2. **`AshenOath.Metallurgy.Contract.NightsteelLightAbsorption`:** Asserts Tier 4 activates `LightAbsorptionRadius == 2.0f` and `TapetumLucidumRetroreflection == 1.0f`.
3. **`AshenOath.Metallurgy.Contract.ColdMonolithAcousticSilence`:** Asserts Tier 5 enforces `bDeadAcousticIsolation == true` and `EffectiveMass == 35.0f`.
