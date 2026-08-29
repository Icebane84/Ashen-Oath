// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenForensicMindscapeAudioSubsystem.h"

UAshenForensicMindscapeAudioSubsystem::UAshenForensicMindscapeAudioSubsystem()
{
}

void UAshenForensicMindscapeAudioSubsystem::EvaluateForensicAcoustics(
	EMemoryReconstructionState State,
	float SynthesisScore,
	float& OutSpectralEmanationGain,
	float& OutEpiphanyHarmonicGain) const
{
	switch (State)
	{
	case EMemoryReconstructionState::ReconstructedTruth:
		OutSpectralEmanationGain = 0.40f;
		OutEpiphanyHarmonicGain = 1.00f; // Full euphoric epiphany swell
		break;

	case EMemoryReconstructionState::DeductionInProgress:
		OutSpectralEmanationGain = FMath::Clamp(SynthesisScore * 0.80f, 0.20f, 0.80f);
		OutEpiphanyHarmonicGain = 0.30f;
		break;

	case EMemoryReconstructionState::UnsolvedFragments:
	default:
		OutSpectralEmanationGain = 0.15f;
		OutEpiphanyHarmonicGain = 0.0f;
		break;
	}
}
