// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenFrostbitePostProcessAdapter.generated.h"

/**
 * UAshenFrostbitePostProcessAdapter
 * 
 * Drives post-process screen-edge ice frost vignette (0.0 to 1.0) and desaturated blue color grading.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFrostbitePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFrostbitePostProcessAdapter();

	/** Computes screen frost vignette intensity [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario6|PostProcess")
	float EvaluateFrostVignetteIntensity(float FrostbiteGauge) const;

	/** Computes cold color grade tint temperature shift in Kelvin [-2500K to 0K] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario6|PostProcess")
	float EvaluateColorTemperatureShift(float FrostbiteGauge) const;
};
