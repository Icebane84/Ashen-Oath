// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenRealitySunderingEvaluatorComponent.h"

UAshenRealitySunderingEvaluatorComponent::UAshenRealitySunderingEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenRealitySunderingEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenRealitySunderingEvaluatorComponent::CalculateGeometryDistortion(float IncursionIntensity, float DistanceToNearestRift, float MaxRiftRadius) const
{
	if (DistanceToNearestRift >= MaxRiftRadius || MaxRiftRadius <= 0.0f)
	{
		return FMath::Clamp(IncursionIntensity * 0.3f, 0.0f, 1.0f);
	}

	const float ProximityWeight = 1.0f - (DistanceToNearestRift / MaxRiftRadius);
	const float Combined = (IncursionIntensity * 0.5f) + (ProximityWeight * 0.5f);
	return FMath::Clamp(Combined, 0.0f, 1.0f);
}

float UAshenRealitySunderingEvaluatorComponent::CalculateSunderingDamageMultiplier(float CurrentDebt) const
{
	// Base 1.0x, scaling up to 1.50x at Debt >= 1.0
	const float Multiplier = 1.0f + (FMath::Clamp(CurrentDebt, 0.0f, 1.0f) * 0.50f);
	return Multiplier;
}
