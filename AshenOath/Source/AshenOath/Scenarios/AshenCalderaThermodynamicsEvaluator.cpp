// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenCalderaThermodynamicsEvaluator.h"

UAshenCalderaThermodynamicsEvaluator::UAshenCalderaThermodynamicsEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenCalderaThermodynamicsEvaluator::EvaluateHeatExhaustionRate(float TempC, bool bInCoolingMist) const
{
	if (bInCoolingMist)
	{
		return -0.05f; // Rapid recovery in Garrett's cryo mist
	}

	if (TempC <= 35.0f)
	{
		return 0.0f;
	}

	return FMath::Clamp((TempC - 35.0f) / 400.0f, 0.005f, 0.15f);
}

float UAshenCalderaThermodynamicsEvaluator::EvaluateStaminaDrainMultiplier(float HeatExhaustion01) const
{
	const float ClampedHeat = FMath::Clamp(HeatExhaustion01, 0.0f, 1.0f);
	return 1.0f + (1.0f * ClampedHeat);
}

float UAshenCalderaThermodynamicsEvaluator::EvaluateThermalDamagePerSecond(float HeatExhaustion01) const
{
	if (HeatExhaustion01 < 0.90f)
	{
		return 0.0f;
	}

	// 0.90 to 1.00 scales 0 to 30 dmg/s
	const float Alpha = (HeatExhaustion01 - 0.90f) / 0.10f;
	return FMath::Lerp(0.0f, 30.0f, Alpha);
}
