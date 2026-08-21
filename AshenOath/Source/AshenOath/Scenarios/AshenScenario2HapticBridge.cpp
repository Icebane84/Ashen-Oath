// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario2HapticBridge.h"

UAshenScenario2HapticBridge::UAshenScenario2HapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario2HapticBridge::EvaluateDualChannelHaptics(
	float CorruptionLevel,
	bool bPhosphorFlareActive,
	float& OutLeftRumble,
	float& OutRightSpark) const
{
	// Left Motor = Low-frequency Corruption sub-rumble
	OutLeftRumble = FMath::Clamp(CorruptionLevel * 0.85f, 0.0f, 1.0f);

	// Right Motor = Crisp White Flame high-frequency spark
	OutRightSpark = bPhosphorFlareActive ? 0.90f : 0.05f;
}
