// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenWindShearDriftEvaluator.h"

UAshenWindShearDriftEvaluator::UAshenWindShearDriftEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FVector UAshenWindShearDriftEvaluator::EvaluateAirborneWindDrift(
	float WindSpeedMps,
	const FVector& WindDirection,
	bool bIsAnchored) const
{
	if (bIsAnchored)
	{
		return FVector::ZeroVector;
	}

	// 1 m/s = 100 uu/s. Airborne drag captures ~30% of wind velocity
	const float DriftSpeedUU = WindSpeedMps * 100.0f * 0.30f;
	return WindDirection.GetSafeNormal() * DriftSpeedUU;
}

float UAshenWindShearDriftEvaluator::EvaluateWindDestabilizationPenalty(
	float WindSpeedMps,
	bool bIsAnchored) const
{
	if (bIsAnchored || WindSpeedMps <= 15.0f)
	{
		return 0.0f;
	}

	// 15 m/s to 45 m/s scales 0.0 to 0.75 penalty
	const float Alpha = FMath::Clamp((WindSpeedMps - 15.0f) / 30.0f, 0.0f, 1.0f);
	return Alpha * 0.75f;
}
