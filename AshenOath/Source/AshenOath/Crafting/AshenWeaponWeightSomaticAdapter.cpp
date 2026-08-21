// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Crafting/AshenWeaponWeightSomaticAdapter.h"

UAshenWeaponWeightSomaticAdapter::UAshenWeaponWeightSomaticAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenWeaponWeightSomaticAdapter::EvaluateSomaticResistance(float EffectiveMassKg) const
{
	// Maps 45kg -> 0.10 resistance, 180kg -> 0.85 resistance
	const float ClampedMass = FMath::Clamp(EffectiveMassKg, 45.0f, 220.0f);
	return FMath::GetMappedRangeValueClamped(
		FVector2D(45.0f, 200.0f),
		FVector2D(0.10f, 0.95f),
		ClampedMass);
}
