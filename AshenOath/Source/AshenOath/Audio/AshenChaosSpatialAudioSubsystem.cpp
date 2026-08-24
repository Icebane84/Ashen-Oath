// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenChaosSpatialAudioSubsystem.h"

UAshenChaosSpatialAudioSubsystem::UAshenChaosSpatialAudioSubsystem()
{
}

float UAshenChaosSpatialAudioSubsystem::EvaluateOccludedAudioLPF(float RubbleMassKg) const
{
	// As rubble mass increases to 250kg, LPF drops from 20000Hz down to 500Hz
	const float OcclusionAlpha = FMath::Clamp(RubbleMassKg / 250.0f, 0.0f, 1.0f);
	return FMath::Lerp(20000.0f, 500.0f, OcclusionAlpha);
}
