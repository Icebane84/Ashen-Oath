// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenScenario9AudioSubsystem.h"

UAshenScenario9AudioSubsystem::UAshenScenario9AudioSubsystem()
{
}

float UAshenScenario9AudioSubsystem::EvaluateWindHowlFrequency(float WindSpeedMps) const
{
	// 5 m/s to 50 m/s scales 180Hz to 950Hz
	const float Alpha = FMath::Clamp((WindSpeedMps - 5.0f) / 45.0f, 0.0f, 1.0f);
	return FMath::Lerp(180.0f, 950.0f, Alpha);
}
