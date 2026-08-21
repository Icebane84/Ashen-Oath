// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenHarmonizedAudioSubsystem.h"

UAshenHarmonizedAudioSubsystem::UAshenHarmonizedAudioSubsystem()
{
}

float UAshenHarmonizedAudioSubsystem::CalculateResonanceCrescendoGain(ETripartiteComboPhase Phase) const
{
	switch (Phase)
	{
	case ETripartiteComboPhase::Step1_KaelenCleave:
		return 1.20f;
	case ETripartiteComboPhase::Step2_GarrettSnare:
		return 1.50f;
	case ETripartiteComboPhase::FinisherReady:
		return 2.00f; // Max harmonic resonance volume
	default:
		return 1.00f;
	}
}
