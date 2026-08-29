// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenDestructionWeatherAIHapticBridge.h"

UAshenDestructionWeatherAIHapticBridge::UAshenDestructionWeatherAIHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDestructionWeatherAIHapticBridge::EvaluateTacticalHaptics(
	bool bDirectLightningStrike,
	bool bConductiveArcChained,
	bool bCoverCollapsed,
	float& OutHeavyMotorPunch,
	float& OutLightMotorTingle)
{
	if (bDirectLightningStrike)
	{
		OutHeavyMotorPunch = 0.95f; // Massive sub-bass thunder motor kick
		OutLightMotorTingle = 0.80f;
	}
	else if (bConductiveArcChained)
	{
		OutHeavyMotorPunch = 0.40f;
		OutLightMotorTingle = 0.90f; // Rapid 150Hz electrical tickle
	}
	else if (bCoverCollapsed)
	{
		OutHeavyMotorPunch = 0.70f; // Low-frequency stone thud
		OutLightMotorTingle = 0.35f;
	}
	else
	{
		OutHeavyMotorPunch = 0.0f;
		OutLightMotorTingle = 0.0f;
	}
}
