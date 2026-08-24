// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenBioAcousticAudioSubsystem.h"

UAshenBioAcousticAudioSubsystem::UAshenBioAcousticAudioSubsystem()
{
}

float UAshenBioAcousticAudioSubsystem::EvaluateHeartStressAudioFilter(float HeartRateBPM) const
{
	// At zen 60 BPM, sound is unoccluded (20000 Hz). At 170 BPM tachycardia, peripheral audio muffles down to 600 Hz
	const float Alpha = FMath::Clamp((HeartRateBPM - 60.0f) / 110.0f, 0.0f, 1.0f);
	return FMath::Lerp(20000.0f, 600.0f, Alpha);
}
