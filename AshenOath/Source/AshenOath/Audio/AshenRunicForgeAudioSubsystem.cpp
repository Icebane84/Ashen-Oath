// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenRunicForgeAudioSubsystem.h"

UAshenRunicForgeAudioSubsystem::UAshenRunicForgeAudioSubsystem()
{
}

void UAshenRunicForgeAudioSubsystem::EvaluateForgeAcoustics(
	EOathbringerAscensionTier Tier,
	bool bStrikingAnvil,
	float& OutAnvilClangGain,
	float& OutRunicSeamHumGain) const
{
	OutAnvilClangGain = bStrikingAnvil ? 0.95f : 0.0f;

	switch (Tier)
	{
	case EOathbringerAscensionTier::Tier5_GodslayerApex:
		OutRunicSeamHumGain = 0.90f; // Resonant divine hum
		break;
	case EOathbringerAscensionTier::Tier4_EldrinsCrucible:
		OutRunicSeamHumGain = 0.70f;
		break;
	case EOathbringerAscensionTier::Tier3_SunderedSovereign:
		OutRunicSeamHumGain = 0.50f;
		break;
	case EOathbringerAscensionTier::Tier2_AwakenedFuller:
		OutRunicSeamHumGain = 0.30f;
		break;
	case EOathbringerAscensionTier::Tier1_DullNightsteel:
	default:
		OutRunicSeamHumGain = 0.05f;
		break;
	}
}
