// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenCampfireAudioSubsystem.h"

UAshenCampfireAudioSubsystem::UAshenCampfireAudioSubsystem()
{
}

float UAshenCampfireAudioSubsystem::EvaluateBoilingBubbleGain(float TemperatureCelsius) const
{
	if (TemperatureCelsius < 60.0f)
	{
		return 0.0f;
	}

	const float SafeTemp = FMath::Clamp(TemperatureCelsius, 60.0f, 100.0f);
	return (SafeTemp - 60.0f) / 40.0f; // 0.0 to 1.0
}

float UAshenCampfireAudioSubsystem::EvaluateEmberCrackleVolume(ECookingPotState PotState) const
{
	return (PotState != ECookingPotState::EmptyCold) ? 0.75f : 0.20f;
}
