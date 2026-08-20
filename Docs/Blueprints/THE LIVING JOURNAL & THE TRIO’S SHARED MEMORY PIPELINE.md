# **GAME DESIGN DOCUMENT: VERTICAL SLICE (v3.0 \- DEFINITIVE EDITION)**

## **SYSTEM: THE LIVING JOURNAL & THE TRIO’S SHARED MEMORY PIPELINE**

**PROJECT:** *Ashen Oath*

**TARGET ARCHITECTURE:** Unreal Engine 5.8 C++ (Source/AshenOath)  
**MILESTONE ALIGNMENT:** Master Milestone 1015 / Milestone 1000 Capstone Standards  
**GOVERNING SPECIFICATIONS:** PHOENIX CODEX (v4.5+), UMB-UI-004, UMB-INT-001

## **1\. EXECUTIVE SUMMARY & SYSTEMIC PURPOSE**

### **1.1 The Core Thesis**

In traditional action-RPGs, companion relationships and player memories are represented through static UI menus, affinity meters, and isolated codex logs. *Ashen Oath* rejects this paradigm.  
The **Living Journal** is not a menu; it is an in-world, physical artifact that serves as the **diegetic convergence point** for the entire game’s psychological and relational architecture. It translates raw C++ combat data, narrative choices, and party trust dynamics into a lived, multi-perspective record of human experience.

┌─────────────────────────────────────────────────────────────────────────────┐  
│                          THE DIEGETIC CONVERGENCE                           │  
│                                                                             │  
│  NOT THIS:                                                                  │  
│  \[ Menu Screen \] \-\> "Garrett Trust: 75/100" \-\> "Unlocks \+10% Posture Dmg"   │  
│                                                                             │  
│  BUT THIS:                                                                  │  
│  \[ Living Journal \] \-\> Garrett's Hand-Drawn Sketch over Ash Walker Entry \-\> │  
│  "Don't attack the shoulders. Wait for the left-foot plant."                │  
└─────────────────────────────────────────────────────────────────────────────┘

### **1.2 The Five Design Laws**

> 1. **The Journal Is a View, Not a Database:** The C++ Memory Palace (UAshenOath\_ImprintBufferComponent & USoulConstellationSubsystem) remains the sole authoritative source of truth. The journal observes and interprets the state—it does not own it.  
> 2. **Record of Relationship, Not Stat Reward:** Companions do not write in the journal because Trust \>= 80\. They write because an event occurred between them that forced an expression. Trust merely influences *how, where, in what tone, and whether* they write.  
> 3. **Psychological Unreliability vs. Mechanical Honesty:** The journal’s parchment, ink, and handwriting may visually distort to reflect Kaelen’s mental deterioration, but it will **never lie** about actionable game state, inventory counts, or frame data.  
> 4. **Discovered Perspectives, Not Database Spreadsheets:** The player does not open the book to a side-by-side three-column spreadsheet. The main page is Kaelen's lived experience; Garrett's tactical notes and Serafina's spiritual interpretations are physical artifacts tucked into margins, folded beneath pressed flora, or scrawled over old text to be discovered through page examination.  
> 5. **Interpretation Is Evidence, Not Authority:** The journal never automatically designates one character's interpretation as psychologically or factually correct. The system knows what objectively happened. The characters know what they experienced. The player decides what it means, and that decision shapes future action.

## **2\. ARCHITECTURAL PIPELINE & DEFERRED-COMPILATION EVENT FLOW**

The system operates as an **event-driven, deferred-compilation pipeline** bridging live combat gameplay with Heartstone campfire compilation.

                 ASHEN GENESIS / WHERE LIGHT FADES  
                              │  
                              ▼  
                    CANONICAL GAME EVENTS  
                              │  
                              ▼  
                     MEMORY / SOUL STATE  
                              │  
              ┌───────────────┼────────────────┐  
              ▼               ▼                ▼  
          GAMEPLAY        COMPANIONS         AUDIO  
              │               │                │  
              └───────────────┼────────────────┘  
                              ▼  
                     PSYCHOLOGICAL IMPRINT  
                              │  
                              ▼  
                       HEARTSTONE REST  
                              │  
                              ▼  
                    MECHANICAL RECONCILIATION  
                    (Canonical Immutable Data)  
                              │  
                              ▼  
                   INTERPRETIVE RECONCILIATION  
                    (Contested Perspectives)  
                              │  
                              ▼  
                     ┌─────────────────┐  
                     │  LIVING JOURNAL │  
                     └────────┬────────┘  
                              │  
          ┌───────────────────┼──────────────────┐  
          ▼                   ▼                  ▼  
       Kaelen              Garrett            Serafina  
       memory              tactics            meaning  
          │                   │                  │  
          └───────────────────┼──────────────────┘  
                              ▼  
                     PLAYER OBSERVATION  
                              │  
                              ▼  
                     PLAYER INTERPRETATION  
                              │  
                              ▼  
                    DIFFERENT FUTURE ACTION

