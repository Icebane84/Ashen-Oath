// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenForensicMindscapeAudioSubsystem.generated.h"

/**
 * UAshenForensicMindscapeAudioSubsystem
 * 
 * Synthesizes dynamic MetaSounds acoustic layers for forensic investigations: Scratching ink quill notes, 2.1kHz ethereal glass chime clue pings, and radiant epiphany chord swells.
 */
UCLASS()
class ASHENOATH_API UAshenForensicMindscapeAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenForensicMindscapeAudioSubsystem();

	/** Evaluates investigation acoustic gains */
	UFUNCTION(BlueprintPure, Category = "Ashen|Forensic|Audio")
	void EvaluateForensicAcoustics(
		EMemoryReconstructionState State,
		float SynthesisScore,
		float& OutSpectralEmanationGain,
		float& OutEpiphanyHarmonicGain) const;
};
