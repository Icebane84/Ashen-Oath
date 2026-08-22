// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenKineticBerserkHapticBridge.h"

UAshenKineticBerserkHapticBridge::UAshenKineticBerserkHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenKineticBerserkHapticBridge::EvaluateKineticHaptics(
	float KineticJoules,
	float PlayRateModifier,
	float& OutTriggerResistance,
	float& OutSubBassGripVibration) const
{
	// Trigger resistance is inversely proportional to animation play rate (slower play rate = cutting dense stone)
	OutTriggerResistance = FMath::Clamp(1.0f - PlayRateModifier, 0.10f, 0.95f);

	// Sub-bass vibration scales directly with kinetic energy Joules (1000J to 9000J)
	OutSubBassGripVibration = FMath::Clamp((KineticJoules - 1000.0f) / 8000.0f, 0.0f, 1.0f);
}
