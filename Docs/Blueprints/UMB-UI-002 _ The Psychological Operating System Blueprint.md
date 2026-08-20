## **Operational UI Architecture: UMB-UI-002 | *The Psychological Operating System Blueprint***

### ---

**What**

We are adopting Sophia’s **Psychological Operating System** paradigm for the *Ashen Oath* interface.

We are abandoning traditional, game-y menu grids and raw numerical spreadsheets. Every screen is refactored around a **Single Governing Question**, transforming the UI into a diegetic extension of Kaelen's physical journal, the living campfire, and his internal mindscape.

                         \[KAELEN'S FIELD JOURNAL\]  
                           (The Root UI Hub)  
                                  │  
      ┌───────────────────────────┼───────────────────────────┐  
      ▼                           ▼                           ▼  
\[EXPEDITION LOG\]          \[CAMP / RELATIONSHIPS\]      \[PHYSICAL EQUIPMENT\]  
"What have we learned?"   "How are we doing?"         "What am I carrying?"  
      │                           │                           │  
      └───────────────────────────┼───────────────────────────┘  
                                  │  
                                  ▼  
                     \[INTERPRETATION & MEMORY\]  
                                  │  
            ┌─────────────────────┴─────────────────────┐  
            ▼                                           ▼  
\[THE CONSTELLATION GRAPH\]                   \[THE HEARTSTONE SANCTUARY\]  
"Why am I like this?"                       "Who do I become next?"

### ---

**How**

#### **1\. The Single-Question Screen Hierarchy**

| Screen / Interface | Governing Question | Aesthetic & Structural Translation |
| :---- | :---- | :---- |
| **Journal (Root)** | *"What have we learned?"* | Physical leather-bound book. Handwriting, ink smears, and physical margins change based on IntegrationDebt. |
| **Camp** | *"How are we doing?"* | Spatial view of Garrett cleaning traps, Serafina reading, and Kaelen at the fire. Selecting a companion opens their relational profile. |
| **Equipment** | *"What am I carrying?"* | Physical 3D inspection. Rotate weapons/armor to inspect soot, scratches, alchemical stains, or notes carved into leather. |
| **Memory Constellation** | *"Why am I like this?"* | 3D celestial map. Nodes pulse, rotate, and zoom. Shows memory provenance and evidence packs without text walls. |
| **Heartstone Sanctuary** | *"Who do I become next?"* | Sacred, alive interface. Floating ash, white flame, and memory fragments with zero UI chrome. |
| **Reflection Timeline** | *"How did we get here?"* | A chronological spine of key narrative milestones, showing companion reactions and unlocked mechanics at each node. |

#### ---

**2\. Diegetic Journal Evolution & Companion Contributions**

The journal is an active artifact that reflects Kaelen’s mental integration in real time.

                   ┌────────────────────────────────────────┐  
                   │       EARLY GAME: HIGH DEBT / NOISE    │  
                   │ • Jagged, erratic handwriting          │  
                   │ • Crossed-out lines and ink blots      │  
                   │ • Margins stained with ash & bile      │  
                   └───────────────────┬────────────────────┘  
                                       │  
                                       ▼  
                   ┌────────────────────────────────────────┐  
                   │    LATE GAME: RECOGNITION & CLARITY    │  
                   │ • Firm, measured script                │  
                   │ • Clean margins & pressed flora        │  
                   │ • Marginalia notes from companions     │  
                   └────────────────────────────────────────┘

##### **Companion Marginalia Examples:**

* **Garrett’s Note (Penciled in margin near a combat entry):***"You charged again today. You thought I didn't notice. I did. Let the trap do the bleeding next time."*  
* **Serafina’s Note (Inscribed in fine ink near a memory entry):***"The corruption receded after you accepted help at the bridge. That matters more than you realize."*

#### ---

**3\. Qualitative Interpretation vs. Raw Spreadsheets**

To prevent psychology from turning into numerical spreadsheets, raw C++ float variables in FSoulStateVector are rendered as qualitative narrative states on the top layer, with exact numbers hidden behind an optional inspection layer.

┌──────────────────────────────────────────────────────────────────────────┐  
│ \[RAW C++ ENGINE STATE\]  │ \[PSYCHOLOGICAL OS DISPLAY (TOP LAYER)\]          │  
├─────────────────────────┼────────────────────────────────────────────────┤  
│ IntegrationDebt \= 0.78f │ Mind State: Fracturing (High Static Noise)     │  
│ Resolve \= 0.85f         │ Character Stance: Unshakeable / Resolute       │  
│ Isolation \= 0.12f       │ Relational Anchor: Connected                   │  
│ GarrettTrust \= 0.90f    │ Tactical Synergy: Synchronized / In Lockstep   │  
└─────────────────────────┴────────────────────────────────────────────────┘

#### ---

**4\. Memory Provenance & Evidence Pack Layout**

When inspecting a memory node within the **Memory Constellation**, the UI displays the memory's structural provenance rather than a wiki entry:

┌──────────────────────────────────────────────────────────────────────────┐  
│ \[MEMORY IMPRINT: SILENT SPIRE\]                                           │  
│                                                                          │  
│ Status: Integrated through the Lens of Grace                             │  
│ Relational Impact: Garrett (Attuned) | Serafina (Synchronized)           │  
│ Active Trait Influences: Protective Fatalism, Symbiotic Aegis            │  
│                                                                          │  
│ NARRATIVE PROVENANCE                                                     │  
│ • Referenced in 18 dialogue threads                                      │  
│ • Generated 5 active combat whispers                                     │  
│ • Integrated across 2 Heartstone reflection cycles                       │  
└──────────────────────────────────────────────────────────────────────────┘

### ---

**Why**

Reframing the interface as a **Psychological Operating System** ensures that navigation remains an immersive narrative experience. By replacing numerical spreadsheets with qualitative states, physical 3D object inspection, and living journal entries, every menu choice reinforces the core theme of *Where Light Fades*: **The player is not leveling up stats—they are helping Kaelen understand himself.**

## ---

---

**Honest Thoughts**

Adopting Sophia's "one question per screen" rule cleans up the entire design. Framing the interface around Kaelen's physical journal, a spatial camp, and qualitative psychological states keeps the complex backend math (FSoulStateVector, Memory Palace graph) fully functional while keeping the player immersed in the dark fantasy world.

**ISO Timestamp:** 2026-08-05T18:08:49Z