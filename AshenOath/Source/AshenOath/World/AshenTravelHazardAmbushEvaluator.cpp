// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenTravelHazardAmbushEvaluator.h"

UAshenTravelHazardAmbushEvaluator::UAshenTravelHazardAmbushEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenTravelHazardAmbushEvaluator::EvaluateAmbushProbability(
	float DistanceKm,
	float RegionCorruption01,
	bool bUsedEmberSaltProvisions) const
{
	const float SafeDist = FMath::Clamp(DistanceKm, 0.5f, 20.0f);
	const float SafeCorr = FMath::Clamp(RegionCorruption01, 0.0f, 1.0f);

	float BaseRisk = (SafeDist * 3.0f) + (SafeCorr * 40.0f); // 0 to 75%

	if (bUsedEmberSaltProvisions)
	{
		BaseRisk *= 0.50f; // Halve hazard chance with seasoned provisions
	}

	return FMath::Clamp(BaseRisk, 0.0f, 75.0f);
}

float UAshenTravelHazardAmbushEvaluator::EvaluateSurprisePosturePenalty(bool bAmbushTriggered) const
{
	return bAmbushTriggered ? 0.85f : 1.00f; // -15% posture mitigation on surprise
}