### **The Interpretive Feedback Loop**

> 1. **Canonical Event:** The engine determines what happened, who was present, damage dealt, actions taken, and psychological imprints.  
> 2. **Mechanical Reconciliation:** Immutable C++ data is logged to the Memory Palace (UAshenOath\_ImprintBufferComponent).  
> 3. **Interpretive Reconciliation:** The system determines how each character currently understands that event. These interpretations remain contested and can evolve over time.  
> 4. **Player Observation & Behavior:** The player reads the competing perspectives, forms their own interpretation, and alters their combat or narrative choices in response.

## **3\. CORE GAMEPLAY MECHANICS & THE TRIO’S MENTAL MODELS**

### **3.1 Provenance & Multi-Model Perspectives**

Journal entries carry **provenance**—the system remembers *why* a perspective exists back to its underlying C++ imprint and combat telemetry.  
Instead of forcing a single canonical interpretation, every major experience recorded in the Memory Palace carries **competing interpretations** alongside the raw canonical facts.

\+-----------------------------------------------------------------------------------+  
| PAGE 24: THE BLACKWOOD BRIDGE CONFRONTATION                                       |  
|                                                                                   |  
| CANONICAL FACT (Engine Truth):                                                    |  
| \- 3 Ash Walkers slain. Garrett sustained a left shoulder wound.                   |  
| \- Kaelen held western approach. Serafina cast Radiant Purge.                      |  
|                                                                                   |  
| ───────────────────────────────────────────────────────────────────────────────── |  
|                                                                                   |  
| \[KAELEN'S BASE ENTRY \- Main Page (Shaky, Jagged Ink)\]                             |  
| "Blackwood Bridge. The mist was thick with the scent of burning pine. Three Ash   |  
|  Walkers emerged. I failed to protect them."                                      |  
|                                                                                   |  
| \[GARRETT'S MARGINALIA \- Left Margin (Scrawled in Charcoal)\]                       |  
| "No. You held the line long enough for us to retreat."                            |  
|                                                                                   |  
| \[SERAFINA'S ANNOTATION \- Written in Eldorian Ink Beneath Garrett's Note\]          |  
| "You were afraid."                                                                |  
|                                                                                   |  
| \[KAELEN'S SECONDARY RESPONSE \- Scratched below Serafina's Note\]                  |  
| "I wasn't."                                                                       |  
|                                                                                   |  
| \[SERAFINA'S REBUTTAL\]                                                             |  
| "You were."                                                                       |  
\+-----------------------------------------------------------------------------------+

### **3.2 Dynamic Relationship-Driven Marginalia Evolution**

Companion writing changes organically over the course of the campaign based on shared combat experiences and pairwise trust ratings (EAshenOathTrustBand):

#### **Garrett Alerion (Tactics & Survival)**

* **Early Game / Guarded Trust:** Purely technical, distant notes.*"Two came from the western approach. You missed the third."*

* **Mid Game / High Friction (Unchained Overuse):** Heavy, aggressive charcoal strokes.*"You're swinging like a blind man when the black flame takes you. You almost died."*

* **Late Game / Synchronized Trust:** Respectful, companionable observations.*"You held the bridge. And this time you let us help."*

#### **Serafina (Meaning & Spiritual Integrity)**

* **Early Game / Guarded Trust:** Formal Eldorian script, cautious interpretation.*"The corruption grew stronger tonight."*

* **Mid Game / High Friction:** Ink bleeds over Kaelen's dark entries; pressed flowers are removed.*"It became stronger when you believed you had to face it alone."*

* **Late Game / Synchronized Trust:** Protective runes written across Kaelen's trauma text.*"You don't have to carry everything yourself."*

### **3.3 Dynamic Mechanics: "Revisited Memories"**

Pages in the Field Journal are **not static snapshots**; they are living entries that record the history of how Kaelen's self-understanding changed over time.

\+-----------------------------------------------------------------------------------+  
| PAGE 08: THE FALL OF OAKHAVEN (Revisited in Act III)                              |  
|                                                                                   |  
| \[ORIGINAL ENTRY \- ACT I (Dark, Heavy Pressure Marks)\]                             |  
| "Elara is dead. I failed her. The Light has abandoned me."                        |  
|                                                                                   |  
| Garrett (Act I Note): "You couldn't save her, Kaelen."                            |  
| Serafina (Act I Note): "The Shadow took her, not you."                            |  
|                                                                                   |  
| ═════════════════════════════════════════════════════════════════════════════════ |  
|                                                                                   |  
| \[REVISITED COMPILATION \- ACT III (Compiled via Grace Lens at Heartstone)\]         |  
| "I re-read this page today. I don't remember whether I was afraid. I only know    |  
|  I could not save everyone."                                                     |  
|                                                                                   |  
| Garrett (Act III Note): "You finally stopped blaming yourself for the dead."      |  
| Serafina (Act III Note): "That is not the same thing as forgetting them."         |  
\+-----------------------------------------------------------------------------------+

### **3.4 Direct Gameplay Teaching & Shared Competence**

Rather than granting flat \+10% Posture Damage stat bonuses, companion marginalia **teaches the player actual game mechanics and frame data**.

┌─────────────────────────────────────────────────────────────────────────────┐  
│ GARRETT'S FIELD NOTE: ASH WALKER ELITE                                      │  
│                                                                             │  
│ \[SKETCH OF ASH WALKER RIB CAGE WITH ANNOTATED ARROWS\]                       │  
│                                                                             │  
│ "Don't attack the shoulders. Wait for the left-foot plant.                  │  
│  That's when the rib plate opens."                                          │  
│                                                                             │  
│ GAMEPLAY FEEDBACK LOOP:                                                     │  
│ 1\. Player reads note and learns the left-foot plant animation frame\[cite: 27\].   │  
│ 2\. Player exploits the opening in combat\[cite: 27\].                              │  
│ 3\. Journal updates post-combat: "Garrett was right about the left foot."    │  
│ 4\. Next time player opens the guard, Garrett automatically executes a       │  
│    flanking strike without needing a command.                      │  
│ 5\. Journal records: "You saw it before I did this time."\[cite: 27\]                │  
└─────────────────────────────────────────────────────────────────────────────┘

## **4\. SOMATIC PRESENTATION & UX CONSTRAINTS**

The physical behavior of the journal serves as a direct reflection of Kaelen's physical and mental health (UAshenSomaticPresentationController):

\+-----------------------------------------------------------------------------------+  
|                         SOMATIC JOURNAL BEHAVIOR MATRIX                           |  
\+------------------------------------+----------------------------------------------+  
| GAMEPLAY STATE                     | DIEGETIC JOURNAL PRESENTATION                |  
\+------------------------------------+----------------------------------------------+  
| High Sanity / Unbroken Willpower   | Clean parchment, steady script, crisp page   |  
|                                    | turns, bright white flora pressed in margin.|  
\+------------------------------------+----------------------------------------------+  
| High Corruption (C \>= 0.70)        | Ash stains on paper borders, dark vein-creep |  
|                                    | shader crawl, ink bleeding through pages.    |  
\+------------------------------------+----------------------------------------------+  
| Acute Sanity Collapse (\< 15%)      | Shaky/jagged handwriting, words aggressively |  
|                                    | crossed out, incomplete sentences, duplicate  |  
|                                    | descriptions of same event.             |  
\+------------------------------------+----------------------------------------------+  
| Heavy Physical Trauma / Exhaustion | Page-turn animation hesitates, paper crinkles|  
|                                    | with low-pass audio muffling.         |  
\+------------------------------------+----------------------------------------------+

### **Strict UX Constraints (No Bad UX)**

To maintain the non-negotiable rule of **Mechanical Honesty**:

* **ALLOWED:** Visual distortions, handwriting jitter, crossed-out narrative text, ash/vein decals, duplicate perspective entries.  
* **FORBIDDEN:** Falsifying inventory counts, hiding active quest markers, misrepresenting stamina costs, or fabricating game state.

## **5\. TECHNICAL SPECIFICATION (C++ & UMG ARCHITECTURE)**

### **5.1 System Class Overview**

Source/AshenOath/  
├── Narrative/  
│   ├── AshenJournalTypes.h                          \<-- Dynamic Perspective Array Structs  
│   ├── AshenDiegeticJournalSubsystem.h/.cpp         \<-- World Subsystem Manager  
│   ├── AshenMemoryReconciliationEngine.h/.cpp       \<-- Mechanical vs Interpretive Engine  
│   └── AshenFieldJournalPageController.h/.cpp       \<-- Page & Marginalia Controller  
│  
├── UI/  
│   ├── AshenUserWidget\_DiegeticFieldJournal.h/.cpp  \<-- Master UMG Journal Widget  
│   ├── AshenCompanionInterfaceAnnotationComponent.h \<-- Companion Sketch/Rune Component  
│   └── AshenSomaticPresentationController.h/.cpp    \<-- Ink Bleed & Wobble Controller  
│  
└── World/  
    └── AshenParchmentMaterialParameterModulator.h/.cpp \<-- MPC Material Scalar Driver

### **5.2 Header Specification: AshenJournalTypes.h**

C++  
\#**pragma** once

\#**include** "CoreMinimal.h"  
\#**include** "UObject/NoExportTypes.h"  
\#**include** "AshenJournalTypes.generated.h"

UENUM(BlueprintType)  
enum class EJournalEventType : uint8  
{  
    NewEntryCompiled,  
    CompanionMarginaliaAdded,  
    MemoryRevisitedAndReframed,  
    PsychologicalDistortionApplied  
};

USTRUCT(BlueprintType)  
struct FJournalPerspective  
{  
    GENERATED\_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    FName AuthorName; // e.g., "Kaelen", "Garrett", "Serafina", "Elder Valerius"

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    FText InterpretationText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    float EmotionalStateValence;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    FName TrustContext;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    FDateTime Timestamp;  
};

USTRUCT(BlueprintType)  
struct FJournalEvent  
{  
    GENERATED\_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    FGuid SourceImprintGuid;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    FName MemoryNodeID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    EJournalEventType EventType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    FText CanonicalFactText;

    // Dynamic Array supporting evolving and multi-author perspectives  
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    TArray\<FJournalPerspective\> Perspectives;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    uint8 ActiveLensIndex; // 0: Accountability, 1: Grace, 2: Utility

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen Oath|Journal")  
    float KaelenSanityAtTimeOfWriting;  
};

DECLARE\_DYNAMIC\_MULTICAST\_DELEGATE\_OneParam(FOnJournalEventDispatched, const FJournalEvent&, JournalEvent);

### **5.3 C++ Subsystem Implementation: UAshenDiegeticJournalSubsystem**

C++  
// Source/AshenOath/Narrative/AshenDiegeticJournalSubsystem.h  
\#**pragma** once

\#**include** "CoreMinimal.h"  
\#**include** "Subsystems/WorldSubsystem.h"  
\#**include** "AshenJournalTypes.h"  
\#**include** "AshenDiegeticJournalSubsystem.generated.h"

UCLASS()  
class ASHENOATH\_API UAshenDiegeticJournalSubsystem : public UWorldSubsystem  
{  
    GENERATED\_BODY()

public:  
    UPROPERTY(BlueprintAssignable, Category \= "Ashen Oath|Journal")  
    FOnJournalEventDispatched OnJournalEventDispatched;

    UFUNCTION(BlueprintCallable, Category \= "Ashen Oath|Journal")  
    void DispatchJournalEvent(const FJournalEvent& Event);

    UFUNCTION(BlueprintPure, Category \= "Ashen Oath|Journal")  
    TArray\<FJournalEvent\> GetJournalHistoryForNode(FName MemoryNodeID) const;

private:  
    UPROPERTY()  
    TArray\<FJournalEvent\> JournalEventHistory;  
};

C++  
// Source/AshenOath/Narrative/AshenDiegeticJournalSubsystem.cpp  
\#**include** "Narrative/AshenDiegeticJournalSubsystem.h"

void UAshenDiegeticJournalSubsystem::DispatchJournalEvent(const FJournalEvent& Event)  
{  
    JournalEventHistory.Add(Event);  
      
    // Broadcast downstream to UI, Companion AI, and Audio Modulators  
    if (OnJournalEventDispatched.IsBound())  
    {  
        OnJournalEventDispatched.Broadcast(Event);  
    }  
}

TArray\<FJournalEvent\> UAshenDiegeticJournalSubsystem::GetJournalHistoryForNode(FName MemoryNodeID) const  
{  
    TArray\<FJournalEvent\> MatchingEvents;  
    for (const FJournalEvent& Event : JournalEventHistory)  
    {  
        if (Event.MemoryNodeID \== MemoryNodeID)  
        {  
            MatchingEvents.Add(Event);  
        }  
    }  
    return MatchingEvents;  
}

## **6\. QA AUTOMATION & TEST MATRICES**

To guarantee zero regression across builds, this system includes dedicated ProductFilter C++ Automation Tests (FAutomationTestBase).

### **6.1 Test Suite Overview: AshenLivingJournalAutomationTest.cpp**

C++  
\#**include** "Misc/AutomationTest.h"  
\#**include** "Narrative/AshenDiegeticJournalSubsystem.h"  
\#**include** "UI/AshenCompanionInterfaceAnnotationComponent.h"

IMPLEMENT\_SIMPLE\_AUTOMATION\_TEST(FAshenLivingJournalEventDispatchTest,   
    "AshenOath.Journal.EventDrivenProjection.DispatchAndBroadcasting",   
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FAshenLivingJournalEventDispatchTest::RunTest(const FString& Parameters)  
{  
    UWorld\* World \= UWorld::CreateWorld(EWorldType::None, false, "JournalTestWorld");  
    TestNotNull("World Creation", World);

    UAshenDiegeticJournalSubsystem\* JournalSubsystem \= World-\>GetSubsystem\<UAshenDiegeticJournalSubsystem\>();  
    TestNotNull("Journal Subsystem Exists", JournalSubsystem);

    bool bEventReceived \= false;  
    JournalSubsystem-\>OnJournalEventDispatched.AddLambda(\[\&bEventReceived\](const FJournalEvent& Event) {  
        bEventReceived \= true;  
    });

    FJournalEvent TestEvent;  
    TestEvent.MemoryNodeID \= "MEMORY\_TEST\_NODE";  
      
    FJournalPerspective KaelenPerspective;  
    KaelenPerspective.AuthorName \= "Kaelen";  
    KaelenPerspective.InterpretationText \= FText::FromString("Test Interpretation");  
    TestEvent.Perspectives.Add(KaelenPerspective);

    JournalSubsystem-\>DispatchJournalEvent(TestEvent);

    TestTrue("Event Dispatched and Broadcasted Successfully", bEventReceived);  
    TestEqual("Event History Logged", JournalSubsystem-\>GetJournalHistoryForNode("MEMORY\_TEST\_NODE").Num(), 1);

    World-\>DestroyWorld(false);  
    return true;  
}

## **7\. SUMMARY FOR DEVELOPMENT TEAMS**

| Team / Role | Direct Actionable Focus |
| :---- | :---- |
| **System Lead / Tech Director** | Implement FJournalPerspective dynamic array struct & UAshenDiegeticJournalSubsystem. Keep Memory Palace authoritative and journal downstream. |
| **Narrative Lead** | Write multi-perspective text entries (Fact, Kaelen, Garrett, Serafina) and contesting revisions for all key encounters rather than single codex summaries. |
| **UI / Slate Developer** | Construct UAshenUserWidget\_DiegeticFieldJournal UMG widget with multi-layered text boxes, margin slots, hidden discovery folds, and handwriting wobble parameters\[cite: 26, 27\]. |
| **VFX / Tech Artist** | Set up UAshenParchmentMaterialParameterModulator MPC scalars for dynamic ink bleed, ash stains, and vein-creep paper overlays\[cite: 26, 27\]. |
| **Game Designer** | Replace flat stat perks with actionable tactical notes written by Garrett (weak-point frame data) and Serafina (lore & rune seals)\[cite: 26, 27\]. |

## **8\. HONEST THOUGHTS**

The evolution from v2.0 to v3.0 achieves something rare in game architecture: **it aligns the technical implementation perfectly with the core narrative theme.**  
By separating *Mechanical Reconciliation* (what happened) from *Interpretive Reconciliation* (what it meant) and making perspectives an expandable array (TArray\<FJournalPerspective\>), we solved the C++ header issue and opened up the system for dynamic, multi-author storytelling.  
The journal is no longer just documenting the game—it is demonstrating that identity itself is a living, evolving interpretation\[cite: 26, 27\]. The C++ headers are clean, the event pipeline is deferred and decoupled, and the vertical slice design is complete\[cite: 26, 27\].