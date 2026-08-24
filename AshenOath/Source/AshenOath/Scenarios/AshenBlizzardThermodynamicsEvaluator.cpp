// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenBlizzardThermodynamicsEvaluator.h"

UAshenBlizzardThermodynamicsEvaluator::UAshenBlizzardThermodynamicsEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenBlizzardThermodynamicsEvaluator::EvaluateFrostbiteRatePerSecond(
	float AmbientTemperatureCelsius,
	bool bInCompanionWarmth) const
{
	if (bInCompanionWarmth)
	{
		return -0.05f; // Active recovery
	}

	// -5°C -> 0.01/s; -15°C -> 0.025/s; -25°C -> 0.04/s; -35°C -> 0.06/s
	const float BaseRate = FMath::Abs(AmbientTemperatureCelsius) / 600.0f;
	return FMath::Clamp(BaseRate, 0.005f, 0.10f);
}

float UAshenBlizzardThermodynamicsEvaluator::EvaluateMovementSpeedMultiplier(float FrostbiteGauge) const
{
	const float Clamped = FMath::Clamp(FrostbiteGauge, 0.0f, 1.0f);
	return 1.0f - (Clamped * 0.60f); // 1.00x down to 0.40x
}
