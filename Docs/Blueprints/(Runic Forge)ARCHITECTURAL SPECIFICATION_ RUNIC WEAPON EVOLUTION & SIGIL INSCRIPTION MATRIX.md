# **RUNIC-FORGE-SPEC-098-PROD**

# **ARCHITECTURAL SPECIFICATION: RUNIC WEAPON EVOLUTION & SIGIL INSCRIPTION MATRIX**

**Document ID:** `RUNIC-FORGE-SPEC-098-PROD`

**V-Control:** `2026-08-30T08:30:00-04:00`

**Primary Index:** `PRS-001 / RUNIC-FORGE-SPEC-098`

**Architecture Alignment:** `CONTRACT-SPEC-051` / `FSoulStateVector` / `TAM-001` / `UMB-UI-004` / `ENGINE-SPEC-001`

**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS)

**Status:** Canonical / Hardened Production Blueprint

---

┌─────────────────────────────────────────────────────────────────────────────────────────────┐

│                       THE UNIFIED SOUL-TO-BLADE EVOLUTION PIPELINE                          │

│                                                                                             │

│   \[Trauma Imprint\] ──► \[Hearthside Compilation\] ──► \[FSoulStateVector Commit\]                │

│                                                            │                                │

│   ┌────────────────────────────────────────────────────────┴────────────────────────────┐   │

│   ▼                                                     ▼                               ▼   │

│ \[Blade Morphology\]                                \[Stance Loci\]                 \[Blade Hunger\]│

│ (Fuller / Quillons)                               (Liechtenauer)                (Parasite)  │

└─────────────────────────────────────────────────────────────────────────────────────────────┘

---

## **🏛️ SECTION I: Executive Thesis & Ontological Foundation**

### **1\. The Anti-Arcade Loot Mandate**

Standard action-RPGs treat weapon upgrades as an extrinsic economy of arbitrary mineral grinding (e.g., iron ore, titanite, sulfur) and abstract statistical inflation ($+5\\text{ Strength}$).

`RUNIC-FORGE-SPEC-098` rejects this paradigm completely under **Axiom I (Single Source of Truth)** and **Universal Law III (Conservation of Consequence)**:

> **"Everything is Memory. Everything is Interpretation. The sword does not level up—the sword is the physical scar of how Kaelen interprets his suffering."**

*Oathbringer* is an ancient, sentient nightsteel reliquary housing the remorseful ghost of **Eldrin** and the predatory void of the **Shadow Self**. It cannot be improved through ordinary blacksmithing. Its physical shape, fuller luminescence, quillon configuration, and blade hunger are downstream projections of Kaelen's compiled `FSoulStateVector`.

---

## **🗡️ SECTION II: The 5-Tier Morphological Blade Ascension Pipeline**

┌─────────────────────────────────────────────────────────────────────────────────────────────┐

│                           5-TIER BLADE ASCENSION PROGRESSION                                │

│                                                                                             │

│  \[Tier 1: Burdened Iron\] ──► \[Tier 2: Resonant Fuller\] ──► \[Tier 3: Sundered Sovereign\]     │

│                                                                    │                        │

│                                  \[Tier 5: Zenith Sovereign\] ◄──────┴──► \[Tier 4: Crucible\]   │

└─────────────────────────────────────────────────────────────────────────────────────────────┘

The greatsword evolves across five canonical tiers governed by the `UAshenBladeAscensionEvaluator`. Each tier transition requires a specific psychological milestone within the Soul Constellation kernel:

| Tier | Canonical Name | Narrative / Metaphysical State | `FSoulStateVector` Unlock Criteria | Visual & Mechanical Morphology |
| :---- | :---- | :---- | :---- | :---- |
| **Tier 1** | **The Burdened Iron** *(Dull Nightsteel)* | Dormant, chipped nightsteel. Eldrin’s spirit sleeps beneath heavy oxidation; the Shadow Self is a cold, dormant weight. |  |  |

| Default Prologue State ($D \= 0.0, R \= 0.50$).

| • 1 Quillon Socket active (*Vom Tag*)

• Standard Vanguard combo chains

• Zero Fuller Emissive.

| | **Tier 2** | **The Resonant Fuller** *(Awakened Seam)* | The central fuller fractures open. Eldrin’s suppressed memories begin leaking into Kaelen's subconscious.

| $\\text{IntegrationDebt} \\ge 0.25$

1 Sanctum Memory Compiled.

| • Unlocks Socket 2 (*Pflug*)

• $+25%$ Flow Meter capacity

• Fuller pulses pale cyan (`0.2, 0.85, 0.95`).

| | **Tier 3** | **Sundered Sovereign** *(Quad-Socket Ring)* | The crossguard unfolds into four distinct historical socket rings. Kaelen is stabilized by his companions.

| $\\text{TrioResonance} \\ge 0.65$

$\\text{Trust\_Garrett} \\ge 0.60$

$\\text{Trust\_Serafina} \\ge 0.60$  
 | • Unlocks Socket 3 (*Ochs*) & 4 (*Mordhau*)

• Enables **Dual-Sigil Hybrid Finishers**

• Crossguard width expands $+15%$.

| | **Tier 4** | **Eldrin's Crucible** *(Thermal Slag Seam)* | Garrett hammers alchemical conduits into the fuller, binding ash-soot directly into the steel.

| $\\text{Corruption} \\ge 0.50$

$\\text{Resolve} \\ge 0.70$

`Resolution.BifurcatedWill`  
 | • Converts Blade Hunger into **Superheated Slag**

• $+40%$ Poise Break Multiplier

• Thermal Seam (`MPC_ThermalSlag`).

| | **Tier 5** | **Zenith Sovereign** *(The Sovereign Ascended)* | Symbiotic equilibrium between Kaelen, Eldrin, and the White Flame. Nightsteel turns to incandescent crystal.

| $\\text{Resolve} \\ge 0.90$

$\\text{IntegrationDebt} \= 0.0$

`Resolution.WhiteFlameResolution`  
 | • Uninterrupted Flow State HyperArmor

• $2.0\\times$ Finisher Burst Multiplier

• Transcendent White-Gold Crystal Edge.

|

---

## **🥋 SECTION III: The 4 Liechtenauer Guard Sockets & Ontological Lenses**

