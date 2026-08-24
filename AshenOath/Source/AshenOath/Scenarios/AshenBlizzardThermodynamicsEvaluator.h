// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenBlizzardThermodynamicsEvaluator.generated.h"

/**
 * UAshenBlizzardThermodynamicsEvaluator
 * 
 * Computes thermodynamic freezing decay and movement speed penalties based on ambient temperature and companion proximity.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBlizzardThermodynamicsEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBlizzardThermodynamicsEvaluator();

	/** Computes frostbite accumulation per second */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario6|Thermodynamics")
	float EvaluateFrostbiteRatePerSecond(float AmbientTemperatureCelsius, bool bInCompanionWarmth) const;

	/** Computes movement speed multiplier from frostbite gauge [0.40x to 1.00x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario6|Thermodynamics")
	float EvaluateMovementSpeedMultiplier(float FrostbiteGauge) const;
};
