// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenScenario6AudioSubsystem.h"

UAshenScenario6AudioSubsystem::UAshenScenario6AudioSubsystem()
{
}

float UAshenScenario6AudioSubsystem::EvaluateBlizzardWindVolume(EBlizzardIntensity Intensity) const
{
	switch (Intensity)
	{
	case EBlizzardIntensity::CalmChill:
		return 0.20f;
	case EBlizzardIntensity::DrivingSnow:
		return 0.50f;
	case EBlizzardIntensity::SevereBlizzard:
		return 0.80f;
	case EBlizzardIntensity::WhiteoutSurge:
		return 1.00f;
	default:
		return 0.50f;
	}
}

float UAshenScenario6AudioSubsystem::EvaluateHearthFireVolume(float IgnitionProgress) const
{
	return FMath::Clamp(IgnitionProgress, 0.0f, 1.0f);
}