Sockets are not physical holes drilled for gems; they are **Martial Memory Loci** carved into the crossguard and pommel. They represent historical longsword postures (*Kunst des Fechtens*) re-architected through Kaelen's psychological survival strategies:

                                 \[ BLADE TIP \]

                                       │

                      (OCHS) ┌─────────┴─────────┐ (VOM TAG)

                 Left Quillon│    \[CROSSGUARD\]   │ Right Quillon

                (White Flame)│    \[Wolf-Head\]    │ (Fiery Ochre)

                             └─────────┬─────────┘

                                       │ \[GRIP\]

                      (PFLUG) ┌────────┴─────────┐ (MORDHAU)

                  Lower Guard│                   │ Pommel Core

                 (Zephyr/Air)│     \[POMMEL\]      │ (Void Violet)

                             └───────────────────┘

### **1\. Stance 1: Vom Tag (Roof Guard) — *Colossus Rupture***

* **Biomechanical Posture:** Both hands raised above the right shoulder; blade angled back at $45^\\circ$. Upright, imposing silhouette primed for downward gravitational cleavage.  
    
* **Ontological Lens Binding:** **Wrath (Utility)** — *"If I strike hard enough, they can never hurt us again."*  
    
* **Mechanical Expression:** Downward cleaves release a **$600,\\text{uu}$ radial shockwave**, launching light skirmishers into juggle states and breaking heavy frontal shields.  
    
* **Diegetic Shader:** Fuller flares **Molten Ember Orange** (`R=0.95, G=0.35, B=0.05`).

### **2\. Stance 2: Pflug (Plow Guard) — *Zephyr Gale***

* **Biomechanical Posture:** Sunk low into a deep forward fencer's lunge; pommel braced at the right hip with the 5-foot point leveled directly at the opponent's throat.  
    
* **Ontological Lens Binding:** **Trust (Grace)** — *"I hold the line low to open the flank for my brother."*  
    
* **Mechanical Expression:** High-velocity thrusts generate an **$800,\\text{uu}$ inward vacuum cone**, pulling evasive skirmishers into melee range and staggering backline casters.  
    
* **Diegetic Shader:** Fuller swirls **Gale Cyan** (`R=0.20, G=0.85, B=0.95`).

### **3\. Stance 3: Ochs (Window Guard) — *Aegis Pyre***

* **Biomechanical Posture:** Hands held high at eye level; the crossguard acts as a physical viewport and shield window while the tip points downward toward the opponent's face.  
    
* **Ontological Lens Binding:** **Accountability (Defiance)** — *"I will hold this ground with clean hands and unyielding discipline."*  
    
* **Mechanical Expression:** High-guard parries release a burst of White Flame, dealing **$200$ Holy Poise Damage** to attackers and purging **$10.0$ points of accumulated Sanity/Taint decay**.  
    
* **Diegetic Shader:** Fuller radiates **White Gold** (`R=1.00, G=0.90, B=0.40`).

### **4\. Stance 4: Mordhau (Murder-Stroke) — *Gravimetric Rupture***

* **Biomechanical Posture:** Kaelen reverses his grip, seizing the steel blade with armored gauntlets to strike with the heavy crossguard and wolf-head pommel like a war hammer.  
    
* **Ontological Lens Binding:** **Defiance (Martyrdom)** — *"I will break my hands against the iron before I surrender."*  
    
* **Mechanical Expression:** Blunt pommel strikes grant **$100%$ armor penetration**, instantly shattering heavy plate armor and calcified basalt carapaces.  
    
* **Diegetic Shader:** Pommel core pulses **Void Violet** (`R=0.60, G=0.10, B=0.90`).

---

## **⚡ SECTION IV: The 0.15s Flow Glint & Relational Synchronization Matrix**

┌─────────────────────────────────────────────────────────────────────────────────────────────┐

│                          RELATIONAL SYNCHRONIZATION FLOW CHART                              │

└─────────────────────────────────────────────────────────────────────────────────────────────┘

                                \[ STANCE SHIFT INPUT \]

                                          │

                                          ▼

                      \[ Quantized 115 BPM Quartz Downbeat \]

                                          │

                                          ▼

                       \[ 0.15s Optical Flow Glint Fires \]

                                          │

                 ┌────────────────────────┴────────────────────────┐

                 ▼ (Trio Within \<= 200uu & Psi \>= 0.75)            ▼ (Isolated / Spacing \> 200uu)

     \[ RELATIONAL HYBRID FINISHER \]                       \[ SOLO STANCE CANCEL \]

     • Garrett Tendon Vault / Serafina Holy Lance         • Standard Damage Profile

     • Clears 25% Integration Debt                        • High Stamina Cost

     • Silences Stem 02 Parasite Audio                    • Accrues Integration Debt

### **1\. Spatial Gating & The 115 BPM Quartz Rhythm**

The **0.15s Flow Glint** is not an arbitrary Quick-Time Event; it represents the moment of **Tripartite Relational Alignment**:

* **Rhythmic Downbeat:** Optical lens flares trigger on the exact **115 BPM Quartz audio beat** when Kaelen shifts stances.  
    
* **Spatial Invariant:** A Relational Hybrid Finisher can **only** be executed if the Trio is within **$200,\\text{uu}$** ($\\text{CompanionProximityFactor} \\ge 0.80$) and $\\Psi\_{\\text{relational}} \\ge 0.75$.  
    
* **The Diegetic Consequence of Isolation:** If Kaelen has pushed Garrett and Serafina to a **$650,\\text{uu}$ buffer** through high Isolation or reckless Dark Mode usage, companions cannot traverse the distance in $0.15\\text{s}$. The glint flashes and fades, locking Kaelen into solo attack recovery.

### **2\. The Dual-Sigil Hybrid Finishers**

// Runtime verification of Hybrid Finisher eligibility

bool UAshenSigilResonanceEvaluator::EvaluateHybridFinisher(

    EGuardSigilSocket StanceA, 

    EGuardSigilSocket StanceB, 

    const FSomaticState& SomaticState,

    FHybridFinisherPayload& OutPayload)

