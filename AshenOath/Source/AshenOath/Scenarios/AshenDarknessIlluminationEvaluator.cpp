// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenDarknessIlluminationEvaluator.h"

UAshenDarknessIlluminationEvaluator::UAshenDarknessIlluminationEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenDarknessIlluminationEvaluator::EvaluateLightRadius(float TorchFuel01) const
{
	const float ClampedFuel = FMath::Clamp(TorchFuel01, 0.0f, 1.0f);
	return FMath::Clamp(100.0f + (700.0f * ClampedFuel), 100.0f, 800.0f);
}

float UAshenDarknessIlluminationEvaluator::EvaluateDarknessMissPenalty(float LightRadiusUU) const
{
	if (LightRadiusUU >= 600.0f)
	{
		return 0.0f;
	}

	// 600uu down to 100uu scales 0.0 to 0.60 miss chance
	const float Alpha = 1.0f - FMath::Clamp((LightRadiusUU - 100.0f) / 500.0f, 0.0f, 1.0f);
	return Alpha * 0.60f;
}

float UAshenDarknessIlluminationEvaluator::EvaluateFearDebtPerSecond(float LightRadiusUU) const
{
	if (LightRadiusUU >= 250.0f)
	{
		return 0.0f;
	}

	// Below 250uu down to 100uu scales 0.0 to 0.02 Integration Debt / second
	const float Alpha = 1.0f - FMath::Clamp((LightRadiusUU - 100.0f) / 150.0f, 0.0f, 1.0f);
	return Alpha * 0.02f;
}
