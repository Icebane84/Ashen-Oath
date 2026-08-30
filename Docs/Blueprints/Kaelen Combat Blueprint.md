# **PRS-001 COMBAT BLUEPRINT (KAELEN)**

2026-08-06T06:15:30Z

## **PHOENIX SYNARCHE OPERATIONAL DIRECTIVE: PRS-001 COMBAT BLUEPRINT (KAELEN)**

### **WHAT**

The definitive master design document synthesizing Kaelen’s combat mechanics, defensive systems, and psychological state vectors for **Ashen Oath**. This document establishes the architectural standard for how the Gameplay Ability System (GAS) maps Kaelen’s internal conflict directly to player inputs and mechanical outcomes.

### **HOW**

By unifying the **Aegis of the White Flame** (defensive mastery), **The Devil's Bargain** (corruption temptation), and **The Willpower Reward Matrix** (restraint validation) into a single, cohesive framework. This blueprint outlines the specific class structures, tag integrations, and systemic consequences driving the combat loop.

### **WHY**

To solidify the conceptual engineering of Kaelen as a "Sundered Paladin." Combat in *Ashen Oath* must not be a disconnected minigame; it is the primary interactive vessel for narrative. By documenting these rules, we ensure that every frame of animation, every stamina drain, and every player choice reinforces the central theme of traumatic burden versus disciplined mastery.

## **UMB: The Combat Master Architecture**

### **I. The Architectural Foundation (GAS Integration)**

Kaelen’s combat is governed by the AshenAbilitySystemComponent, ensuring a total separation of data and execution.

* **State Tags (FGameplayTag):** Combat states are dictated by dynamic tags (e.g., Stance.Standard, Stance.UnchainedBerserk, State.Willpower.Unbroken).  
* **Attribute Manipulation:** Frame data, stamina costs, and movement speed are actively multiplied or suppressed based on the active tags applied by the player's choices and the system's lethal intercepts.

### **II. The Defensive Arsenal (The Aegis of the White Flame)**

Kaelen fights with precision, leverage, and momentum, utilizing **Oathbringer** as a two-handed defensive bulwark against titanic threats.

* **The Glancing Deflection (Perfect Parry):** A tight-window input that angles the blade to redirect kinetic force. Costs zero stamina, negates damage, and inflicts heavy stagger.  
* **The Half-Sword Brace (Standard Block):** A sustained, braced stance absorbing impact through the flat of the blade. Drains stamina heavily and incurs chip damage, but prevents knockdowns from behemoth-class enemies.  
* **The Crown Guard Counter-Bind:** Catching overhead strikes on the crossguard to execute positional throws or disarms.  
* **The Martyr’s Guard:** An over-extended dash-guard triggered to intercept lethal blows aimed at allies, spiking stamina drain or corruption as a mechanical reflection of his "Glass Shield" protocol.

### **III. The Devil's Bargain (Dark Mode / The Shadow's Rage)**

A hostile, parasitic transformation offered to the player during high-lethal crisis states. It is a choice born of panic and protective desperation.

* **The Trigger:** A visceral prompt triggered when Kaelen reaches zero health or an ally faces a lethal intercept.  
* **Mechanical Ecstasy (The Lure):** Immediate application of Stance.UnchainedBerserk. Stamina costs are negated, attack speed increases by 200%, hit-stop is removed, and Oathbringer becomes a weapon of pure erasure.  
* **The Cost (The Consequence):**  
  * **Trust Atrophy:** Damages the Party Trust Level, reducing companion combo frequency and delaying Serafina's healing logic.  
  * **Spiritual Scarring:** Locks a permanent percentage of maximum health/stamina behind a black "Stain" on the UI, requiring rare sanctuary resources to cleanse.

### **IV. The Willpower Reward Matrix (Light Mode / Mastery)**

The systemic validation of the player's restraint. By surviving lethal intercepts without surrendering to Dark Mode, the player earns a state of absolute Paladin mastery.

* **The Trigger:** Surviving a crisis state or ignoring a lethal intercept prompt applies State.Willpower.Unbroken.  
* **White Flame Surge (Immediate Combat Buffs):**  
  * Full stamina regeneration and \+50% recovery rate.  
  * **Kinetic Refinement:** Perfect Parry timing windows dynamically widen by \+2 to \+3 frames.  
  * **Smite Riposte:** Successful deflections automatically trigger a zero-cost radial shockwave of White Flame.  
* **Long-Term Mastery (Sanctuary Surplus):** By avoiding Spiritual Scarring, players save resources otherwise needed for cleansing, allowing for maximum investment into Oathbringer’s physical upgrades and advanced Resonance Tuning (e.g., Aegis Reflection).

