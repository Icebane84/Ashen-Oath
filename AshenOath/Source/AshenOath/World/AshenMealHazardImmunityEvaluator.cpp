// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenMealHazardImmunityEvaluator.h"

UAshenMealHazardImmunityEvaluator::UAshenMealHazardImmunityEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
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
	if (IsImmuneToHazard(ActiveMeal, bInBlizzard, bInAcidRain, bInAshStorm))
	{
		return 1.00f; // 100% Damage Reduction
	}
	return 0.0f;
}
