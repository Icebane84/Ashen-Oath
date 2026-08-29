// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenShelterThermodynamicsEvaluator.h"

UAshenShelterThermodynamicsEvaluator::UAshenShelterThermodynamicsEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenShelterThermodynamicsEvaluator::EvaluateHypothermiaHPLoss(
	EThermalShelterTier Tier,
	bool bInBlizzard) const
{
	if (!bInBlizzard || Tier == EThermalShelterTier::SanctuaryHearthRadius || Tier == EThermalShelterTier::NaturalCavern)
	{
		return 0.0f;
	}
	return -2.50f; // -2.5 HP per second in exposed blizzard
}

float UAshenShelterThermodynamicsEvaluator::EvaluateCookingSpeedMultiplier(
	EThermalShelterTier Tier) const
{
	switch (Tier)
	{
	case EThermalShelterTier::SanctuaryHearthRadius:
	case EThermalShelterTier::NaturalCavern:
		return 2.00f; // 2.0x (50% faster cooking rate in windbreak shelter)
	case EThermalShelterTier::OpenWilderness:
	default:
		return 1.00f;
	}
}

float UAshenShelterThermodynamicsEvaluator::EvaluateSanityDecayScale(
	EThermalShelterTier Tier) const
{
	switch (Tier)
	{
	case EThermalShelterTier::SanctuaryHearthRadius:
		return 0.0f; // Complete sanity preservation in Hearthstone haven
	case EThermalShelterTier::NaturalCavern:
		return 0.50f;
	case EThermalShelterTier::OpenWilderness:
	default:
		return 1.00f;
	}
}
