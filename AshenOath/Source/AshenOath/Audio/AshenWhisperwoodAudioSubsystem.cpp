// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenWhisperwoodAudioSubsystem.h"

UAshenWhisperwoodAudioSubsystem::UAshenWhisperwoodAudioSubsystem()
{
}

float UAshenWhisperwoodAudioSubsystem::EvaluateWhisperPitchWarble(float Sanity) const
{
	const float ClampedSanity = FMath::Clamp(Sanity, 0.0f, 1.0f);
	// Low sanity = deep erratic pitch warbles (up to 0.40 pitch variance)
	return (1.0f - ClampedSanity) * 0.40f;
}
