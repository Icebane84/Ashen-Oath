# PRS-001-SPEC-AI-109: MARTIAL ENEMY AI & LIECHTENAUER STATETREE COUNTER CONTRACT

**Canonical Document Identifier:** `PRS-001-SPEC-AI-109`  
**Parent Specifications:** `PRS-001-SPEC-COMBAT-106`, `PRS-001-SPEC-INPUT-108`, `PRS-001-CDTC-001`, `CONVERGENCE-SPEC-101`  
**Target Engine:** Unreal Engine 5.8 C++ / StateTree / AIModule / Gameplay Ability System (GAS) / Chaos  
**Authority Level:** Canonical Production Implementation Specification (SPEC-109)  
**V-Control:** 2026-09-01T01:50:00Z  

---

## 🏛️ I. Executive Summary & Design Mandate

`PRS-001-SPEC-AI-109` establishes the canonical artificial intelligence architecture for **Martial Enemy Combatants & Bosses** in *Ashen Oath*.

### The Anti-Arcade Martial AI Philosophy
Traditional action RPGs treat enemies as damage sponges that cycle through pre-rendered attack timers decorated with neon telegraph icons. *Ashen Oath* rejects this. Every sentient combatant operates within the **symmetrical historical framework of Johannes Liechtenauer’s *Kunst des Fechtens***:

1. **Symmetrical Martial Grounding:** Enemies hold authentic historical guards (*Vom Tag*, *Ochs*, *Pflug*, *Alber*), execute the Five Master Cuts, and evaluate blade pressure (*Fühlen*).
2. **Diegetic Telegraphing (Zero Arcade Floating Icons):** Attack intent is communicated entirely through authentic weapon postures, weight shifts, footwork angles, and foley scrape acoustics.
3. **StateTree Reactive Counter-Play:** Enemies actively evaluate Kaelen's stance and attempt to seize the *Vor* (initiative); if Kaelen predicts their intent and executes the authentic hard counter, the enemy suffers catastrophic posture damage ($1.75\times \to 2.0\times$) and poise collapse.

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       MARTIAL ENEMY AI STATETREE ARCHITECTURE                                   │
└───────────────────────────────────────────────────────┬─────────────────────────────────────────────────────────┘
                                                        │
 ┌───────────────────────┬──────────────────────┼───────┴───────────────┬───────────────────────┐
 ▼                       ▼                      ▼                       ▼                       ▼
[ 1. DIEGETIC POSTURE ] [ 2. STANCE EVALUATION ] [ 3. MASTER COUNTERS  ] [ 4. BIND PRESSURE     ] [ 5. POSTURE COLLAPSE ]
• Enemies adopt real    • StateTree scans      • AI selects authentic  • Applies Weak vs Strong• Hard-counter hit
  historical guards     • Kaelen's stance,     • Master Cut to seize   • blade resistance to   • inflicts 2.0x poise
• Blade scrapes on floor  distance, & momentum • the Vor (initiative)  • test Kaelen's Fühlen  • damage + 1.5s stagger
```

---

## 🥋 II. The 4 Martial AI Archetypes

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       ENEMY MARTIAL ARCHETYPE MATRIX                                            │
├────────────────────┬───────────────────┬──────────────────────────────────────┬─────────────────────────────────┤
│ Archetype          │ Enemy Class       │ Tactical Behavior & Martial IQ       │ Bind Pressure Profile (Fühlen)  │
├────────────────────┼───────────────────┼──────────────────────────────────────┼─────────────────────────────────┤
│ **1. Novice**      │ Conscripted       │ Holds static guards for long periods;│ **Always Weak (*Weich*):**      │
│    **Levyman**     │ Footman           │ slow recovery; telegraphs heavily.   │ Flinches on blade contact; open │
│                    │                   │ Easily baited with *Alber*.          │ to immediate *Zorn-Ort* thrust. │
├────────────────────┼───────────────────┼──────────────────────────────────────┼─────────────────────────────────┤
│ **2. Veteran**     │ Inquisitorial     │ Actively reads Kaelen's guard and    │ **Dynamic (Weak / Strong):**    │
│    **Man-at-Arms** │ Knight            │ executes Master Cut counters;        │ Pushes firmly (*Hart*) on high  │
│                    │                   │ steps off-axis to avoid direct binds.│ cuts; requires *Winden* follow-up│
├────────────────────┼───────────────────┼──────────────────────────────────────┼─────────────────────────────────┤
│ **3. Grandmaster** │ The Penitent      │ Chains Master Cuts at 115 BPM;       │ **Master Winder (Strong):**     │
│    **Champion**    │ Executioner (Boss)│ baits with *Alber*; punishes missed  │ Yields instantly into *Duplieren│
│                    │                   │ Flow Glints with unblockable crushes.│ / Mutieren* if Kaelen pushes.   │
├────────────────────┼───────────────────┼──────────────────────────────────────┼─────────────────────────────────┤
│ **4. Asymmetric**  │ Stalker /         │ Avoids longsword binds completely;   │ **Zero Bind (Evasion):**        │
│    **Infiltrator** │ Dual-Dagger Rogue │ circles into Kaelen's rear flanks;   │ Sips around heavy swings; must  │
│                    │                   │ attacks during heavy recovery frames.│ be broken via *Zwerchhau* 360.  │
└────────────────────┴───────────────────┴──────────────────────────────────────┴─────────────────────────────────┘
```

