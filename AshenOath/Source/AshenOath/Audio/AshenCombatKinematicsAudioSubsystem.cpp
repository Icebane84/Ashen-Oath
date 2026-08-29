// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenCombatKinematicsAudioSubsystem.h"

UAshenCombatKinematicsAudioSubsystem::UAshenCombatKinematicsAudioSubsystem()
{
}

void UAshenCombatKinematicsAudioSubsystem::EvaluateArmorRollAudio(
	EAshenWeightClass WeightClass,
	float& OutPitch,
	float& OutVolume) const
{
	switch (WeightClass)
	{
	case EAshenWeightClass::LightLoad:
		OutPitch = 1.30f;
		OutVolume = 0.40f;
		break;
	case EAshenWeightClass::HeavyLoad:
		OutPitch = 0.75f;
		OutVolume = 0.95f;
		break;
	case EAshenWeightClass::Overburdened:
		OutPitch = 0.60f;
		OutVolume = 1.00f;
		break;
	case EAshenWeightClass::MediumLoad:
	default:
		OutPitch = 1.00f;
		OutVolume = 0.70f;
		break;
	}
}

float UAshenCombatKinematicsAudioSubsystem::EvaluateParryChimePitchHz(EParryRiposteQuality Quality) const
{
	switch (Quality)
	{
	case EParryRiposteQuality::PerfectRiposte:
		return 880.0f; // Pure A5 chime
	case EParryRiposteQuality::StandardParry:
		return 660.0f;
	case EParryRiposteQuality::GlancingBlock:
		return 440.0f;
	case EParryRiposteQuality::MissedDeflection:
	default:
		return 220.0f;
	}
}
