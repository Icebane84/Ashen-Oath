// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenFallingMasonryHazardEvaluator.h"

UAshenFallingMasonryHazardEvaluator::UAshenFallingMasonryHazardEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenFallingMasonryHazardEvaluator::EvaluateCrushingDamage(float MasonryMassKg, float FallHeightMeters) const
{
	const float SafeMass = FMath::Clamp(MasonryMassKg, 25.0f, 600.0f);
	const float SafeHeight = FMath::Clamp(FallHeightMeters, 2.0f, 20.0f);
	// Dmg = Mass * 1.5 + Height * 25
	const float Damage = (SafeMass * 1.5f) + (SafeHeight * 25.0f);
	return FMath::Clamp(Damage, 250.0f, 1200.0f);
}

float UAshenFallingMasonryHazardEvaluator::EvaluateTelegraphRadius(float MasonryMassKg) const
{
	const float SafeMass = FMath::Clamp(MasonryMassKg, 25.0f, 600.0f);
	// Radius scales from 150uu up to 450uu
	const float Radius = 150.0f + ((SafeMass - 25.0f) / 575.0f) * 300.0f;
	return FMath::Clamp(Radius, 150.0f, 450.0f);
}
