// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenWaystationHapticBridge.h"

UAshenWaystationHapticBridge::UAshenWaystationHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWaystationHapticBridge::EvaluateWaystationHaptics(
	EWaystationRunMode Mode,
	float& OutLeftTriggerResistance,
	float& OutRightTactileTremor) const
{
	switch (Mode)
	{
	case EWaystationRunMode::RunB_PureGrace:
		OutLeftTriggerResistance = 0.85f; // Solid twin-blade X-lock torque
		OutRightTactileTremor = 0.05f;    // Calm steady grip
		break;
	case EWaystationRunMode::RunA_ShadowHarvest:
		OutLeftTriggerResistance = 0.50f; // Moderate resistance
		OutRightTactileTremor = 0.30f;    // Dark ash humming vibration
		break;
	case EWaystationRunMode::RunC_TheSpiral:
		OutLeftTriggerResistance = 0.20f; // Erratic loose grip
		OutRightTactileTremor = 0.95f;    // High-frequency panic tremor
		break;
	case EWaystationRunMode::RunD_AvoidantMercy:
	default:
		OutLeftTriggerResistance = 0.40f; // Guarded resistance
		OutRightTactileTremor = 0.45f;    // Nervous hesitation pulse
		break;
	}
}
