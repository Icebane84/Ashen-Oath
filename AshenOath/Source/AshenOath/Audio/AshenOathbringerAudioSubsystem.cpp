// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenOathbringerAudioSubsystem.h"

UAshenOathbringerAudioSubsystem::UAshenOathbringerAudioSubsystem()
{
}

float UAshenOathbringerAudioSubsystem::EvaluateNightsteelHumGain(float Corruption01, bool bIsFrozen) const
{
	if (bIsFrozen)
	{
		return 0.0f; // Silenced when chemically frozen
	}

	return FMath::Clamp(Corruption01, 0.0f, 1.0f);
}

float UAshenOathbringerAudioSubsystem::EvaluateBloodChillPitchSemitones(bool bIsFrozen) const
{
	return bIsFrozen ? -12.0f : 0.0f;
}
