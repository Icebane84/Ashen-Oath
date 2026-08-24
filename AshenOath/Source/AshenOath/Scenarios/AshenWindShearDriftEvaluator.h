// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenWindShearDriftEvaluator.generated.h"

/**
 * UAshenWindShearDriftEvaluator
 * 
 * Computes lateral aerodynamic drag forces and displacement applied to airborne units in high-altitude gales.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWindShearDriftEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWindShearDriftEvaluator();

	/** Evaluates lateral wind drift displacement in UU per second */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9|Wind")
	FVector EvaluateAirborneWindDrift(float WindSpeedMps, const FVector& WindDirection, bool bIsAnchored) const;

	/** Evaluates wind shear destabilization penalty [0.0 to 0.75] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9|Wind")
	float EvaluateWindDestabilizationPenalty(float WindSpeedMps, bool bIsAnchored) const;
};
