// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario9HapticBridge.h"

UAshenScenario9HapticBridge::UAshenScenario9HapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario9HapticBridge::EvaluateCitadelHaptics(
	float GravityScale,
	float WindSpeedMps,
	float BridgeStability01,
	float& OutTriggerResistance,
	float& OutLeftGripWindRumble,
	float& OutRightGripWindRumble,
	float& OutBridgeResonance528Hz) const
{
	// Trigger resistance matches gravity scale (0.05 at 0.1g up to 0.90 at 1.5g)
	OutTriggerResistance = FMath::Clamp((GravityScale - 0.10f) / 1.40f * 0.90f, 0.05f, 0.90f);

	// Wind shear grip vibration
	const float WindIntensity = FMath::Clamp((WindSpeedMps - 10.0f) / 40.0f, 0.0f, 1.0f);
	OutLeftGripWindRumble = WindIntensity * 0.80f;
	OutRightGripWindRumble = WindIntensity * 0.80f;

	// Bridge resonance at 528Hz
	OutBridgeResonance528Hz = BridgeStability01 * 0.75f;
}
