// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenDynamicDebrisOcclusionAudioLinker.generated.h"

/**
 * UAshenDynamicDebrisOcclusionAudioLinker
 * 
 * Computes dynamic MetaSounds low-pass filter cutoff frequencies based on physical rubble obstruction.
 */
UCLASS()
class ASHENOATH_API UAshenDynamicDebrisOcclusionAudioLinker : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Calculates LPF cutoff frequency based on obstructing rubble fragments */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|KineticBerserk")
	static float CalculateDebrisLowPassCutoff(
		int32 ObstructingRubbleCount,
		float MaxDebrisCount = 6.0f,
		float BaseFrequency = 20000.0f,
		float MuffledFloorFrequency = 400.0f);

	/** Evaluates occlusion state category */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|KineticBerserk")
	static EAshenDebrisOcclusionState EvaluateDebrisOcclusionState(int32 ObstructingRubbleCount);
};
