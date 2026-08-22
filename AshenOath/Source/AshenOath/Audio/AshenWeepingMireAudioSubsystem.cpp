// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenWeepingMireAudioSubsystem.h"

UAshenWeepingMireAudioSubsystem::UAshenWeepingMireAudioSubsystem()
{
}

float UAshenWeepingMireAudioSubsystem::EvaluateHeartThumpPitch(float HeartRateBPM) const
{
	// Elevated heart rate = higher visceral thump frequency (55 Hz to 95 Hz sub-bass)
	const float Normalized = FMath::Clamp((HeartRateBPM - 60.0f) / 120.0f, 0.0f, 1.0f);
	return 55.0f + (Normalized * 40.0f);
}
