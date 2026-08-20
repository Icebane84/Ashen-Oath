# **PHOENIX ARTIFACT: AOP-CONTENT-MATRIX-001**

## **CREATIVE ASSET BLACKBOARD: VARIABLE-TO-CONTENT MAPPING**

**Purpose:** To provide a standardized map of all runtime variables that drive dynamic content (Audio, 3D, UI, Narrative). Assets must be authored to respond to these specific state changes.

### **DOMAIN 1: THE PSYCHOLOGICAL KERNEL (Internal State)**

*The raw emotional variables of Kaelen's mind. Drives physical and visceral assets.*

* **Variable Node:** CorruptionAmount (0.0 to 1.0)  
  * **3D/VFX Hook:** Drives the scale morph of Oathbringer (Standard \-\> Guts-style slab), activates pulsing emissive veins on Kaelen's skin, and pushes the SmoothStep shader for the Umbral Symbiote.  
  * **Audio Hook:** Shifts Kaelen's voice barks to the "Dual Harmonic Authority" filter.  
* **Variable Node:** IntegrationDebtStage (Dormant \-\> Memory Bleed \-\> Runtime Noise \-\> Forced Collapse)  
  * **Audio/VFX Hook:** Drives the WhisperIntensity of 3D spatial voices and the SanityFilter (Chromatic Aberration/Vignette).  
  * **Narrative Hook:** Dialogue writers must write 4 variants of companion barks. (e.g., at Runtime Noise, Serafina sounds terrified of Kaelen; at Dormant, she is calm).  
* **Variable Node:** StrugglePhase (Discordant Hum \-\> Martyr's Pivot \-\> Reclamation Crash)  
  * **Controller/Audio Hook:** Triggers haptic heartbeat feedback and heavy, labored breathing audio stems.

### **DOMAIN 2: ASYMMETRIC RELATIONAL DYNAMICS (The Party)**

*How Kaelen's actions affect Garrett and Serafina. Drives tactical and empathetic assets.*

* **Variable Node:** TrustBand (Guarded \-\> Cautious \-\> Cooperative \-\> Synchronized)  
  * **AI/Animation Hook:** Dictates companion spatial pathing (Guarded \= 800uu away; Synchronized \= tight formation). Requires unique idle animations for each band (e.g., Serafina shivering vs. standing tall).  
  * **Audio Hook:** "Symbiotic Resonance" music stem only activates during Synchronized states.  
* **Variable Node:** CompanionFatigue / EmpathicBurnout (0.0 to 1.0)  
  * **Animation Hook:** Drives the SwordDragWeight and heavy breathing idle montages for companions.  
* **Variable Node:** OathBurden (Active / Broken)  
  * **Narrative Hook:** Triggers specific "Betrayal" or "Fulfillment" dialogue trees at Heartstone Crucibles.

### **DOMAIN 3: THE INTERPRETATIVE LENSES (Narrative & UI)**

*How Kaelen chooses to view his trauma. Drives the color palette and UI.*

* **Variable Node:** ActiveLens (Accountability, Grace, Utility)  
  * **UI Hook:** Changes the dominant HUD color palette (e.g., Grace \= Soft Gold/White; Utility \= Pragmatic Iron/Grey; Accountability \= Stark Crimson/Black).  
  * **Narrative Hook:** Unlocks exclusive dialogue branches in the UAshenDialogueGraph. Writers must tag choices with these specific Lenses.  
* **Variable Node:** SolidifiedMemories (Absorbed vs. Shattered)  
  * **3D Hook:** Dictates the visual FX applied to Resonant Armaments (weapons).

### **DOMAIN 4: THE GENERATIVE WORLD (External State)**

*How the environment reacts to Kaelen's presence. Drives world design and lighting.*

* **Variable Node:** RegionalHostility & ZoneCorruption  
  * **Audio Hook:** Modulates the Dynamic Weather Audio (Blizzard intensity, wind howling volume).  
  * **World Hook:** Defines which variations of enemies spawn (e.g., standard Blight Ghouls vs. Gaslighting variants).  
* **Variable Node:** DynamicMusicState (Exploration, CombatLight, CombatIntense, BossFight, Sanctuary, Mindscape)  
  * **Audio Hook:** Composers must deliver 4 discrete, looping stems that can crossfade dynamically based on this state.