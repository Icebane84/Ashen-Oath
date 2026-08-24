// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenDarknessIlluminationEvaluator.generated.h"

/**
 * UAshenDarknessIlluminationEvaluator
 * 
 * Computes illumination radius, darkness combat hit penalties, and Integration Debt accumulation in pitch black.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDarknessIlluminationEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDarknessIlluminationEvaluator();

	/** Evaluates effective light radius in UU from torch fuel [100uu to 800uu] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8|Illumination")
	float EvaluateLightRadius(float TorchFuel01) const;

	/** Evaluates darkness attack miss penalty percentage [0.0 to 0.60] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8|Illumination")
	float EvaluateDarknessMissPenalty(float LightRadiusUU) const;

	/** Evaluates fear Integration Debt accumulation per second in darkness [0.0 to 0.02/s] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8|Illumination")
	float EvaluateFearDebtPerSecond(float LightRadiusUU) const;
};
