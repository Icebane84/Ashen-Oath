// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario10HapticBridge.h"

UAshenScenario10HapticBridge::UAshenScenario10HapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario10HapticBridge::EvaluateZenithHaptics(
	float Resonance01,
	float TrustScore01,
	float Debt01,
	float& OutSynchronizedTriggerPulse60BPM,
	float& OutLeftMotorPurity639Hz,
	float& OutRightMotorKinetic396Hz,
	FLinearColor& OutTouchpadLEDColor) const
{
	const float SafeRes = FMath::Clamp(Resonance01, 0.0f, 1.0f);

	// 60 BPM trigger pulse scales with apotheosis resonance
	OutSynchronizedTriggerPulse60BPM = SafeRes * 0.95f;

	// Left motor purity (639Hz) driven by trust score
	OutLeftMotorPurity639Hz = FMath::Clamp(TrustScore01, 0.0f, 1.0f) * 0.85f;

	// Right motor kinetic grounding (396Hz) driven by debt / kinetic force
	OutRightMotorKinetic396Hz = FMath::Clamp(Debt01, 0.0f, 1.0f) * 0.85f;

	// Touchpad LED color blends between Gold (Transfiguration), Red (Hegemony), Grey (Fracture), Purple (Eclipse)
	if (Debt01 >= 0.85f)
	{
		OutTouchpadLEDColor = FLinearColor(0.5f, 0.0f, 1.0f); // Purple Eclipse
	}
	else if (TrustScore01 < 0.40f)
	{
		OutTouchpadLEDColor = FLinearColor(0.3f, 0.3f, 0.3f); // Grey Fracture
	}
	else if (TrustScore01 < 0.75f)
	{
		OutTouchpadLEDColor = FLinearColor(1.0f, 0.2f, 0.0f); // Red Hegemony
	}
	else
	{
		OutTouchpadLEDColor = FLinearColor(1.0f, 0.84f, 0.0f); // Gold Radiant Transfiguration
	}
}
