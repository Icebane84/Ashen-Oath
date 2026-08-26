// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenWeatherAudioSubsystem.h"

UAshenWeatherAudioSubsystem::UAshenWeatherAudioSubsystem()
{
}

float UAshenWeatherAudioSubsystem::EvaluateBlizzardWindGain(
	EWeatherHazardState State,
	float WindShearMps) const
{
	if (State != EWeatherHazardState::BlizzardWhiteout)
	{
		return 0.0f;
	}

	const float SafeWind = FMath::Clamp(WindShearMps, 0.0f, 40.0f);
	return SafeWind / 40.0f; // 0.0 to 1.0
}

float UAshenWeatherAudioSubsystem::EvaluateAcidRainHissGain(EWeatherHazardState State) const
{
	return (State == EWeatherHazardState::AcidRainCorrosion) ? 0.85f : 0.0f;
}
