// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenFogOfWarCartographyEvaluator.h"

UAshenFogOfWarCartographyEvaluator::UAshenFogOfWarCartographyEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenFogOfWarCartographyEvaluator::EvaluateFogUnveilRadius(
	float ElevationZ,
	bool bHasTorchLit,
	bool bIsLookoutPoint) const
{
	if (bIsLookoutPoint)
	{
		return 3500.0f; // High-ground vantage reveal
	}

	float BaseRadius = 800.0f;
	if (bHasTorchLit)
	{
		BaseRadius += 400.0f;
	}

	// Elevation scaling (up to +600uu)
	const float ElevationBonus = FMath::Clamp(ElevationZ / 500.0f * 200.0f, 0.0f, 600.0f);
	return FMath::Clamp(BaseRadius + ElevationBonus, 500.0f, 2500.0f);
}

bool UAshenFogOfWarCartographyEvaluator::IsLocationUnveiled(
	const FVector& Center,
	float UnveilRadius,
	const FVector& QueryLocation) const
{
	return FVector::DistSquared2D(Center, QueryLocation) <= (UnveilRadius * UnveilRadius);
}
