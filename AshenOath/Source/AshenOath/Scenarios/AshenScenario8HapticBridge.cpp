// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario8HapticBridge.h"

UAshenScenario8HapticBridge::UAshenScenario8HapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario8HapticBridge::EvaluateAbyssHaptics(
	ELightEnvironmentState LightState,
	float SonarRadiusUU,
	float LurkerProximityDistanceUU,
	float& OutLurkerHeartbeat40Hz,
	float& OutLeftTriggerDarknessFear,
	float& OutSonarTactileTick) const
{
	// Lurker proximity heartbeat: 1.0 at 0uu, drops to 0.0 at 800uu
	const float ProximityAlpha = FMath::Clamp(1.0f - (LurkerProximityDistanceUU / 800.0f), 0.0f, 1.0f);
	OutLurkerHeartbeat40Hz = ProximityAlpha * 0.85f;

	// Darkness fear resistance on left trigger
	if (LightState == ELightEnvironmentState::PitchBlackDarkness)
	{
		OutLeftTriggerDarknessFear = 0.90f;
	}
	else if (LightState == ELightEnvironmentState::GloomPerimeter)
	{
		OutLeftTriggerDarknessFear = 0.50f;
	}
	else
	{
		OutLeftTriggerDarknessFear = 0.0f;
	}

	// Sonar tactile tick
	OutSonarTactileTick = FMath::Clamp(SonarRadiusUU / 1800.0f, 0.0f, 1.0f);
}
