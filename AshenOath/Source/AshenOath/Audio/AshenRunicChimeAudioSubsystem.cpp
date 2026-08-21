// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenRunicChimeAudioSubsystem.h"

UAshenRunicChimeAudioSubsystem::UAshenRunicChimeAudioSubsystem()
{
}

float UAshenRunicChimeAudioSubsystem::EvaluateRunicPitchHz(ESoulForgeAttunementTier Tier) const
{
	switch (Tier)
	{
	case ESoulForgeAttunementTier::Resonant:
		return 528.0f; // Solfeggio Love/Repair tone
	case ESoulForgeAttunementTier::Overcharged:
		return 741.0f; // Intuition tone
	case ESoulForgeAttunementTier::MasterForged:
		return 852.0f; // Spiritual return tone (Boss core)
	case ESoulForgeAttunementTier::Dormant:
	default:
		return 220.0f;
	}
}
