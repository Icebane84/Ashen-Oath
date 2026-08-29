// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSanctuarySurvivalHapticBridge.h"

UAshenSanctuarySurvivalHapticBridge::UAshenSanctuarySurvivalHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSanctuarySurvivalHapticBridge::EvaluateSurvivalHaptics(
	EThermalShelterTier Tier,
	float BodyTempC,
	float& OutHeavyMotorGain,
	float& OutLightMotorGain)
{
	if (Tier == EThermalShelterTier::SanctuaryHearthRadius)
	{
		OutHeavyMotorGain = 0.20f;
		OutLightMotorGain = 0.40f; // Gentle warm rhythmic hearth breathing
		return;
	}

	if (BodyTempC < 35.0f)
	{
		OutHeavyMotorGain = 0.65f;
		OutLightMotorGain = 0.85f; // Rapid shivering cold jitter
		return;
	}

	OutHeavyMotorGain = 0.10f;
	OutLightMotorGain = 0.10f;
}
