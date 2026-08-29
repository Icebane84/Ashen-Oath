// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenMealHazardImmunityEvaluator.h"

UAshenMealHazardImmunityEvaluator::UAshenMealHazardImmunityEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	BalanceDataAsset = nullptr;
}

bool UAshenMealHazardImmunityEvaluator::IsImmuneToHazard(
	ECookedMealBuffType ActiveMeal,
	bool bInBlizzard,
	bool bInAcidRain,
	bool bInAshStorm) const
{
	if (bInBlizzard && ActiveMeal == ECookedMealBuffType::GlacialHeartStew)
	{
		return true;
	}

	if (bInAcidRain && ActiveMeal == ECookedMealBuffType::VitriolPurgeBroth)
	{
		return true;
	}

	if (bInAshStorm && ActiveMeal == ECookedMealBuffType::CinderAshCake)
	{
		return true;
	}

	return false;
}

float UAshenMealHazardImmunityEvaluator::EvaluateHazardDamageReduction(
	ECookedMealBuffType ActiveMeal,
	bool bInBlizzard,
	bool bInAcidRain,
	bool bInAshStorm) const
{
	const bool bImmune = IsImmuneToHazard(ActiveMeal, bInBlizzard, bInAcidRain, bInAshStorm);
	if (bImmune)
	{
		if (BalanceDataAsset)
		{
			return BalanceDataAsset->GetClampedMealBalancing().MatchedHazardDamageReduction;
		}
		return 1.0f; // 100% reduction
	}

	return 0.0f;
}
