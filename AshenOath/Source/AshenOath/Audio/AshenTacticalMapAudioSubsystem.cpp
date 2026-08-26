// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenTacticalMapAudioSubsystem.h"

UAshenTacticalMapAudioSubsystem::UAshenTacticalMapAudioSubsystem()
{
}

float UAshenTacticalMapAudioSubsystem::EvaluateBeaconResonanceGain(EWaypointBeaconState BeaconState) const
{
	switch (BeaconState)
	{
	case EWaypointBeaconState::AttunedSanctuary:
		return 0.85f; // Strong 432Hz harmonic hum
	case EWaypointBeaconState::DiscoveredBeacon:
		return 0.35f;
	case EWaypointBeaconState::ContestedCorrupted:
	case EWaypointBeaconState::UndiscoveredShadow:
	default:
		return 0.0f;
	}
}

float UAshenTacticalMapAudioSubsystem::EvaluateTeleportWhooshFrequency(float ChannelProgress01) const
{
	const float SafeProg = FMath::Clamp(ChannelProgress01, 0.0f, 1.0f);
	return 200.0f + (SafeProg * 1000.0f); // 200Hz rising to 1200Hz
}
