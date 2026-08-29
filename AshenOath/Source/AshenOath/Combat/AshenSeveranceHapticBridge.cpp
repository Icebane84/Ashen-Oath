// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSeveranceHapticBridge.h"

UAshenSeveranceHapticBridge::UAshenSeveranceHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSeveranceHapticBridge::EvaluateSeveranceHaptics(
	ESeveranceSeverityTier Severity,
	bool bAdrenalineSurging,
	float& OutHeavyMotorGain,
	float& OutLightMotorGain)
{
	if (bAdrenalineSurging)
	{
		OutHeavyMotorGain = 0.95f;
		OutLightMotorGain = 0.80f; // High adrenaline rush thud
		return;
	}

	switch (Severity)
	{
	case ESeveranceSeverityTier::Decapitation:
	case ESeveranceSeverityTier::TotalBisection:
		OutHeavyMotorGain = 0.95f;
		OutLightMotorGain = 0.70f;
		break;
	case ESeveranceSeverityTier::MajorLimb:
		OutHeavyMotorGain = 0.75f;
		OutLightMotorGain = 0.50f;
		break;
	case ESeveranceSeverityTier::MinorLimb:
	default:
		OutHeavyMotorGain = 0.40f;
		OutLightMotorGain = 0.30f;
		break;
	}
}