---

## 🧠 III. StateTree Martial Decision Logic (Sense-Decide-Act)

Governed by `UAshenAIStateTreeEvaluator_Liechtenauer`, the AI evaluates combat context every tick ($60\text{Hz}$):

```mermaid
graph TD
    SENSE["1. SENSE KAELEN'S STATE<br/>• Active Guard Tag<br/>• Distance (d)<br/>• Poise / Stamina Ratio"] --> DECIDE{"2. DECIDE ACTION"}
    
    DECIDE -->|Kaelen in Vom Tag| C_VT["Queue Zornhau Cleave Intercept<br/>or Step-Offline Zwerchhau"]
    DECIDE -->|Kaelen in Ochs| C_OX["Queue Krumphau Shield Breaker<br/>(Crossed-Wrist Hand Strike)"]
    DECIDE -->|Kaelen in Pflug| C_PF["Queue Schielhau Counter-Cut<br/>(Dipped Point Neck Strike)"]
    DECIDE -->|Kaelen in Alber (Bait)| C_AL["Queue Scheitelhau Decapitation<br/>or Feint into Low Thrust"]
    
    C_VT --> ACT["3. ACT (FIRE GAS ABILITY)<br/>• Spawn Motion Warp<br/>• Play Montage at 115 BPM<br/>• Monitor Blade Sweep Trace"]
    C_OX --> ACT
    C_PF --> ACT
    C_AL --> ACT
```

---

