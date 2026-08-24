// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenHeatDistortionPostProcessAdapter.generated.h"

/**
 * UAshenHeatDistortionPostProcessAdapter
 * 
 * Computes optical heat shimmering distortion intensity (0.0 to 1.0) and edge orange combustion glow.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHeatDistortionPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHeatDistortionPostProcessAdapter();

	/** Evaluates optical heat shimmer distortion [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7|PostProcess")
	float EvaluateHeatShimmerIntensity(float AmbientTempC) const;

	/** Evaluates combustion vignette intensity based on heat exhaustion [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7|PostProcess")
	float EvaluateCombustionVignette(float HeatExhaustion01) const;
};
