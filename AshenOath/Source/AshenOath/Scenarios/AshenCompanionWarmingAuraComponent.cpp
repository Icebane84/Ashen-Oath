// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenCompanionWarmingAuraComponent.h"

UAshenCompanionWarmingAuraComponent::UAshenCompanionWarmingAuraComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	WarmingRadiusUU = 350.0f;
	ThermalHeatOutputCelsius = 25.0f;
}

bool UAshenCompanionWarmingAuraComponent::IsActorWithinWarmthRadius(
	const FVector& SourceLocation,
	const FVector& TargetLocation) const
{
	const float DistSq = FVector::DistSquared(SourceLocation, TargetLocation);
	return DistSq <= FMath::Square(WarmingRadiusUU);
}
