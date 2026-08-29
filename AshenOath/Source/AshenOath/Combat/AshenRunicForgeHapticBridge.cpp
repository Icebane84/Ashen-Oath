// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenRunicForgeHapticBridge.h"

UAshenRunicForgeHapticBridge::UAshenRunicForgeHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRunicForgeHapticBridge::EvaluateForgeHaptics(
	bool bAnvilStrike,
	bool bFlowResonating,
	float& OutHeavyMotorGain,
	float& OutLightMotorGain)
{
	if (bFlowResonating)
	{
		OutHeavyMotorGain = 0.95f;
		OutLightMotorGain = 0.90f; // Massive dual-sigil finisher shockwave
		return;
	}

	if (bAnvilStrike)
	{
		OutHeavyMotorGain = 0.85f;
		OutLightMotorGain = 0.40f; // Heavy ringing hammer blow
		return;
	}

	OutHeavyMotorGain = 0.10f;
	OutLightMotorGain = 0.10f;
}
