// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenSanctuarySurvivalAudioSubsystem.h"

UAshenSanctuarySurvivalAudioSubsystem::UAshenSanctuarySurvivalAudioSubsystem()
{
}

void UAshenSanctuarySurvivalAudioSubsystem::EvaluateShelterAcoustics(
	EThermalShelterTier Tier,
	float& OutWindHowlLowPassHz,
	float& OutCracklingFireGain,
	float& OutSanctuaryPeaceHarmonyGain) const
{
	switch (Tier)
	{
	case EThermalShelterTier::SanctuaryHearthRadius:
		OutWindHowlLowPassHz = 350.0f; // Deeply muffled distant storm
		OutCracklingFireGain = 0.95f;
		OutSanctuaryPeaceHarmonyGain = 1.00f; // Serene sanctuary harmony
		break;

	case EThermalShelterTier::NaturalCavern:
		OutWindHowlLowPassHz = 850.0f; // Muffled cavern wind
		OutCracklingFireGain = 0.60f;
		OutSanctuaryPeaceHarmonyGain = 0.30f;
		break;

	case EThermalShelterTier::OpenWilderness:
	default:
		OutWindHowlLowPassHz = 16000.0f; // Full raw howling blizzard
		OutCracklingFireGain = 0.10f;
		OutSanctuaryPeaceHarmonyGain = 0.0f;
		break;
	}
}