### **V. The Trinity Doctrine (Companion Synergy)**

Kaelen’s combat loop is deeply woven into the AI StateTrees of his companions.

* **Garrett (The Architect of Chaos):** Provides crowd control and setup. When Kaelen holds the Unbroken tag, Garrett executes **Tactical Flank Intercepts**, altering his EQS to violently defend Kaelen's blind spots.  
* **Serafina (The Eye of the Storm):** Provides area denial and stability. Her **Harmonic Purification** triggers off Kaelen's perfect parries, restoring fractions of his stamina in a symbiotic loop of protection.

### **Honest Thoughts**

Seeing the entire matrix compiled like this reveals just how dense and interconnected this system is. We have successfully taken complex psychological traits—like Kaelen's self-destructive need to protect, the terrifying allure of dissociation, and the quiet triumph of disciplined restraint—and turned them into functional, deeply satisfying C++ loops. This is conceptual engineering working exactly as intended. The game does not just tell the player Kaelen is struggling; it makes the player physically balance that struggle on their controller.  
With the combat blueprint now fully defined and the architectural freeze in place, how should we approach designing the very first procedural enemy encounter to perfectly tutorialize this "Perfect Parry vs. Half-Sword Brace" mechanic without overwhelming the player?

# **COMBAT BLUEPRINT (MASTER SYNTHESIS V2.0)**

## **PHOENIX SYNARCHE OPERATIONAL DIRECTIVE: PRS-001 COMBAT BLUEPRINT (MASTER SYNTHESIS V2.0)**

**Timestamp:** 2026-08-06T03:00:00Z

### **WHAT**

The definitive, unified master design document for Kaelen’s combat architecture in **Ashen Oath**. This document establishes the absolute baseline for how the Gameplay Ability System (GAS), animation graphs, and diegetic sensory feedback map Kaelen’s internal psychological conflict directly to player inputs.

### **HOW**

By architecting the combat loop entirely around the paradigm of **Discipline (Mastery) vs. Desperation (Corruption)**. This synthesis integrates the core defensive toolkit, the Devil's Bargain, the Willpower Reward Matrix, the Synchronization Rating, and the Trinity Doctrine into a singular, cohesive simulation of Kaelen's psychological state.

### **WHY**

To ensure that *Ashen Oath* transcends standard action-RPG mechanics. Combat must serve as the primary interactive vessel for the narrative. By physically enforcing the burden of choice through frame data, haptics, and animation vocabulary, the player does not merely witness Kaelen's trauma and discipline; they actively execute it.

## **I. The Core Defensive Arsenal (Aegis of the White Flame)**

Kaelen’s baseline combat relies on high-skill kinetic redirection and leveraging **Oathbringer** against threats of all scales. Every action possesses a distinct, instantly readable silhouette.

* **The Glancing Deflection (Perfect Parry):** A micro-movement requiring absolute precision. Kaelen rotates the blade a fraction of a degree, standing perfectly still while the enemy's momentum is redirected. Costs zero stamina, negates damage, and inflicts heavy stagger.  
* **The Half-Sword Brace (Standard Block):** A wide, low, and exhausting stance used to survive titanic blows. Hands choke up on the unsharpened flat of the blade, and boots carve trenches into the dirt. Drains stamina heavily and incurs chip damage, but prevents knockdowns.  
* **The Crown Guard Counter-Bind:** A historical HEMA guard. Kaelen raises the hilt high to catch an enemy's blade in the massive crossguard, establishing leverage for a fluid disarm or pommel strike.  
* **The Martyr’s Guard:** Driven by his "Glass Shield" complex. An explosive, desperate sprint to intercept lethal blows aimed at Garrett or Serafina. Generates a wide, sacrificial silhouette that spikes stamina drain or corruption to guarantee ally safety.

## **II. The Devil's Bargain (Desperation / The Shadow's Rage)**

A hostile, parasitic transformation offered exclusively during high-lethal crisis states. It is a choice born of panic that exchanges long-term stability for immediate, catastrophic power.

