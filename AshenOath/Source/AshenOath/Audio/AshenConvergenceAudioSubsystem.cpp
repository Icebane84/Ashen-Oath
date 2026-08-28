// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenConvergenceAudioSubsystem.h"

UAshenConvergenceAudioSubsystem::UAshenConvergenceAudioSubsystem()
{
}

float UAshenConvergenceAudioSubsystem::EvaluateWhisperSpatialPanAngle(float Sanity) const
{
	const float SafeSanity = FMath::Clamp(Sanity, 0.0f, 100.0f);
	// Lower sanity causes rapid chaotic circular orbit panning (-180 to +180 deg)
	const float Deficit = (100.0f - SafeSanity) / 100.0f;
	return Deficit * 180.0f;
}

float UAshenConvergenceAudioSubsystem::EvaluateWhiteFlameStemGain(bool bFlowStateActive) const
{
	return bFlowStateActive ? 1.0f : 0.20f;
}
