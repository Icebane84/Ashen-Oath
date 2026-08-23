// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenWaystationAudioSubsystem.h"

UAshenWaystationAudioSubsystem::UAshenWaystationAudioSubsystem()
{
}

float UAshenWaystationAudioSubsystem::EvaluateResonanceFrequency(EWaystationRunMode Mode) const
{
	switch (Mode)
	{
	case EWaystationRunMode::RunB_PureGrace:
		return 528.0f; // Solfeggio Miracles & Healing Harmonic
	case EWaystationRunMode::RunA_ShadowHarvest:
		return 396.0f; // Liberation of Guilt & Heavy Metallic Drone
	case EWaystationRunMode::RunD_AvoidantMercy:
		return 432.0f; // Muted Harmonic
	case EWaystationRunMode::RunC_TheSpiral:
	default:
		return 140.0f; // Low Discordant Panic Pulse
	}
}