* **The Trigger (Lethal Intercept):** When Kaelen's health reaches zero, or an ally is about to take a fatal blow, time dilates. A visceral, on-screen prompt allows the player to accept the Shadow's offer.  
* **Mechanical Ecstasy (The Lure):** Immediate application of the Stance.UnchainedBerserk tag. Stamina costs are eradicated, attack speed increases by 200%, and hit-stop is removed. Oathbringer cleaves through armor and stone with zero resistance.  
* **The Animation Language:** Predatory, explosive, and supernaturally fluid. The weapon no longer feels heavy; it anticipates intent. Kaelen is not sloppy—he is terrifyingly, inhumanly optimized.  
* **The Cost (The Consequence):**  
  * **Trust Atrophy:** Damages the Party Trust Level, throttling Serafina's healing logic and Garrett's combo frequency.  
  * **Spiritual Scarring:** Locks a permanent percentage of maximum health/stamina behind a black "Stain" on the UI, requiring rare sanctuary resources to cleanse. Synchronization Rating drops to zero.

## **III. The Willpower Reward Matrix (Discipline / Light Mode)**

The systemic validation of the player's restraint. By surviving lethal intercepts without submitting to Dark Mode, the player earns a state of absolute Paladin mastery.

* **The Trigger:** Surviving a crisis state or allowing a lethal intercept prompt to expire applies State.Willpower.Unbroken.  
* **The Animation Language:** Supreme economy of motion. Posture is grounded and upright. Swings feature clean anticipation, efficient acceleration, and controlled follow-through.  
* **White Flame Surge (Immediate Combat Buffs):**  
  * Full stamina regeneration and \+50% recovery rate.  
  * **Kinetic Refinement:** Perfect Parry timing windows dynamically widen by \+2 to \+3 frames.  
  * **Smite Riposte:** Successful deflections automatically trigger a zero-cost radial shockwave of White Flame.  
* **Long-Term Mastery (Sanctuary Surplus):** By avoiding Spiritual Scarring, players save resources otherwise needed for cleansing, enabling maximum investment into Oathbringer’s physical upgrades (e.g., Aegis Reflection).

## **IV. Diegetic Synchronization Feedback (The Flow State)**

The HUD is bypassed in favor of a multi-layered sensory feedback matrix. As Kaelen executes perfect actions (parries, clean dodges, Martyr's Guards), his **Synchronization Rating** builds, dynamically tightening animation blending and recovery frames.

* **Acoustic Harmonic Resonance:**  
  * **Low Sync:** Heavy, thudding impacts, dull metallic grinding, and ragged breathing.  
  * **High Sync:** Environmental noise is isolated (dropped by \-3 dB). Oathbringer's impacts pitch-shift into a pure silver bell-tonal ring. Kaelen's breathing locks into a steady, rhythmic cadence.  
* **Material & Shader Dynamics:**  
  * **The Diegetic Eye:** Kaelen's intense blue eyes scale in emissive intensity. At peak synchronization, evasive movements leave a razor-thin silver-blue flare.  
  * **Blade Resonance:** Oathbringer's Nightsteel blade loses its matte finish. Etched runes glow silver-blue, and weapon swings leave crisp, mirror-like spatial distortions indicating zero atmospheric drag.  
* **Kinematic Weight & Haptics:**  
  * **Low Sync:** Heavy, continuous controller rumble mirroring the exhaustive weight of the greatsword.  
  * **High Sync:** Micro-haptic clicks signal the exact opening frames of parry windows. Attack recoveries blend instantaneously, snapping Kaelen back into a perfect guard with magnetic stability.

## **V. The Trinity Doctrine (Companion Synergy)**

Combat is deeply woven into the AI StateTrees of Kaelen's companions, validating his internal state through their behavior.

* **Garrett (The Architect of Chaos):** Provides spatial control. When Kaelen holds the Unbroken tag, Garrett's EQS initiates **Tactical Flank Intercepts**, actively prioritizing enemies in Kaelen's blind spots with the animation language of absolute confidence.  
* **Serafina (The Eye of the Storm):** Provides stability. When Kaelen successfully executes a Perfect Parry, Serafina instantly follows with **Harmonic Purification**—a seamless, synchronized animation that restores fractions of his stamina in a symbiotic loop of protection.

### **Honest Thoughts**

This synthesis is the culmination of our conceptual engineering efforts, establishing a fiercely original combat identity for *Ashen Oath*. By mapping the dichotomy of Discipline vs. Desperation entirely through mechanics, animation graph states, and diegetic feedback, the player is never abstracted away from Kaelen's trauma. The removal of UI meters in favor of haptic and auditory cues is a massive technical challenge, but it is precisely what will elevate this from a standard Unreal project to a visceral, AAA-quality character study. The blueprint is tight, the GAS implementations are mapped, and the architectural baseline is rock solid.

# **THE DEVIL'S BARGAIN DIEGETIC UI PROMPT**

## **PHOENIX SYNARCHE OPERATIONAL DIRECTIVE: THE DEVIL'S BARGAIN DIEGETIC UI PROMPT**

**Timestamp:** 2026-08-06T07:14:10Z

**Artifact ID:** PRS-001-UI-006

---

### **What / How / Why**

* **What:** The visual, haptic, and acoustic design specification for "The Devil's Bargain" UI prompt, ensuring it presents as an intrusive, parasitic temptation during high-lethal crisis states rather than a gamified HUD element.  
*   
* **How:** By enforcing the **UI Constitution (UMB-UI-004)** principles—stripping traditional game icons, employing temporal dilation, introducing physical controller friction, and bleeding corruptive visual/audio artifacts directly into the gameplay space.  
*   
* **Why:** If the prompt looks like a standard "Press LB+RB to Unleash Ultimate," it communicates a reward to be used strategically. If it looks like a hostile rupture in Kaelen's perception—shattering game rules while his companions scream—the player experiences the exact panic, guilt, and illicit relief that defines Kaelen's trauma.  
* 

---

## **I. Constitutional UI Pillars for the Prompt**

Following our established **UMB-UI-004 Diegetic Interface Constitution**:

1. **Zero HUD Framing:** No clean button icons, blue highlight rings, or power meters. The prompt must not live on the HUD overlay; it exists as an in-world anomaly attached to Kaelen's body (the Shadow's Mark on his forearm).  
2.   
3. **Somatic Intrusion (Meaning → Expression):** The engine reality (FSoulStateVector, lethal intercept event) translates into Kaelen's physiological panic—tunnel vision, muffled audio, and spatial distortion.  
4.   
5. **Physical Friction (The Burden of Choice):** The input must require sustained, uncomfortable physical effort on the controller to prevent accidental triggers and force intentional surrender.  
6. 

