// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenPathfindingDisruptionEvaluatorComponent.h"

UAshenPathfindingDisruptionEvaluatorComponent::UAshenPathfindingDisruptionEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

EPathfindingDisruptionTier UAshenPathfindingDisruptionEvaluatorComponent::EvaluateDisruptionTier(float UtilityScore) const
{
	if (UtilityScore < 0.15f)
	{
		return EPathfindingDisruptionTier::CircuitBreakerTripped; // LAW-001 Tripped
	}
	else if (UtilityScore < 0.70f)
	{
		return EPathfindingDisruptionTier::DegradedRouting;
	}
	return EPathfindingDisruptionTier::NormalNavigation;
}

float UAshenPathfindingDisruptionEvaluatorComponent::EvaluateDegradedUtility(
	float BaseUtility,
	int32 NearbyTrapCount) const
{
	// Each nearby trap reduces AI path utility by 0.25f
	const float Penalty = NearbyTrapCount * 0.25f;
	return FMath::Clamp(BaseUtility - Penalty, 0.0f, 1.0f);
}
