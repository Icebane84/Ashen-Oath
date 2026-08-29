// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenCSEHapticBridge.h"

UAshenCSEHapticBridge::UAshenCSEHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCSEHapticBridge::EvaluateCSEHaptics(
	float DissonanceIndex,
	float& OutConsensusPurrGain,
	float& OutFrictionPulseGain)
{
	const float SafeD = FMath::Clamp(DissonanceIndex, 0.0f, 1.0f);

	if (SafeD < 0.25f)
	{
		OutConsensusPurrGain = 0.85f; // Smooth 60Hz resonance
		OutFrictionPulseGain = 0.0f;
	}
	else
	{
		OutConsensusPurrGain = 0.0f;
		OutFrictionPulseGain = SafeD * 0.90f; // 120Hz friction vibration
	}
}