---

## **II. The Crisis State Trigger & Visual Language**

\[ Lethal Intercept / Zero HP Event \]  
                 ↓  
\[ Temporal Dilation (Time slows to 10%) \]  
                 ↓  
\[ Color Desaturation \+ Acoustic Muffling \]  
                 ↓  
\[ Diegetic Intrusive Anomaly (Veins \+ Controller Friction) \]  
                 ├─ Path A: Hold Both Triggers → SURRENDER (Dark Mode)  
                 └─ Path B: Hold Stance / Expire → RESIST (Willpower Surge)

### **1\. Environmental & Perceptual Shift (The Setup)**

* **Temporal Dilation:** The moment a fatal hit connects on Kaelen or an ally (Garrett/Serafina), time decelerates to **10% speed**.  
* **Chromatic & Contrast Drain:** World colors wash out into muted slate-greys, except for two elements:  
  * The lethal threat (monstrous weapon, blood spray) highlighted in stark, high-contrast silhouette.  
  * The **Shadow’s Mark** crawling up Kaelen’s arm, glowing with an ominous, black-and-crimson oil sheen.

### **2\. The Intrusive Prompt (No "Press X")**

* **Diegetic Vein Creep:** Black, vein-like tendrils bleed out from the center of the screen, creeping inward like cracking glass or ocular pressure artifacts.  
* **The In-World Input:** Floating HUD text is strictly forbidden. Instead, the physical controller inputs (e.g., **LT \+ RT / L2 \+ R2**) appear etched directly into the game world—pulsing darkly along the glowing veins of Kaelen's forearm in rough, jagged runic scratches that mimic his unsteady pulse.  
* **Subliminal Text Overlay:** Faint, semi-transparent phrases flicker across the peripheral vision for single frames—not as game UI, but as intrusive thoughts: *"Let go," "They die," "Take it."*

---

## **III. Acoustic & Haptic Friction Layer**

### **1\. Acoustic Isolation**

* **Muffled Reality:** The sound of wind, combat, and music drops out instantly, replaced by a low-frequency, suffocating vacuum effect.  
* **The Parasite's Whisper:** A wet, guttural heartbeat fills the audio center, accompanied by the muffled, panicking voice of Garrett or Serafina screaming Kaelen's name from a distance.  
* **Audio Tension:** As the prompt's timer ticks down (the 2–3 second window of dilated time), the pitch of the heartbeat rises, creating unbearable acoustic pressure.

### **2\. Controller Resistance (DualSense / Advanced Haptics)**

