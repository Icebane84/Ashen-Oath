// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenMireHazardEvaluatorComponent.h"

UAshenMireHazardEvaluatorComponent::UAshenMireHazardEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenMireHazardEvaluatorComponent::EvaluateMudSpeedMultiplier(
	bool bInDeepMud,
	bool bIsUnchained) const
{
	if (!bInDeepMud)
	{
		return 1.0f;
	}

	// Unchained mode powers through mud with 0.85x speed instead of severe 0.50x penalty
	return bIsUnchained ? 0.85f : 0.50f;
}

float UAshenMireHazardEvaluatorComponent::EvaluateGasBlastDamage(
	float BaseDamage,
	float DistanceCentimeters,
	float MaxRadiusCentimeters) const
{
	if (DistanceCentimeters >= MaxRadiusCentimeters)
	{
		return 0.0f;
	}

	const float DistanceRatio = FMath::Clamp(DistanceCentimeters / MaxRadiusCentimeters, 0.0f, 1.0f);
	return BaseDamage * (1.0f - DistanceRatio);
}
