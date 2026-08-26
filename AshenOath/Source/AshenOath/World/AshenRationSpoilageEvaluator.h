// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenRationSpoilageEvaluator.generated.h"

/**
 * UAshenRationSpoilageEvaluator
 * 
 * Computes ration shelf-life degradation over travel distance and evaluates ember-salt preservation scaling.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRationSpoilageEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRationSpoilageEvaluator();

	/** Evaluates updated freshness percent after travel distance [0.0 to 100.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|Rations")
	float EvaluateFreshnessAfterDistance(float CurrentFreshness, float TravelDistanceMeters, EIngredientQualityTier Quality) const;

	/** Checks if ingredient has spoiled */
	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking|Rations")
	bool IsRationSpoiled(float FreshnessPercent) const;
};
