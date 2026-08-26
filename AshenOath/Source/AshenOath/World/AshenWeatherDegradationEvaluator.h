// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenWeatherDegradationEvaluator.generated.h"

/**
 * UAshenWeatherDegradationEvaluator
 * 
 * Computes armor durability corrosion (-2.5%/s), movement speed slow (-30%), and stamina regeneration suppression from severe weather.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherDegradationEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherDegradationEvaluator();

	/** Evaluates movement speed multiplier in severe blizzard conditions [0.70x to 1.00x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Weather|Degradation")
	float EvaluateMovementSpeedModifier(EWeatherHazardState State) const;

	/** Evaluates armor durability degradation per second [%/s] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Weather|Degradation")
	float EvaluateArmorCorrosionRate(EWeatherHazardState State, bool bHasAlchemicalInsulation) const;

	/** Evaluates stamina regeneration penalty multiplier [0.75x to 1.00x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Weather|Degradation")
	float EvaluateStaminaRegenModifier(EWeatherHazardState State) const;
};
