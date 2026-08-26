// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenMoraleBuffEvaluator.h"

UAshenMoraleBuffEvaluator::UAshenMoraleBuffEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenMoraleBuffEvaluator::EvaluatePoiseResistanceBonus(ECampfireRecipeType Recipe) const
{
	switch (Recipe)
	{
	case ECampfireRecipeType::SentinelsIronBroth:
	case ECampfireRecipeType::GrandZenithSoulGoulash:
		return 1.25f; // +25% poise
	default:
		return 1.00f;
	}
}

float UAshenMoraleBuffEvaluator::EvaluateMaxStaminaBonus(ECampfireRecipeType Recipe) const
{
	switch (Recipe)
	{
	case ECampfireRecipeType::SentinelsIronBroth:
		return 150.0f;
	case ECampfireRecipeType::GrandZenithSoulGoulash:
		return 200.0f;
	default:
		return 0.0f;
	}
}

float UAshenMoraleBuffEvaluator::EvaluateBurnoutMitigationMultiplier(ECampfireRecipeType Recipe) const
{
	switch (Recipe)
	{
	case ECampfireRecipeType::WhiteFlameHerbalTisane:
	case ECampfireRecipeType::GrandZenithSoulGoulash:
		return 0.70f; // -30% burnout accumulation
	default:
		return 1.00f;
	}
}

float UAshenMoraleBuffEvaluator::EvaluateKineticDamageMultiplier(ECampfireRecipeType Recipe) const
{
	switch (Recipe)
	{
	case ECampfireRecipeType::GloomwoodVenisonStew:
		return 1.20f; // +20% damage
	case ECampfireRecipeType::GrandZenithSoulGoulash:
		return 1.25f; // +25% damage
	default:
		return 1.00f;
	}
}
