// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenWeatherDegradationEvaluator.h"

UAshenWeatherDegradationEvaluator::UAshenWeatherDegradationEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenWeatherDegradationEvaluator::EvaluateMovementSpeedModifier(EWeatherHazardState State) const
{
	return (State == EWeatherHazardState::BlizzardWhiteout) ? 0.70f : 1.00f; // -30% slow
}

float UAshenWeatherDegradationEvaluator::EvaluateArmorCorrosionRate(
	EWeatherHazardState State,
	bool bHasAlchemicalInsulation) const
{
	if (State != EWeatherHazardState::AcidRainCorrosion)
	{
		return 0.0f;
	}

	const float BaseRate = 2.5f; // 2.5% per second
	return bHasAlchemicalInsulation ? (BaseRate * 0.40f) : BaseRate; // 60% mitigation
}

float UAshenWeatherDegradationEvaluator::EvaluateStaminaRegenModifier(EWeatherHazardState State) const
{
	switch (State)
	{
	case EWeatherHazardState::VolcanicAshStorm:
		return 0.75f; // -25% stamina regen
	case EWeatherHazardState::BlizzardWhiteout:
		return 0.80f; // -20% stamina regen
	default:
		return 1.00f;
	}
}