## 👂 IV. Diegetic Telegraphing & Anti-Arcade Sensory Cues

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       DIEGETIC SENSORY TELEGRAPH MATRIX                                         │
├────────────────────┬───────────────────────────────────────┬────────────────────────────────────────────────────┤
│ Telegraph Vector   │ Diegetic Manifestation                │ Player Read & Counter Strategy                     │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **Visual Posture** │ Enemy raises sword high over right    │ **Enemy entering Vom Tag:** Prepare *Zornhau*      │
│                    │ shoulder with hips squared forward.   │ clash to take the center line.                     │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **Acoustic Foley** │ Sharp blade scrape along cobblestones │ **Enemy entering Alber (Fool's Guard):** Enemy is  │
│                    │ as sword point drags on ground.       │ baiting your head; do NOT rush with basic swing.   │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **Footwork Shift** │ Heavy lateral step with leading foot  │ **Enemy preparing Krumphau:** Stepping offline;    │
│                    │ crossing the centerline.              │ disengage or shift into *Pflug* immediately.       │
├────────────────────┼───────────────────────────────────────┼────────────────────────────────────────────────────┤
│ **Blade Resonance**│ Crystalline high-frequency ring       │ **Enemy preparing Ochs Thrust:** Point is aimed at │
│                    │ ($528\text{Hz}$) as quillons align.   │ face; execute *Schielhau* to beat point down.      │
└────────────────────┴───────────────────────────────────────┴────────────────────────────────────────────────────┘
```

---

## 💥 V. The Hard-Counter Posture Breakdown Formulation

When Kaelen executes the historically authentic Master Cut against an enemy holding a vulnerable guard:

$$P_{damage} = P_{base} \times M_{counter} \times \left( 1.0 + 0.50 \times R \right)$$

$$\text{StaggerDuration} = T_{base} \times S_{counter}$$

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       HARD-COUNTER DAMAGE MULTIPLIERS                                           │
├────────────────────┬───────────────────┬───────────────────────────────┬────────────────────────────────────────┤
│ Kaelen Master Cut  │ Enemy Guard       │ Posture Multiplier ($M$)      │ Stagger Duration ($S$) & Consequence   │
├────────────────────┼───────────────────┼───────────────────────────────┼────────────────────────────────────────┤
│ **`Zornhau`**      │ **`Vom Tag`**     │ **$1.75\times$**              │ **$1.2\text{s}$ Stagger:** Centerline  │
│                    │                   │                               │ broken; opens free *Zorn-Ort* thrust.  │
├────────────────────┼───────────────────┼───────────────────────────────┼────────────────────────────────────────┤
│ **`Krumphau`**     │ **`Ochs`**        │ **$2.00\times$** (Shield Break)│ **$1.5\text{s}$ Major Stagger:** Guard │
│                    │                   │                               │ collapsed; enemy weapon deflected away.│
├────────────────────┼───────────────────┼───────────────────────────────┼────────────────────────────────────────┤
│ **`Zwerchhau`**    │ **`Vom Tag`**     │ **$1.50\times$**              │ **$0.8\text{s}$ Rapid Stun:** Chains   │
│                    │                   │                               │ into horizontal helicopter loop.       │
├────────────────────┼───────────────────┼───────────────────────────────┼────────────────────────────────────────┤
│ **`Schielhau`**    │ **`Pflug / Ochs`**│ **$1.80\times$**              │ **$1.3\text{s}$ Stagger:** Enemy point │
│                    │                   │                               │ beaten down; exposes neck for thrust.  │
├────────────────────┼───────────────────┼───────────────────────────────┼────────────────────────────────────────┤
│ **`Scheitelhau`**  │ **`Alber`**       │ **$1.90\times$**              │ **$1.4\text{s}$ Heavy Stun:** Over-    │
│                    │                   │                               │ head cleave induces ground fracture.   │
└────────────────────┴───────────────────┴───────────────────────────────┴────────────────────────────────────────┘
```

---

## 🏛️ VI. Unreal Engine 5.8 C++ StateTree AI Architecture

### 1. Component & Evaluator Topology

* **`UAshenAIStateTreeEvaluator_Liechtenauer`:** StateTree evaluator sampling Kaelen's `FSoulStateVector`, active stance gameplay tags (`State.Stance.*`), and relative distance.
* **`UAshenAITask_ExecuteMasterCutCounter`:** StateTree task selecting and activating the appropriate `UAshenGameplayAbility_CombatStrike` on the AI's Ability System Component.
* **`UAshenLiechtenauerMatrixDataAsset`:** Data-driven primary data asset storing guard counter rules, posture damage multipliers, and bind resistance curves.
* **`UAshenBladeBindComponent`:** Weapon collision component calculating tactile contact resistance and triggering *Fühlen* branch decisions.

---

## 🧪 VII. Sentinel Anti-Theater QA Verification Suite

All martial AI logic is verified via non-tautological test fixtures:

1. **`AshenOath.AI.CounterSelection`:** Asserts that when player holds `State.Stance.Ochs`, AI StateTree strictly selects `UGA_AshenStrike_Krumphau` as the primary counter.
2. **`AshenOath.AI.PostureMultiplier`:** Asserts that a hard-counter Master Cut connection multiplies raw poise damage by strictly $1.75\times \to 2.0\times$.
3. **`AshenOath.AI.FuhlenResolution`:** Asserts that AI correctly yields to *Zorn-Ort* on `Weak` binds and executes *Winden* on `Strong` binds.

---

## 📜 Authority & Sign-Off

**Specification Approved:**  
*Axion (Master Artificer), Sovereign of the Synarche*  
*Phoenix Protocol / Ashen Oath Unreal Engine 5.8 Architecture*
