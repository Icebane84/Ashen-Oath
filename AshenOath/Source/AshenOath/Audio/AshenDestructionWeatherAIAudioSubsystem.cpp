// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenDestructionWeatherAIAudioSubsystem.h"

UAshenDestructionWeatherAIAudioSubsystem::UAshenDestructionWeatherAIAudioSubsystem()
{
}

void UAshenDestructionWeatherAIAudioSubsystem::EvaluateLightningAcoustics(
	bool bConductiveSurface,
	float& OutThunderVolume,
	float& OutElectricArcSizzleGain,
	float& OutDebrisRumbleGain) const
{
	OutThunderVolume = 1.0f; // Full power 45Hz sub-bass strike
	OutDebrisRumbleGain = 0.75f;

	if (bConductiveSurface)
	{
		OutElectricArcSizzleGain = 0.95f; // Sizzling high-frequency electricity
	}
	else
	{
		OutElectricArcSizzleGain = 0.10f;
	}
}