{

    if (SomaticState.RelationalFlow \< 0.75f || SomaticState.IsolationPressure \> 0.40f)

    {

        return false; // Gated by Relational Matrix

    }

    if ((StanceA \== EGuardSigilSocket::VomTag && StanceB \== EGuardSigilSocket::Pflug) ||

        (StanceA \== EGuardSigilSocket::Pflug && StanceB \== EGuardSigilSocket::VomTag))

    {

        OutPayload.FinisherTag \= FGameplayTag::RequestGameplayTag("Ability.Finisher.CataclysmVortex");

        OutPayload.DamageMultiplier \= 1.40f;

        OutPayload.DebtPurgeAmount \= 0.15f;

        return true;

    }

    if ((StanceA \== EGuardSigilSocket::Ochs && StanceB \== EGuardSigilSocket::Mordhau) ||

        (StanceA \== EGuardSigilSocket::Mordhau && StanceB \== EGuardSigilSocket::Ochs))

    {

        OutPayload.FinisherTag \= FGameplayTag::RequestGameplayTag("Ability.Finisher.SovereignSmite");

        OutPayload.DamageMultiplier \= 1.60f;

        OutPayload.PoiseBreakAmount \= 250.0f;

        return true;

    }

    return false;

}

---

## **🩸 SECTION V: The Blade Hunger Subsystem (Parasite Pressure & Seduction)**

┌─────────────────────────────────────────────────────────────────────────────────────────────┐

│                           THE BLADE HUNGER CYCLE (SEDUCTION)                                │

└─────────────────────────────────────────────────────────────────────────────────────────────┘

                                \[ HESITATION / ISOLATION \]

                                            │

                                            ▼

                           \[ ParasitePressure Escalates (0.0 ──► 1.0) \]

                                            │

               ┌────────────────────────────┴────────────────────────────┐

               ▼                                                         ▼

    \[ THE SEDUCTIVE REWARD \]                                  \[ THE CRIPPLING RISK \]

    • Up to \+45% Direct Damage                                • Drains Sanity (-4.0/s)

    • \+50% Poise Break Multiplier                             • \-35% Parry Window Penalty

    • Visceral Armor Shredding                                • L2 Trigger Heartbeat Shudder

    • Stem 02 Audio Seduction                                 • Spacing Expands to 650uu

               │                                                         │

               └────────────────────────────┬────────────────────────────┘

                                            │

                                            ▼

                           \[ FLOW CATHARSIS / SEVERANCE KILL \]

                           • Blade Hunger reset to 0.0

                           • \+40.0 Sanity Restored

                           • Stem 02 Audio Silenced (-24dB)

### **1\. Dynamic Scaling & Faustian Seduction**

Blade Hunger is not an isolated arcade meter; it is the runtime interaction of \*\*$\\text{ParasitePressure}$ and $\\text{IsolationPressure}$ on `FSoulStateVector**`:

$$\\text{DamageBonus} \= \\text{Clamp}(1.0 \+ (\\text{ParasitePressure} \\cdot 0.45), ,, 1.0, ,, 1.45)$$

$$\\text{ParryWindow} \= \\text{BaseParryWindow} \\cdot (1.0 \- (\\text{ParasitePressure} \\cdot 0.35))$$

* **The Seduction:** When Kaelen isolates himself, his attacks hit significantly harder ($+45%$) and crush poise faster ($+50%$). The game mathematically tempts the player to lean into solitary wrath.  
    
* **The Cost:** Starving the blade drains party Sanity ($-4.0/\\text{s}$), shrinks the parry window from $0.20\\text{s} \\to 0.13\\text{s}$, increases dodge stamina by $1.50\\times$, and pushes companions to a defensive $650,\\text{uu}$ spacing.

### **2\. Somatosensory & Acoustic Telemetry**

* **Quartz Stem 02 (Discordant Hum):** As Hunger exceeds $0.50$, the soundtrack's melodic instruments duck by **$-18\\text{dB}$**, replaced by high-pitched ringing, reversed whispering, and discordant cellos.  
    
* **DualSense Trigger Kinetics:** The L2 Guard trigger develops an irregular, rhythmic **cardiac shudder** that increases in frequency as hunger spikes.  
    
* **Shader Seam Creep (`MPC_Oathbringer`):** Dark crimson vein tendrils physically crawl from the crossguard onto Kaelen's gauntlets and plate armor.

---

## **🛠️ SECTION VI: The Tripartite Campfire Metallurgical Ritual**

Weapon evolution occurs exclusively at **Sanctuary Hearths (`AAshenSomaticWeaponAltarActor`)**, turning upgrades into an intimate, cooperative character set-piece:

┌─────────────────────────────────────────────────────────────────────────────────────────────┐

│                           TRIPARTITE METALLURGICAL RITUAL                                   │

├──────────────────────────┬──────────────────────────┬───────────────────────────────────────┤

│ Actor                    │ Mechanical Contribution  │ Narrative & Systemic Provenance       │

├──────────────────────────┼──────────────────────────┼───────────────────────────────────────┤

│ \*\*Garrett Alerion\*\*      │ Cold-Iron Metallurgy     │ Hammers physical conduits into the    │

│ \*(Non-Magical Sentinel)\* │ & Structural Leverage    │ steel; optimizes mechanical leverage  │

│                          │                          │ without using magic\[cite: 4, 11\].    │

├──────────────────────────┼──────────────────────────┼───────────────────────────────────────┤

│ \*\*Serafina\*\*             │ Lorekeeper Transference  │ Chants ancient Eldorian bindings to   │

│ \*(Warden / Empath)\*      │ & Soul-Seam Binding      │ stabilize Eldrin's soul and prevent   │

│                          │                          │ necrotic unravelling\[cite: 3, 4, 11\].│

├──────────────────────────┼──────────────────────────┼───────────────────────────────────────┤

│ \*\*Kaelen Vance\*\*         │ Somatic Heat Anchor      │ Endures the psychological burn of the │

│ \*(The Crucible)\*         │ & Memory Imprint Binding │ trauma imprint being forged directly  │

│                          │                          │ into the blade's fuller\[cite: 1, 4\]. │

└──────────────────────────┴──────────────────────────┴───────────────────────────────────────┘

### **1\. The Living Journal Convergence (`UMB-UI-004`)**

The inscription process generates permanent, multi-author marginalia in the **Living Journal**:

* **Accountability / Ochs Inscription:** Kaelen writes: *"The steel holds what I cannot."* Serafina presses a dried silver leaf over the text; Garrett adds a structural diagram of the crossguard bind.  
    
* **Wrath / Vom Tag Inscription:** The page develops physical charcoal burn vignettes (`UAshenParchmentMaterialParameterModulator`); Garrett notes: *"Hits like a siege ram. Mind your recovery time."*

---

## **💻 SECTION VII: C++ Engine Contracts, Structs & DataAssets**

### **1\. Core Header Types (`AshenRunicForgeTypes.h`)**

\#pragma once

\#include "CoreMinimal.h"

\#include "GameplayTagContainer.h"

\#include "AshenRunicForgeTypes.generated.h"

UENUM(BlueprintType)

enum class EOathbringerAscensionTier : uint8

{

    BurdenedIron        \= 0 UMETA(DisplayName \= "Tier 1: The Burdened Iron"),

    AwakenedFuller      \= 1 UMETA(DisplayName \= "Tier 2: The Resonant Fuller"),

    SunderedSovereign   \= 2 UMETA(DisplayName \= "Tier 3: Sundered Sovereign"),

    EldrinsCrucible     \= 3 UMETA(DisplayName \= "Tier 4: Eldrin's Crucible"),

    ZenithSovereign     \= 4 UMETA(DisplayName \= "Tier 5: Zenith Sovereign")

};

UENUM(BlueprintType)

enum class EGuardSigilSocket : uint8

{

    VomTag   \= 0 UMETA(DisplayName \= "High Guard (Vom Tag)"),

    Pflug    \= 1 UMETA(DisplayName \= "Plow Guard (Pflug)"),

    Ochs     \= 2 UMETA(DisplayName \= "Window Guard (Ochs)"),

    Mordhau  \= 3 UMETA(DisplayName \= "Murder Stroke (Mordhau)")

};

USTRUCT(BlueprintType)

struct FMemoryEchoSocketBinding

{

    GENERATED\_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen|RunicForge")

    FGuid BoundMemoryImprintId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen|RunicForge")

    EOntologicalLens AppliedLens \= EOntologicalLens::Uncompiled;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen|RunicForge")

    EGuardSigilSocket TargetSocket \= EGuardSigilSocket::VomTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category \= "Ashen|RunicForge")

    FGameplayTag GrantedCombatTrait;

};

USTRUCT(BlueprintType)

struct FOathbringerMorphologyState

{

    GENERATED\_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category \= "Ashen|Morphology")

    EOathbringerAscensionTier CurrentTier \= EOathbringerAscensionTier::BurdenedIron;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category \= "Ashen|Morphology")

    float BladeHungerScalar \= 0.0f; // Clamped \[0.0, 1.0\]

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category \= "Ashen|Morphology")

    TMap\<EGuardSigilSocket, FMemoryEchoSocketBinding\> SocketBindings;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category \= "Ashen|Morphology")

    bool bIsFlowGlintActive \= false;

};

### **2\. Balance DataAsset Contract (`UAshenRunicForgeBalanceDataAsset.h`)**

\#pragma once

\#include "CoreMinimal.h"

\#include "Engine/DataAsset.h"

\#include "AshenRunicForgeBalanceDataAsset.generated.h"

UCLASS(BlueprintType)

class ASHENOATH\_API UAshenRunicForgeBalanceDataAsset : public UPrimaryDataAsset

{

    GENERATED\_BODY()

public:

    UPROPERTY(EditDefaultsOnly, Category \= "Timing", meta \= (ClampMin \= "0.05", ClampMax \= "0.30"))

    float FlowGlintWindowSeconds \= 0.15f;

    UPROPERTY(EditDefaultsOnly, Category \= "Damage Multipliers", meta \= (ClampMin \= "1.10", ClampMax \= "2.00"))

    float HybridFinisherDamageMultiplier \= 1.40f;

    UPROPERTY(EditDefaultsOnly, Category \= "Hunger Scaling", meta \= (ClampMin \= "0.0", ClampMax \= "1.0"))

    float MaxHungerDamageBonus \= 0.45f;

    UPROPERTY(EditDefaultsOnly, Category \= "Hunger Scaling", meta \= (ClampMin \= "0.0", ClampMax \= "1.0"))

    float MaxHungerParryPenalty \= 0.35f;

    UPROPERTY(EditDefaultsOnly, Category \= "Sanity Drain", meta \= (ClampMin \= "0.0", ClampMax \= "10.0"))

    float MaxHungerSanityDrainPerSec \= 4.0f;

    UPROPERTY(EditDefaultsOnly, Category \= "Radii", meta \= (ClampMin \= "200.0", ClampMax \= "1500.0"))

    float VomTagShockwaveRadius \= 600.0f;

    UPROPERTY(EditDefaultsOnly, Category \= "Radii", meta \= (ClampMin \= "200.0", ClampMax \= "1500.0"))

    float PflugVacuumRadius \= 800.0f;

};

---

## **🧪 SECTION VIII: Value-Asserting Automation Test Suite**

// Source/AshenOathTests/Private/AshenRunicForgeAutomationTest.cpp

\#include "Misc/AutomationTest.h"

\#include "Combat/AshenRunicForgeEvaluator.h"

\#include "Soul/AshenSoulPublisher.h"

\#include "Combat/AshenRunicForgeBalanceDataAsset.h"