* **Adaptive Trigger Tension:** The adaptive triggers lock into a heavy, resistant state. The player cannot simply tap the triggers; they must **forcefully press past a physical resistance threshold** (simulating breaking Kaelen's mental barrier).  
* **Asymmetric Haptic Pulse:** The left side of the controller vibrates with a chaotic, heavy thrum (the Shadow's corruption), while the right side vibrates with a tight, rapid pulse (Kaelen's panic).

---

## **IV. The Choice & Resolution Matrix**

| Player Action | Visual & Sensory Transition | Immediate Game State |
| :---- | :---- | :---- |
| **Surrender (Hold Triggers Past Threshold)** | Black tendrils snap inward to cover the screen; a horrific tearing sound plays; time snaps back to 100% with violent velocity. | Applies Stance.UnchainedBerserk. All UI elements vanish; camera drops low and tight; attack speed doubles instantly; Trust Atrophy incurs. |
| **Resist (Ignore Prompt / Expire Window)** | The black veins shatter like glass, dissolving into bright silver dust; a pure, resonant bell tone sounds. | Applies State.Willpower.Unbroken. Kaelen executes an automatic **White Flame Parry**, stamina recharges fully, and the Flow State begins. |

---

### **Honest Thoughts**

Designing "The Devil's Bargain" as a hostile intrusion rather than a standard ability is what keeps the game grounded in Kaelen's trauma. By using adaptive trigger resistance, color desaturation, and in-world runic tendrils instead of a glowing button icon on a HUD, the player doesn't think "I should save my ultimate for the boss phase." Instead, they feel the immediate panic of a failing fight and must make a conscious, uncomfortable physical choice on the controller to give up Kaelen's humanity. It transforms a UI element into a narrative knife-edge.

# **DIEGETIC UI VALIDATION**

2026-08-06T07:14:43Z

## **PHOENIX SYNARCHE OPERATIONAL DIRECTIVE: DIEGETIC UI VALIDATION**

### **WHAT**

Architectural validation and integration of Artifact ID: PRS-001-UI-006 into the **Ashen Oath** master blueprint. This locks in the visual, acoustic, and haptic framework for the "Devil's Bargain" prompt.

### **HOW**

By cross-referencing the proposed sensory friction directly against Kaelen's established trauma profile and physiological reactions. We align the controller resistance, temporal dilation, and diegetic visual artifacts with his "Glass Shield" protocol and the canonical behavior of the Shadow's Mark.

### **WHY**

To guarantee that the physical act of playing the game enforces the emotional reality of the narrative. If the player feels actual physical resistance on the controller triggers while their allies scream in muffled slow-motion, the transformation ceases to be a gameplay mechanic and becomes an act of shared desperation.

## **AOP: Structural & Narrative Alignment**

The UI Constitution proposed in PRS-001-UI-006 is a flawless translation of Kaelen's internal psychology into player-facing mechanics. Here is how your design seamlessly integrates with the established lore:

* **The Shadow's Mark as the Anchor:** Utilizing Kaelen's left forearm as the origin point for the prompt is perfectly canonical. The Shadow's Mark is a physical scar located on his left arm, appearing as a tracery of greyish-black veins that darken to an obsidian black when he is tempted by dark power.  
* **The "Glass Shield" Catalyst:** The trigger condition—a lethal threat to Garrett or Serafina—directly activates Kaelen's "Glass Shield" protocol, where his instinct is to position himself as the sole target to absorb pain for others. The temporal dilation forces the player to sit inside that exact moment of paralyzing protective fatalism.  
* **Acoustic Isolation:** Dropping ambient noise to replace it with a guttural heartbeat and muffled screams leverages his greatest fear: failing to protect those he cares about. It simulates the dissociation he experiences when surrendering control to the Shadow Self.  
* **Haptic Resistance:** The asymmetric vibration and adaptive trigger tension physically manifest the battle taking place in his mind. The player has to fight the controller to surrender, just as the Shadow Self must break Kaelen's will to take over.  
* **The Willpower Surge Resolution:** When the player successfully resists the prompt, the black veins shattering into silver dust beautifully juxtaposes the corruptive visuals. In this moment of pure resolve, Kaelen's intense blue eyes can pierce through the dimness, signaling his return to absolute control without needing an on-screen text confirmation.

### **Honest Thoughts**

This directive is a triumph of empathetic game design. You have taken a standard action-game trope (the "super mode" prompt) and weaponized it against the player's comfort. By moving the input indicators off a 2D HUD and etching them into Kaelen's infected, pulsing veins, you destroy the safety barrier between the player and the protagonist. The use of adaptive trigger resistance is particularly brilliant; forcing the player to physically *squeeze* past a mechanical lock simulates the exact mental snap Kaelen undergoes. This solidifies the combat blueprint as a true behavioral simulation. No further revisions are required for this module; it is ready for prototype integration.  
