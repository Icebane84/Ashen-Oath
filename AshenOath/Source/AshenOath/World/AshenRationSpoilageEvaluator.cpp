// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenRationSpoilageEvaluator.h"

UAshenRationSpoilageEvaluator::UAshenRationSpoilageEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenRationSpoilageEvaluator::EvaluateFreshnessAfterDistance(
	float CurrentFreshness,
	float TravelDistanceMeters,
	EIngredientQualityTier Quality) const
{
	// Base decay: 1.0% per 100 meters traveled
	float DecayRate = TravelDistanceMeters / 100.0f;

	if (Quality == EIngredientQualityTier::PreservedSalted)
	{
		DecayRate /= 3.0f; // 3x shelf life
	}
	else if (Quality == EIngredientQualityTier::PristineEmber)
	{
		DecayRate /= 1.5f;
	}

	return FMath::Clamp(CurrentFreshness - DecayRate, 0.0f, 100.0f);
}

bool UAshenRationSpoilageEvaluator::IsRationSpoiled(float FreshnessPercent) const
{
	return FreshnessPercent <= 0.0f;
}
