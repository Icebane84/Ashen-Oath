// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenMealHazardImmunityEvaluator.generated.h"

/**
 * UAshenMealHazardImmunityEvaluator
 * 
 * Computes environmental hazard mitigation (100% immunity against Blizzards from Glacial Stew, Acid Rain from Vitriol Broth, Ash Storms from Cinder Cake).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMealHazardImmunityEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMealHazardImmunityEvaluator();

	/** Evaluates whether player is immune to the specific weather hazard */
	UFUNCTION(BlueprintPure, Category = "Ashen|Survival|Evaluator")
	bool IsImmuneToHazard(ECookedMealBuffType ActiveMeal, bool bInBlizzard, bool bInAcidRain, bool bInAshStorm) const;

	/** Evaluates net damage reduction percentage [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Survival|Evaluator")
	float EvaluateHazardDamageReduction(ECookedMealBuffType ActiveMeal, bool bInBlizzard, bool bInAcidRain, bool bInAshStorm) const;
};
