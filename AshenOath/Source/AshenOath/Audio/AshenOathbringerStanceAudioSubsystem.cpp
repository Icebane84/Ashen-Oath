// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenOathbringerStanceAudioSubsystem.h"

UAshenOathbringerStanceAudioSubsystem::UAshenOathbringerStanceAudioSubsystem()
{
}

void UAshenOathbringerStanceAudioSubsystem::EvaluateStanceAcoustics(
	EOathbringerMartialStance Stance,
	float& OutSwingPitchMultiplier,
	float& OutImpactLowBassGain,
	float& OutMetallicChimeGain) const
{
	switch (Stance)
	{
	case EOathbringerMartialStance::VomTag_HighWrath:
		OutSwingPitchMultiplier = 0.80f; // Deep, heavy swoosh
		OutImpactLowBassGain = 1.00f;
		OutMetallicChimeGain = 0.20f;
		break;

	case EOathbringerMartialStance::Pflug_LowPlow:
		OutSwingPitchMultiplier = 1.25f; // Fast, high-frequency whip
		OutImpactLowBassGain = 0.30f;
		OutMetallicChimeGain = 0.60f;
		break;

	case EOathbringerMartialStance::Ochs_CrownGuard:
		OutSwingPitchMultiplier = 1.00f;
		OutImpactLowBassGain = 0.40f;
		OutMetallicChimeGain = 0.95f; // Pure 880Hz ringing steel bind
		break;

	case EOathbringerMartialStance::Mordhau_HalfSword:
	default:
		OutSwingPitchMultiplier = 0.90f;
		OutImpactLowBassGain = 0.90f; // Dull, heavy pommel thud
		OutMetallicChimeGain = 0.45f;
		break;
	}
}
