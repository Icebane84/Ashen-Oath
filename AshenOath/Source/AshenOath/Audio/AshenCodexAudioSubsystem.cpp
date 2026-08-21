// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenCodexAudioSubsystem.h"

UAshenCodexAudioSubsystem::UAshenCodexAudioSubsystem()
{
}

float UAshenCodexAudioSubsystem::EvaluateRelicHumPitchHz(ERelicRarityTier Rarity) const
{
	switch (Rarity)
	{
	case ERelicRarityTier::RareArtifact:
		return 528.0f; // Solfeggio 528 Hz (Repair/Love)
	case ERelicRarityTier::SacredHeirloom:
		return 741.0f; // Solfeggio 741 Hz (Intuition)
	case ERelicRarityTier::TitanCoreRelic:
		return 852.0f; // Solfeggio 852 Hz (Spiritual Order)
	case ERelicRarityTier::CommonRelic:
	default:
		return 396.0f; // Solfeggio 396 Hz (Grounding)
	}
}
