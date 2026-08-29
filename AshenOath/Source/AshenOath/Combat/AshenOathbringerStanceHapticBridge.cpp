// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenOathbringerStanceHapticBridge.h"

UAshenOathbringerStanceHapticBridge::UAshenOathbringerStanceHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenOathbringerStanceHapticBridge::EvaluateStanceHaptics(
	EOathbringerMartialStance Stance,
	bool bCleanFlowCancel,
	float& OutHeavyMotorGain,
	float& OutLightMotorGain)
{
	if (bCleanFlowCancel)
	{
		OutHeavyMotorGain = 0.50f;
		OutLightMotorGain = 0.95f; // Crisp resonant flow ping
		return;
	}

	switch (Stance)
	{
	case EOathbringerMartialStance::VomTag_HighWrath:
		OutHeavyMotorGain = 0.90f; // Heavy low-frequency slam
		OutLightMotorGain = 0.30f;
		break;

	case EOathbringerMartialStance::Mordhau_HalfSword:
		OutHeavyMotorGain = 0.75f;
		OutLightMotorGain = 0.60f; // Blunt armor crunch
		break;

	case EOathbringerMartialStance::Ochs_CrownGuard:
		OutHeavyMotorGain = 0.30f;
		OutLightMotorGain = 0.85f; // Sharp deflection click
		break;

	case EOathbringerMartialStance::Pflug_LowPlow:
	default:
		OutHeavyMotorGain = 0.20f;
		OutLightMotorGain = 0.70f; // Rapid high-frequency pierce
		break;
	}
}
