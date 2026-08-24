// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenCalderaThermodynamicsEvaluator.generated.h"

/**
 * UAshenCalderaThermodynamicsEvaluator
 * 
 * Computes heat exhaustion accumulation rate, stamina penalty, and thermal damage per second.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCalderaThermodynamicsEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCalderaThermodynamicsEvaluator();

	/** Evaluates heat exhaustion rate per second based on temperature */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7|Thermodynamics")
	float EvaluateHeatExhaustionRate(float TempC, bool bInCoolingMist) const;

	/** Evaluates stamina drain multiplier [1.00x to 2.00x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7|Thermodynamics")
	float EvaluateStaminaDrainMultiplier(float HeatExhaustion01) const;

	/** Evaluates thermal damage per second [0.0 to 30.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario7|Thermodynamics")
	float EvaluateThermalDamagePerSecond(float HeatExhaustion01) const;
};
