// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenDualSenseHapticResonanceComponent.h"

UAshenDualSenseHapticResonanceComponent::UAshenDualSenseHapticResonanceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FHapticResonanceProfile UAshenDualSenseHapticResonanceComponent::EvaluateHapticProfile(ETripartiteComboPhase Phase) const
{
	FHapticResonanceProfile Profile;
	Profile.PulseFrequencyHz = 1.0f; // 60 BPM

	switch (Phase)
	{
	case ETripartiteComboPhase::Step1_KaelenCleave:
		Profile.LeftTriggerResistance = 0.60f;
		Profile.RightTriggerResistance = 0.40f;
		Profile.VibrationIntensity = 0.60f;
		break;
	case ETripartiteComboPhase::Step2_GarrettSnare:
		Profile.LeftTriggerResistance = 0.75f;
		Profile.RightTriggerResistance = 0.60f;
		Profile.VibrationIntensity = 0.80f;
		break;
	case ETripartiteComboPhase::FinisherReady:
		Profile.LeftTriggerResistance = 1.00f; // Max resistance click
		Profile.RightTriggerResistance = 1.00f;
		Profile.VibrationIntensity = 1.00f; // Full resonance crescendo
		break;
	default:
		Profile.LeftTriggerResistance = 0.20f;
		Profile.RightTriggerResistance = 0.20f;
		Profile.VibrationIntensity = 0.20f;
		break;
	}

	return Profile;
}
