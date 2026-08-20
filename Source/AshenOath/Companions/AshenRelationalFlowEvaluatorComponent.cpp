// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenRelationalFlowEvaluatorComponent.h"

UAshenRelationalFlowEvaluatorComponent::UAshenRelationalFlowEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CanonicalSupportProximityThreshold = 0.75f;
}

float UAshenRelationalFlowEvaluatorComponent::CalculateProximityFactorFromDistance(float DistanceUU) const
{
	// Linear decay curve: 1.0 at <= 200.0uu, 0.0 at >= 1000.0uu
	if (DistanceUU <= 200.0f)
	{
		return 1.0f;
	}
	if (DistanceUU >= 1000.0f)
	{
		return 0.0f;
	}
	return 1.0f - ((DistanceUU - 200.0f) / (1000.0f - 200.0f));
}

bool UAshenRelationalFlowEvaluatorComponent::EvaluateCompanionSupportPresent(float ProximityFactor, bool bLineOfSight) const
{
	return (ProximityFactor >= CanonicalSupportProximityThreshold) && bLineOfSight;
}

float UAshenRelationalFlowEvaluatorComponent::EvaluateRelationalFlow(
	float TrioResonance,
	float ImmediateThreat,
	float CompanionProximityFactor,
	bool bCompanionSupportPresent) const
{
	const float ClampedResonance = FMath::Clamp(TrioResonance, 0.0f, 1.0f);
	const float ClampedThreat = FMath::Clamp(ImmediateThreat, 0.0f, 1.0f);
	const float ClampedProximity = FMath::Clamp(CompanionProximityFactor, 0.0f, 1.0f);

	// Formula: TrioResonance*0.60 + (1.0 - Threat*0.20)*Proximity*0.30 + (bSupport ? 0.10 : 0.0)
	const float ThreatFactor = 1.0f - (ClampedThreat * 0.20f);
	const float ProximityTerm = ThreatFactor * ClampedProximity * 0.30f;
	const float SupportBonus = bCompanionSupportPresent ? 0.10f : 0.0f;

	return FMath::Clamp((ClampedResonance * 0.60f) + ProximityTerm + SupportBonus, 0.0f, 1.0f);
}
