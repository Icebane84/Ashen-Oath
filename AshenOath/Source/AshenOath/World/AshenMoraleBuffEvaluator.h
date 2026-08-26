// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenMoraleBuffEvaluator.generated.h"

/**
 * UAshenMoraleBuffEvaluator
 * 
 * Computes combat stat bonuses, stamina boosts, and burnout mitigation percentages from active campfire meals.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMoraleBuffEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMoraleBuffEvaluator();

	/** Evaluates posture/poise resistance bonus multiplier [1.0x to 1.25x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|Buffs")
	float EvaluatePoiseResistanceBonus(ECampfireRecipeType Recipe) const;

	/** Evaluates max stamina flat bonus [0 to 150] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|Buffs")
	float EvaluateMaxStaminaBonus(ECampfireRecipeType Recipe) const;

	/** Evaluates burnout accumulation mitigation multiplier [0.70x to 1.00x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|Buffs")
	float EvaluateBurnoutMitigationMultiplier(ECampfireRecipeType Recipe) const;

	/** Evaluates kinetic cleave damage multiplier [1.0x to 1.25x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|Buffs")
	float EvaluateKineticDamageMultiplier(ECampfireRecipeType Recipe) const;

	/** Evaluates meal buff duration in seconds */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|Buffs")
	float GetMealBuffDurationSeconds() const { return 600.0f; } // 10 minutes
};
