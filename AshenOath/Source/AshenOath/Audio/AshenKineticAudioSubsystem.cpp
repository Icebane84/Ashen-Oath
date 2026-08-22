// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenKineticAudioSubsystem.h"

UAshenKineticAudioSubsystem::UAshenKineticAudioSubsystem()
{
}

float UAshenKineticAudioSubsystem::EvaluateKineticPitchMultiplier(float KineticEnergyJoules) const
{
	// Heavy kinetic energy (>5000J) down-tunes pitch from 1.0x down to 0.70x for massive weight
	const float Normalized = FMath::Clamp((KineticEnergyJoules - 1000.0f) / 9000.0f, 0.0f, 1.0f);
	return 1.0f - (Normalized * 0.30f);
}
