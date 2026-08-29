// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenForensicMindscapeHapticBridge.h"

UAshenForensicMindscapeHapticBridge::UAshenForensicMindscapeHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenForensicMindscapeHapticBridge::EvaluateForensicHaptics(
	EMemoryReconstructionState State,
	bool bPinningClue,
	float& OutHeavyMotorGain,
	float& OutLightMotorGain)
{
	if (State == EMemoryReconstructionState::ReconstructedTruth)
	{
		OutHeavyMotorGain = 0.90f;
		OutLightMotorGain = 0.95f; // Euphoric epiphany breakthrough surge
		return;
	}

	if (bPinningClue)
	{
		OutHeavyMotorGain = 0.35f;
		OutLightMotorGain = 0.65f; // Sharp crisp mechanical pin snap
		return;
	}

	OutHeavyMotorGain = 0.10f;
	OutLightMotorGain = 0.25f; // Subtle magnifying glass tick
}
