// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenMassKineticAudioSubsystem.h"

UAshenMassKineticAudioSubsystem::UAshenMassKineticAudioSubsystem()
{
}

float UAshenMassKineticAudioSubsystem::CalculateWhooshPitch(float WeaponMassKG, float TipVelocity) const
{
	// Heavier weapon lowers pitch (180kg lowers down to 0.65x)
	const float MassDowntune = FMath::Clamp(1.0f - (WeaponMassKG / 300.0f), 0.50f, 1.0f);
	return MassDowntune;
}

float UAshenMassKineticAudioSubsystem::CalculateImpactBassBoost(float EnergyJoules) const
{
	// Sub-bass boost scales with energy, up to 2.5x
	const float Boost = FMath::Clamp(1.0f + (EnergyJoules / 5000.0f) * 1.5f, 1.0f, 2.5f);
	return Boost;
}
