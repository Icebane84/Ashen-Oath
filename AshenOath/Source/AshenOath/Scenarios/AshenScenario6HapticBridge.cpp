// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario6HapticBridge.h"

UAshenScenario6HapticBridge::UAshenScenario6HapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario6HapticBridge::EvaluateScenario6Haptics(
	float FrostbiteGauge,
	float HearthIgnition,
	bool bInWarmth,
	float& OutLeftGripFrostShiver,
	float& OutRightGripHearthWarmth,
	float& OutFrozenTriggerResistance) const
{
	const float SafeFrostbite = FMath::Clamp(FrostbiteGauge, 0.0f, 1.0f);
	const float SafeHearth = FMath::Clamp(HearthIgnition, 0.0f, 1.0f);

	// Shiver intensity scales with frostbite if not in warmth
	OutLeftGripFrostShiver = bInWarmth ? 0.0f : (SafeFrostbite * 0.80f);

	// Hearth warmth pulse on right grip
	OutRightGripHearthWarmth = SafeHearth * 0.70f;

	// Stiff frozen trigger resistance proportional to frostbite
	OutFrozenTriggerResistance = SafeFrostbite * 0.75f;
}
