// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenCampfireWarmthPostProcessAdapter.generated.h"

/**
 * UAshenCampfireWarmthPostProcessAdapter
 * 
 * Drives warm amber hearth color grading, parchment sepia vignette, and depth-of-field ember bokeh.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireWarmthPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireWarmthPostProcessAdapter();

	/** Evaluates ember bokeh radius and warm amber grading intensity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|PostProcess")
	float EvaluateHearthWarmthIntensity(ECampfireReflectionMood Mood) const;

	/** Evaluates sepia vignette strength for reading mode [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|PostProcess")
	float EvaluateParchmentSepiaVignette(bool bJournalOpen) const;
};
