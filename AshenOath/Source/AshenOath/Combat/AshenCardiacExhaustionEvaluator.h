// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenCardiacExhaustionEvaluator.generated.h"

/**
 * UAshenCardiacExhaustionEvaluator
 * 
 * Computes combat penalties when stamina drops below 35% critical threshold: +25% swing windup, +30% parry recovery penalty, and DualSense trigger resistance.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCardiacExhaustionEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCardiacExhaustionEvaluator();

	/** Evaluates weapon swing windup speed multiplier [0.75x to 1.00x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Cardiac")
	float EvaluateSwingWindupMultiplier(float CurrentStaminaPercent) const;

	/** Evaluates parry recovery duration multiplier [1.00x to 1.30x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Cardiac")
	float EvaluateParryRecoveryMultiplier(float CurrentStaminaPercent) const;

	/** Evaluates DualSense trigger resistance [0.10 to 0.85] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Cardiac")
	float EvaluateTriggerResistance(float CurrentStaminaPercent) const;
};