IMPLEMENT\_SIMPLE\_AUTOMATION\_TEST(FAshenRunicForgeEvolutionTest, "AshenOath.Combat.RunicForge.EvolutionAndHunger", 

    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FAshenRunicForgeEvolutionTest::RunTest(const FString& Parameters)

{

    UWorld\* World \= FTestWorldScope::CreateTestWorld();

    UAshenSoulPublisher\* Publisher \= World-\>GetGameInstance()-\>GetSubsystem\<UAshenSoulPublisher\>();

    UAshenRunicForgeEvaluator\* Evaluator \= NewObject\<UAshenRunicForgeEvaluator\>();

    // 1\. Assert Tier 1 Baseline State

    FSoulStateVector SoulState;

    SoulState.IntegrationDebt \= 0.10f;

    SoulState.Resolve \= 0.50f;

    FRelationalMatrix RelMatrix;

    RelMatrix.TrioResonance \= 0.40f;

    Publisher-\>CommitStateDirect(SoulState, RelMatrix);

    EOathbringerAscensionTier CurrentTier \= Evaluator-\>EvaluateAscensionTier(Publisher-\>GetSoulState(), Publisher-\>GetRelationalMatrix());

    TestEqual("Baseline must evaluate to Tier 1: Burdened Iron", CurrentTier, EOathbringerAscensionTier::BurdenedIron);

    // 2\. Mutate to Tier 3 Requirements (TrioResonance \>= 0.65, Trust \>= 0.60)

    RelMatrix.TrioResonance \= 0.70f;

    RelMatrix.Trust\_Garrett \= 0.65f;

    RelMatrix.Trust\_Serafina \= 0.65f;

    Publisher-\>CommitStateDirect(SoulState, RelMatrix);

    CurrentTier \= Evaluator-\>EvaluateAscensionTier(Publisher-\>GetSoulState(), Publisher-\>GetRelationalMatrix());

    TestEqual("Must evaluate to Tier 3: Sundered Sovereign when Trust is compiled", CurrentTier, EOathbringerAscensionTier::SunderedSovereign);

    // 3\. Test Blade Hunger Seduction Scaling

    const float LowHungerDmg \= Evaluator-\>CalculateDamageMultiplier(0.0f);

    const float HighHungerDmg \= Evaluator-\>CalculateDamageMultiplier(1.0f);

    TestEqual("Zero Hunger must yield 1.0x Base Multiplier", LowHungerDmg, 1.0f);

    TestEqual("Max Hunger must yield 1.45x Damage Multiplier", HighHungerDmg, 1.45f);

    // 4\. Test Relational Gating on Hybrid Finishers (Proximity Isolation Failure)

    FSomaticState SomaticState;

    SomaticState.RelationalFlow \= 0.40f; // Low Flow due to Isolation

    SomaticState.IsolationPressure \= 0.70f;

    FHybridFinisherPayload Payload;

    const bool bFinisherAllowed \= Evaluator-\>EvaluateHybridFinisher(

        EGuardSigilSocket::VomTag, 

        EGuardSigilSocket::Pflug, 

        SomaticState, 

        Payload

    );

    TestFalse("Hybrid Finisher must be REJECTED when Kaelen is Isolated", bFinisherAllowed);

    return true;

}

---

## **🎯 SECTION IX: Final Architectural Verification**

`RUNIC-FORGE-SPEC-098-PROD` establishes complete, unbroken ludonarrative cohesion:

1. **Zero Loot Economy:** Eliminates all arbitrary mineral grinding. Progression is strictly gated by **Trauma Imprints, Hearthside Reflection, and Ontological Lenses**.  
     
2. **Diegetic Martial Mastery:** Longsword postures (*Vom Tag, Pflug, Ochs, Mordhau*) serve as the physical embodiment of Kaelen's psychological coping mechanisms.  
     
3. **Spatial Relational Necessity:** The $0.15\\text{s}$ Flow Glint requires physical companion proximity ($\\le 200,\\text{uu}$), ensuring that **fellowship is a mechanical requirement for high-level combat execution**.  
     
4. **The Seduction of Wrath:** Blade Hunger provides immense damage bonuses ($+45%$) at the cost of Sanity and companion trust, mathematically placing the player inside Kaelen's struggle between solitary domination and shared vulnerability.

# **AOP-REWORK-HUNGER-103-PROD**

# **ARCHITECTURAL SPECIFICATION: THE DE-GAMIFICATION OF BLADE HUNGER (PREDATORY MOMENTUM)**

**Document ID:** AOP-REWORK-HUNGER-103-PROD  
**V-Control:** 2026-08-30T08:50:00-04:00  
**Primary Index:** PRS-001 / AOP-REWORK-HUNGER-103

**Architecture Alignment:** CONTRACT-SPEC-051 / FSoulStateVector / TAM-001 / RUNIC-FORGE-SPEC-098 / AOP-COMBAT-SPEC-101

**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / MetaSounds  
**Status:** Canonical / Hardened Production Blueprint

┌─────────────────────────────────────────────────────────────────────────────────────────────┐  
│                           THE PREDATORY MOMENTUM CYCLE                                      │  
│                                                                                             │  
│  \[Hesitation / Spatial Isolation\] ──► \[ParasitePressure Escalates (H \>= 0.60)\]              │  
│                                                     │                                       │  
│          ┌──────────────────────────────────────────┴──────────────────────────┐            │  
│          ▼                                                                     ▼            │  
│  \[KINETIC OVER-SWING & MAGNETISM\]                               \[SOMATIC LOSS OF CONTROL\]   │  
│  • Double Hitbox Cones / Cleave                                 • Recovery Lockout (+0.35s) │  
│  • Skew-Warp Lunge (+120uu toward Blood)                        • L2 Trigger Resistance 220 │  
│  • Armor Shred via Unruly Inertia                               • Soot Tunnel Vision Blur   │  
│          │                                                                     │            │  
│          └──────────────────────────────────────────┬──────────────────────────┘            │  
│                                                     │                                       │  
│                                                     ▼                                       │  
│              \[MARTIAL RE-GROUNDING: CALCULATED DEFERENCE (AOP-101)\]                         │  
│              • Plant into Ochs / Mordhau Bind                                               │  
│              • Companions break frenzy via Tendon Vault / White Flame Lance                 │  
└─────────────────────────────────────────────────────────────────────────────────────────────┘

## **🏛️ SECTION I: Executive Thesis & The Anti-Spreadsheet Mandate**

### **1\. The Death of the "Max-Hunger DPS Build"**

Assigning a flat $+45\\%$ Damage Multiplier and $+50\\%$ Poise Damage bonus to Blade Hunger introduced a severe game design failure: **it transformed a psychological horror into a spreadsheet optimization problem**.  
Players naturally seek peak mechanical efficiency. In a system with pure numerical buffs, players would intentionally starve the blade, isolate Kaelen, and disregard party safety to maximize speed-running damage numbers. This directly contradicts the narrative canon: **the Shadow Self is not a convenient stat buff; it is a predatory parasite that degrades human motor precision, blurs spatial awareness, and drags Kaelen toward biological butchery**.

### **2\. The Core Paradigm Shift: From Stat Inflation to Predatory Momentum**

Under AOP-REWORK-HUNGER-103, escalating ParasitePressure ($H \\ge 0.60$) does not award clean mathematical damage:

* **The Momentum:** The greatsword gains immense kinetic inertia, widening strike arcs, tearing through light enemy guards, and pulling Kaelen's physical body forward through the mud.  
* **The Horror:** The player loses fine defensive agency. Recovery animations lengthen, dodging is locked out during lunges, missed swings bury the blade in the dirt, peripheral vision is choked by dark soot, and companion audio is muffled beneath Eldrin’s low iron rasping.

## **🩸 SECTION II: The 4 Somatic Pillars of Predatory Momentum**

┌─────────────────────────────────────────────────────────────────────────────────────────────┐  
│                             THE 4 SOMATIC HUNGER PILLARS                                    │  
├──────────────────────────┬─────────────────────────────────┬────────────────────────────────┤  
│ Dimension                │ Kinetic & Spatial Behavior      │ Somatosensory & Relational Cost│  
├──────────────────────────┼─────────────────────────────────┼────────────────────────────────┤  
│ \*\*1. Unruly Over-Swing\*\* │ Massive kinetic cleave arc;     │ Recovery frames expand \+0.35s; │  
│ \*(Inertial Cleave)\*      │ breaks frontal light guards     │ Posture over-committed to dirt │  
├──────────────────────────┼─────────────────────────────────┼────────────────────────────────┤  
│ \*\*2. Predatory Magnetism\*\*│ RootMotionSkew pulls Kaelen     │ Cannot cancel into dodge;      │  
│ \*(Violent Gap-Close)\*    │ \+120uu forward into flesh       │ Directional control snapped    │  
├──────────────────────────┼─────────────────────────────────┼────────────────────────────────┤  
│ \*\*3. Somatic Blade Drag\*\*│ Greatsword anchors into ground  │ L2 Adaptive Trigger locks 220; │  
│ \*(Weight & Tremor)\*      │ on missed swing recoveries      │ Poise broken on whiffed timing │  
├──────────────────────────┼─────────────────────────────────┼────────────────────────────────┤  
│ \*\*4. Sensory Blindness\*\* │ Screen perimeter vignettes with │ Companion callouts muffled;    │  
│ \*(The Soot Tunnel)\*      │ heavy dynamic soot shaders      │ AI buffer pushes to 650uu      │  
└──────────────────────────┴─────────────────────────────────┴────────────────────────────────┘

### **1\. Pillar 1: Unruly Over-Swing & Kinetic Cleave**

* **Kinetic Expression:** Attacks do not deal higher base numbers; rather, the physics volume of *Oathbringer's* swing expands by $+60\\%$. The sheer kinetic weight cleaves through multiple overlapping limbs and knocks back light skirmishers in wide $180^\\circ$ arcs.  
* **The Somatic Cost:** Kaelen cannot interrupt his follow-through. His center of gravity collapses forward with the blade’s momentum. **Recovery frames increase by $+0.35\\text{ seconds}$**, leaving his back completely exposed if the strike does not hit flesh.

### **2\. Pillar 2: Predatory Magnetism (Loss of Locomotion Agency)**

* **Kinetic Expression:** Light melee inputs activate URootMotionModifier\_SkewWarp, forcibly pulling Kaelen **$+120\\,\\text{uu}$ forward** directly toward the nearest bleeding adversary.  
* **The Somatic Cost:** The player cannot cancel the lunge into an evasive roll or defensive strafe. The sword physically drags Kaelen's feet across the stone, giving the player the distinct, unsettling sensation that **the weapon is choosing the target, not the knight**.

### **3\. Pillar 3: Somatic Blade Drag & DualSense Cardiac Lock**

* **Kinetic Expression:** If an attack whiffs (misses the target hitbox entirely), the tip of *Oathbringer* embeds directly into the earth/masonry, requiring an explicit $0.40\\text{s}$ un-wedging wrench animation that drains $25\\text{ Stamina}$.  
* **Hardware Telemetry:**  
  * The DualSense **L2 Guard Trigger** increases its baseline stiffness to **$220/255$**.  
  * A continuous, irregular **cardiac rumble** pulses through the left grip, accelerating in cadence as hunger approaches $1.0$.  
  * Raising a defensive guard feels physically exhausting, tactilely pushing the player to swing again just to release the trigger strain.

### **4\. Pillar 4: The Soot Tunnel (Diegetic Sensory Deprivation)**

* **Visual Post-Processing (MPC\_PostProcess\_SootVignette):** As Hunger climbs above $0.60$, the edges of the viewport are choked with thick, churning black soot-smoke shaders. Peripheral enemies and companion positioning indicators are completely obscured.  
* **Quartz Audio Mix:** Battlefield spatialization ducks by **$-14\\text{dB}$**. Companion tactical callouts are replaced by the wet, ragged sound of Kaelen's gasping breath and the discordant, metallic grating of Eldrin's voice rasping through the controller speaker.  
* **Companion Disengagement:** Witnessing Kaelen fight with monstrous, uncoordinated fury forces Garrett and Serafina's AI to pull back to a defensive **$650\\,\\text{uu}$ spatial buffer**, terrified of being caught in his blind over-swings.

## **🥋 SECTION III: Liechtenauer Fencing vs. Desperate Butchery**

┌─────────────────────────────────────────────────────────────────────────────────────────────┐  
│                          STANCE DEGRADATION UNDER BLADE HUNGER                              │  
├───────────────────┬──────────────────────────────────┬──────────────────────────────────────┤  
│ Posture           │ Disciplined Form (H \< 0.40)      │ Predatory Butchery (H \>= 0.60)       │  
├───────────────────┼──────────────────────────────────┼──────────────────────────────────────┤  
│ \*\*Vom Tag\*\*       │ High, balanced over shoulder;    │ Over-torqued violent hammer slam;    │  
│ \*(Roof Guard)\*    │ clean downward recovery│ embeds blade into dirt (+0.40s lock) │  
├───────────────────┼──────────────────────────────────┼──────────────────────────────────────┤  
│ \*\*Pflug\*\*         │ Low fencer's lunge;              │ Wild skewering charge (+120uu warp); │  
│ \*(Plow Guard)\*    │ rapid piercing line-of-sight     │ over-extends spine, locks evasion    │  
├───────────────────┼──────────────────────────────────┼──────────────────────────────────────┤  
│ \*\*Ochs\*\*          │ High eye-level viewport bind;    │ Blade trembles with soot static;     │  
│ \*(Window Guard)\*  │ fluid parry-to-riposte\[cite: 3\] │ parry window shrinks 35% (0.13s)\[cite: 2\]│  
├───────────────────┼──────────────────────────────────┼──────────────────────────────────────┤  
│ \*\*Mordhau\*\*       │ Disciplined two-handed grip;     │ Savage flailing bludgeon; drains     │  
│ \*(Murder-Stroke)\* │ measured armor crushing\[cite: 3\]│ double stamina per swing│  
└───────────────────┴──────────────────────────────────┴──────────────────────────────────────┘

## **💻 SECTION IV: C++ Runtime Architecture & Gameplay Ability System**

┌─────────────────────────────────────────────────────────────────────────────────────────────┐  
│                               HUNGER KINETIC EVALUATION PIPELINE                            │  
│                                                                                             │  
│   \[FSoulStateVector.ParasitePressure\] ──► \[UAshenBladeHungerEvaluator\]                      │  
│                                                          │                                  │  
│         ┌────────────────────────────────────────────────┴──────────────────┐               │  
│         ▼                                                                   ▼               │  
│   \[Montage Skew-Warp Target\]                                    \[Recovery Frame Additive\]   │  
│   (FMath::Lerp(0, 120uu, H))                                    (FMath::Lerp(0.0, 0.35s, H))│  
│         │                                                                   │               │  
│         └───────────────────────────────┬───────────────────────────────────┘               │  
│                                         │                                                   │  
│                                         ▼                                                   │  
│                        \[UGA\_OathbringerPredatorySwing\]                                      │  
└─────────────────────────────────────────────────────────────────────────────────────────────┘

### **1\. The Dynamic Ability Implementation (UGA\_OathbringerPredatorySwing)**

C++  
// Source/AshenOath/Combat/Abilities/GA\_OathbringerPredatorySwing.h  
\#**pragma** once

\#**include** "CoreMinimal.h"  
\#**include** "Abilities/GameplayAbility.h"  
\#**include** "GA\_OathbringerPredatorySwing.generated.h"

UCLASS()  
class ASHENOATH\_API UGA\_OathbringerPredatorySwing : public UGameplayAbility  
{  
    GENERATED\_BODY()

public:  
    UGA\_OathbringerPredatorySwing();

    virtual void ActivateAbility(  
        const FGameplayAbilitySpecHandle Handle,   
        const FGameplayAbilityActorInfo\* ActorInfo,   
        const FGameplayAbilityActivationInfo ActivationInfo,   
        const FGameplayEventData\* TriggerEventData) override;

protected:  
    UPROPERTY(EditDefaultsOnly, Category \= "Hunger|Kinetics")  
    UAnimMontage\* BaseSwingMontage;

    UPROPERTY(EditDefaultsOnly, Category \= "Hunger|Kinetics")  
    UAnimMontage\* OverSwingMontage;

    void ApplyPredatoryWarping(float HungerScalar);  
    void UpdateSomaticTelemetry(float HungerScalar);  
};

C++  
// Source/AshenOath/Combat/Abilities/GA\_OathbringerPredatorySwing.cpp  
\#**include** "GA\_OathbringerPredatorySwing.h"  
\#**include** "GameFramework/Character.h"  
\#**include** "RootMotionModifier.h"  
\#**include** "MotionWarpingComponent.h"  
\#**include** "Soul/AshenSoulPublisher.h"

void UGA\_OathbringerPredatorySwing::ActivateAbility(...)  
{  
    ACharacter\* Character \= Cast\<ACharacter\>(GetAvatarActorFromActorInfo());  
    UAshenSoulPublisher\* Publisher \= GetWorld()-\>GetGameInstance()-\>GetSubsystem\<UAshenSoulPublisher\>();  
    if (\!Character || \!Publisher) return;

    const float Hunger \= Publisher-\>GetSoulState().ParasitePressure;

    // 1\. Evaluate Motion Warping: Predatory Magnetism (0uu \-\> 120uu)  
    if (Hunger \>= 0.60f)  
    {  
        if (UMotionWarpingComponent\* WarpComp \= Character-\>FindComponentByClass\<UMotionWarpingComponent\>())  
        {  
            AActor\* NearestBleedingTarget \= FindNearestBleedingTarget(Character-\>GetActorLocation(), 450.0f);  
            if (NearestBleedingTarget)  
            {  
                const FVector TargetLoc \= NearestBleedingTarget-\>GetActorLocation();  
                const FVector LungeLoc \= FMath::VInterpTo(Character-\>GetActorLocation(), TargetLoc, 0.40f, 10.0f);  
                  
                WarpComp-\>AddOrUpdateWarpTargetFromLocation(FName("PredatoryLungeTarget"), LungeLoc);  
            }  
        }  
    }

    // 2\. Play Appropriate Montage (Base vs Over-committed Over-Swing)  
    UAnimMontage\* MontageToPlay \= (Hunger \>= 0.60f) ? OverSwingMontage : BaseSwingMontage;  
    PlayMontageAndWaitForEvent(MontageToPlay);

    // 3\. Drive Somatosensory & Shader Outputs  
    UpdateSomaticTelemetry(Hunger);  
}

## **🔗 SECTION V: Calculated Deference as the Somatic Emergency Brake**

The rework of Blade Hunger directly elevates **Calculated Deference (AOP-COMBAT-SPEC-101)** from a tactical option into a **vital survival necessity**:

                                \[ HIGH BLADE HUNGER FRENZY \]  
                     (Loss of Control, Soot Tunnel Vision, 650uu Spacing)  
                                              │  
                                              ▼  
                        \[ PLAYER INTENTIONALLY INPUTS BIND \]  
                                (L2 \+ R-Stick Azimuth)  
                                              │  
               ┌──────────────────────────────┴──────────────────────────────┐  
               ▼                                                             ▼  
    \[ MARTIAL GROUNDING: OCHS \]                                   \[ COMPANION RESCUE PAYOFF \]  
    • Kaelen plants boots into stone                              • Garrett Tendon Vault / Serafina Holy Lance  
    • Halts forward kinetic lunging                               • Slams into locked blade fulcrum  
    • Absorbs poise strain, yields DPS                            • Shatters frenzy, burns off soot shaders  
               │                                                             │  
               └──────────────────────────────┬──────────────────────────────┘  
                                              │  
                                              ▼  
                              \[ SYMBIOTIC RESTORATION \]  
                              • ParasitePressure: \-0.35 (Silences Eldrin)\[cite: 2, 8\]  
                              • Soot Vignette Clears Completely  
                              • Spacing Snaps from 650uu ──► 150uu

When Kaelen is spiraling into Predatory Momentum, **he cannot defend himself**\[cite: 2, 5\]. He is over-swinging, missing parry windows, and leaving his spine exposed.  
Executing Calculated Deference forces Kaelen to plant his heels, resist the sword’s forward pull, and raise *Oathbringer* into a rigid **Ochs Bind**. By surrendering his offensive momentum, he allows Garrett and Serafina to strike the enemy, **physically snapping him out of the frenzy and cleansing the soot from his soul**.

## **📖 SECTION VI: Living Journal Provenance & SELT Audit (UMB-UI-004)**

When resting at a Sanctuary Hearth after an encounter dominated by Predatory Momentum, the Living Journal dynamically renders Kaelen's loss of motor control:

┌─────────────────────────────────────────────────────────────────────────────────────────────┐  
│                          LIVING JOURNAL ENTRY: THE DRAGGING STEEL                           │  
├─────────────────────────────────────────────────────────────────────────────────────────────┤  
│  \[Kaelen's Hand \- Shaky, frantic script with deep, torn ink gouges\]:                       │  
│  "The iron moved before my feet did. I swung, and the mud came up to meet my face.          │  
│   I could hear the boy screaming behind me, but all I could see was the black smoke.        │  
│   The sword wanted the kill. It didn't care if I was holding it or being dragged by it."    │  
│                                                                                             │  
│  \[Garrett's Margin \- Heavy charcoal underlining across the tear\]:                           │  
│  "You over-swung by two full feet at the gate. If I hadn't ducked under your backswing,     │  
│   you would have taken my ear off with the crossguard. Stop letting the steel drive."       │  
│                                                                                             │  
│  \[Serafina's Margin \- Pale silver resin dropped over the scorched corner\]:                  │  
│  "Your hands were freezing on the hilt, Kaelen. When you locked into Ochs, the fever broke. │  
│   Do not let the darkness convince you that swinging harder is the same as standing firm."  │  
└─────────────────────────────────────────────────────────────────────────────────────────────┘

## **🧪 SECTION VII: Value-Asserting Automation Test Suite**

C++  
// Source/AshenOathTests/Private/AshenBladeHungerMomentumTest.cpp  
\#**include** "Misc/AutomationTest.h"  
\#**include** "Combat/AshenBladeHungerEvaluator.h"  
\#**include** "Soul/AshenSoulPublisher.h"

IMPLEMENT\_SIMPLE\_AUTOMATION\_TEST(FAshenBladeHungerMomentumTest, "AshenOath.Combat.BladeHunger.PredatoryMomentum",   
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FAshenBladeHungerMomentumTest::RunTest(const FString& Parameters)  
{  
    UWorld\* World \= FTestWorldScope::CreateTestWorld();  
    UAshenSoulPublisher\* Publisher \= World-\>GetGameInstance()-\>GetSubsystem\<UAshenSoulPublisher\>();  
    UAshenBladeHungerEvaluator\* Evaluator \= NewObject\<UAshenBladeHungerEvaluator\>();

    // 1\. Verify No Flat Damage Multiplier Exists  
    const float BaseDamage \= 100.0f;  
    const float HighHungerDamage \= Evaluator-\>CalculateOutputDamage(BaseDamage, 1.0f /\* Max Hunger \*/);  
    TestEqual("High Hunger must NOT apply a flat damage multiplier (Base \== Output)", HighHungerDamage, BaseDamage);

    // 2\. Assert Recovery Frame Penalty Scaling (+0.35s at Max Hunger)  
    const float LowHungerRecoveryAdd \= Evaluator-\>GetRecoveryFrameAdditive(0.0f);  
    const float HighHungerRecoveryAdd \= Evaluator-\>GetRecoveryFrameAdditive(1.0f);  
    TestEqual("Zero Hunger recovery additive must be 0.0s", LowHungerRecoveryAdd, 0.0f);  
    TestEqual("Max Hunger recovery additive must be exactly \+0.35s", HighHungerRecoveryAdd, 0.35f);

    // 3\. Assert Predatory Magnetism Skew-Warp Distance (+120uu at Max Hunger)  
    const float LungeWarpDistance \= Evaluator-\>GetPredatoryWarpDistance(0.80f);  
    TestTrue("Hunger \>= 0.60 must apply forward lunge warping (\>= 100uu)", LungeWarpDistance \>= 100.0f);

    // 4\. Assert DualSense Trigger Resistance Escalation  
    const uint8 TriggerStiffness \= Evaluator-\>GetL2TriggerStiffness(0.85f);  
    TestTrue("High Hunger must lock L2 trigger stiffness \>= 200/255", TriggerStiffness \>= 200);

    return true;  
}

## **🎯 Final Architectural Verification**

AOP-REWORK-HUNGER-103-PROD achieves complete systemic and narrative integrity\[cite: 3\]:

> 1. **Eliminates Min-Max Exploits:** Players will never farm hunger for spreadsheet numbers, because high hunger actively destabilizes defensive control and spatial awareness\[cite: 2, 3\].  
> 2. **Embodies the Horror of Eldrin's Prison:** The greatsword feels like a heavy, living entity that drags Kaelen toward violence rather than an obedient magic tool.  
> 3. **Harmonizes with Calculated Deference:** Makes interdependent companion play an essential martial anchor, grounding Kaelen when the darkness threatens to consume his humanity.