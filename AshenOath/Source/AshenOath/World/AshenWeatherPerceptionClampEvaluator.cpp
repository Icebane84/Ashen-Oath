// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenWeatherPerceptionClampEvaluator.h"

UAshenWeatherPerceptionClampEvaluator::UAshenWeatherPerceptionClampEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenWeatherPerceptionClampEvaluator::EvaluateLockOnRangeClamp(
	EAtmosphericVisibilityTier Tier) const
{
	switch (Tier)
	{
	case EAtmosphericVisibilityTier::BlizzardWhiteout:
		return 500.0f;
	case EAtmosphericVisibilityTier::VolcanicAshStorm:
		return 750.0f;
	case EAtmosphericVisibilityTier::AcidRainMist:
		return 1100.0f;
	case EAtmosphericVisibilityTier::ClearDaylight:
	default:
		return 1500.0f;
	}
}

float UAshenWeatherPerceptionClampEvaluator::EvaluateAISightRadius(
	EAtmosphericVisibilityTier Tier) const
{
	switch (Tier)
	{
	case EAtmosphericVisibilityTier::BlizzardWhiteout:
		return 600.0f;
	case EAtmosphericVisibilityTier::VolcanicAshStorm:
		return 900.0f;
	case EAtmosphericVisibilityTier::AcidRainMist:
		return 1400.0f;
	case EAtmosphericVisibilityTier::ClearDaylight:
	default:
		return 2000.0f;
	}
}

float UAshenWeatherPerceptionClampEvaluator::EvaluateAIVisionConeDegrees(
	EAtmosphericVisibilityTier Tier) const
{
	switch (Tier)
	{
	case EAtmosphericVisibilityTier::BlizzardWhiteout:
		return 45.0f;
	case EAtmosphericVisibilityTier::VolcanicAshStorm:
		return 55.0f;
	case EAtmosphericVisibilityTier::AcidRainMist:
		return 75.0f;
	case EAtmosphericVisibilityTier::ClearDaylight:
	default:
		return 90.0f;
	}
}

float UAshenWeatherPerceptionClampEvaluator::EvaluateStealthAmbushMultiplier(
	EAtmosphericVisibilityTier Tier) const
{
	switch (Tier)
	{
	case EAtmosphericVisibilityTier::BlizzardWhiteout:
	case EAtmosphericVisibilityTier::VolcanicAshStorm:
		return 1.50f; // +50% critical strike damage from storm stealth
	case EAtmosphericVisibilityTier::AcidRainMist:
		return 1.20f;
	case EAtmosphericVisibilityTier::ClearDaylight:
	default:
		return 1.00f;
	}
}
