// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenStemGainMatrixEvaluator.h"

UAshenStemGainMatrixEvaluator::UAshenStemGainMatrixEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenStemGainMatrixEvaluator::EvaluateStemGain(
	EQuartzAudioStem Stem,
	float Corruption01,
	float Burnout01,
	ECombatFlowState FlowState) const
{
	if (FlowState == ECombatFlowState::SymbioticResonance)
	{
		switch (Stem)
		{
		case EQuartzAudioStem::Stem01_IndustrialDrums: return 0.05f;
		case EQuartzAudioStem::Stem02_NightsteelHum:   return 0.00f; // Silenced!
		case EQuartzAudioStem::Stem03_SoloViolin:      return 1.00f;
		case EQuartzAudioStem::Stem04_ElectricGuitar:  return 1.00f;
		case EQuartzAudioStem::Stem05_PaladinChoir:    return 0.00f;
		case EQuartzAudioStem::Stem06_AfroPopGroove:   return 1.00f;
		default: return 1.0f;
		}
	}

	const float C = FMath::Clamp(Corruption01, 0.0f, 1.0f);
	const float B = FMath::Clamp(Burnout01, 0.0f, 1.0f);

	switch (Stem)
	{
	case EQuartzAudioStem::Stem01_IndustrialDrums:
		return FMath::Clamp(0.10f + (0.90f * C), 0.10f, 1.0f);
	case EQuartzAudioStem::Stem02_NightsteelHum:
		return (C >= 0.25f) ? FMath::Clamp((C - 0.25f) / 0.75f, 0.0f, 1.0f) : 0.0f;
	case EQuartzAudioStem::Stem03_SoloViolin:
		return FMath::Clamp(0.80f - (0.50f * B), 0.30f, 0.80f);
	case EQuartzAudioStem::Stem04_ElectricGuitar:
		return FMath::Clamp(C * 0.70f, 0.0f, 0.70f);
	case EQuartzAudioStem::Stem05_PaladinChoir:
		return FMath::Clamp(1.00f - (0.70f * C), 0.30f, 1.00f);
	case EQuartzAudioStem::Stem06_AfroPopGroove:
		return FMath::Clamp(0.20f + (0.60f * (1.0f - C)), 0.20f, 0.80f);
	default:
		return 1.0f;
	}
}
