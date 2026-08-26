// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenRubbleClearingDirectorComponent.h"

UAshenRubbleClearingDirectorComponent::UAshenRubbleClearingDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenRubbleClearingDirectorComponent::EvaluateDemolitionEfficiency(bool bThermalShockActive) const
{
	// Thermal shock increases demolition speed and damage by 60%
	return bThermalShockActive ? 1.60f : 1.00f;
}

FVector UAshenRubbleClearingDirectorComponent::EvaluateScatterVelocity(
	const FVector& ImpactNormal,
	float ExplosiveYield) const
{
	const float SafeYield = FMath::Clamp(ExplosiveYield, 100.0f, 2000.0f);
	return (ImpactNormal + FVector(0.0f, 0.0f, 0.5f)).GetSafeNormal() * SafeYield;
}
