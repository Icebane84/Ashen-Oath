// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenMapParchmentPostProcessAdapter.generated.h"

/**
 * UAshenMapParchmentPostProcessAdapter
 * 
 * Drives parchment paper sepia tone, ink contour etching, and perimeter vignette when viewing the tactical map.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMapParchmentPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMapParchmentPostProcessAdapter();

	/** Evaluates post-process parameters for tactical map viewing */
	UFUNCTION(BlueprintPure, Category = "Ashen|Map|PostProcess")
	void EvaluateMapParchmentPostProcess(
		bool bMapOpen,
		float& OutSepiaIntensity,
		float& OutInkContourContrast,
		float& OutVignetteRadius);
};
