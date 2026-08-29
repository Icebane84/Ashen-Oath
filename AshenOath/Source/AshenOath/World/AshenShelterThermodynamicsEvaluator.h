// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenShelterThermodynamicsEvaluator.generated.h"

/**
 * UAshenShelterThermodynamicsEvaluator
 * 
 * Computes environmental exposure decay, hypothermia HP loss rates, and cooking velocity multipliers based on active shelter tier.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShelterThermodynamicsEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenShelterThermodynamicsEvaluator();

	/** Evaluates hypothermia damage per second [0.0 in shelter, -2.5 in blizzard] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Survival|Evaluator")
	float EvaluateHypothermiaHPLoss(EThermalShelterTier Tier, bool bInBlizzard) const;

	/** Evaluates campfire cooking velocity multiplier [1.0x open, 2.0x cavern/hearth] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Survival|Evaluator")
	float EvaluateCookingSpeedMultiplier(EThermalShelterTier Tier) const;

	/** Evaluates sanity decay suppression [0.0 in hearth, 1.0 in wilderness] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Survival|Evaluator")
	float EvaluateSanityDecayScale(EThermalShelterTier Tier) const;
};
