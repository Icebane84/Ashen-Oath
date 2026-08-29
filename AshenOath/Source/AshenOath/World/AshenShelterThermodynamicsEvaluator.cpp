// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenShelterThermodynamicsEvaluator.h"

UAshenShelterThermodynamicsEvaluator::UAshenShelterThermodynamicsEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	BalanceDataAsset = nullptr;
}

float UAshenShelterThermodynamicsEvaluator::EvaluateHypothermiaHPLoss(EThermalShelterTier Tier, bool bInBlizzard) const
{
	if (!bInBlizzard)
	{
		return 0.0f;
	}

	// Shelter blocks hypothermia damage
	if (Tier == EThermalShelterTier::NaturalCavern || Tier == EThermalShelterTier::SanctuaryHearthRadius)
	{
		return 0.0f;
	}

	if (BalanceDataAsset)
	{
		return BalanceDataAsset->GetClampedShelterBalancing().WildernessHypothermiaHPLoss; // -2.50 HP/s
	}

	return -2.50f;
}

float UAshenShelterThermodynamicsEvaluator::EvaluateCookingSpeedMultiplier(EThermalShelterTier Tier) const
{
	if (Tier == EThermalShelterTier::NaturalCavern || Tier == EThermalShelterTier::SanctuaryHearthRadius)
	{
		if (BalanceDataAsset)
		{
			return BalanceDataAsset->GetClampedShelterBalancing().CavernCookingSpeedMultiplier; // 2.0x
		}
		return 2.0f;
	}

	return 1.0f;
}

float UAshenShelterThermodynamicsEvaluator::EvaluateSanityDecayScale(EThermalShelterTier Tier) const
{
	if (Tier == EThermalShelterTier::SanctuaryHearthRadius)
	{
		return 0.0f; // Complete sanity preservation in sanctuary
	}

	if (Tier == EThermalShelterTier::NaturalCavern)
	{
		return 0.25f; // 75% sanity suppression in cavern
	}

	return 1.0f; // 100% standard decay in open wilderness
}
