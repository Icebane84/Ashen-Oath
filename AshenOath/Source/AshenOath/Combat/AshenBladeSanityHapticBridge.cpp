// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenBladeSanityHapticBridge.h"

UAshenBladeSanityHapticBridge::UAshenBladeSanityHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenBladeSanityHapticBridge::EvaluateConvergenceHaptics(
	float BladeHunger01,
	float CurrentSanity,
	bool bFlowStateActive,
	float& OutBladeHeartbeatGain,
	float& OutSanityDistortionGain,
	float& OutFlowPurrImpulse)
{
	if (bFlowStateActive)
	{
		OutBladeHeartbeatGain = 0.0f;
		OutSanityDistortionGain = 0.0f;
		OutFlowPurrImpulse = 0.85f; // Smooth resonant purr
		return;
	}

	const float SafeHunger = FMath::Clamp(BladeHunger01, 0.0f, 1.0f);
	const float SafeSanity = FMath::Clamp(CurrentSanity, 0.0f, 100.0f);
	const float SanityDeficit = (100.0f - SafeSanity) / 100.0f;

	// Blade hunger low-frequency heartbeat (45Hz)
	OutBladeHeartbeatGain = SafeHunger * 0.90f;

	// Sanity distortion jitter (180Hz)
	OutSanityDistortionGain = SanityDeficit * 0.80f;

	OutFlowPurrImpulse = 0.0f;
}
