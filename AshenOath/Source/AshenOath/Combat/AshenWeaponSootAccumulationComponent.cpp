// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenWeaponSootAccumulationComponent.h"

UAshenWeaponSootAccumulationComponent::UAshenWeaponSootAccumulationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	BladeSootScalar = 0.0f;
	CumulativeStrikeJoules = 0.0f;
	MicroNickCount = 0;
}

void UAshenWeaponSootAccumulationComponent::RecordStrikeEnergy(float Joules)
{
	CumulativeStrikeJoules += Joules;
	const float AddedSoot = (Joules / 5000.0f) * 0.05f;
	BladeSootScalar = FMath::Clamp(BladeSootScalar + AddedSoot, 0.0f, 1.0f);

	if (Joules >= 2500.0f)
	{
		MicroNickCount++;
	}
}

void UAshenWeaponSootAccumulationComponent::CleanBlade()
{
	BladeSootScalar = 0.0f;
}
