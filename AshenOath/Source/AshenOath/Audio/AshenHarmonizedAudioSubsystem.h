// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenHarmonizedAudioSubsystem.generated.h"

/**
 * UAshenHarmonizedAudioSubsystem
 * 
 * Synthesizes 60 BPM rhythmic pulse chords (1.0 Hz) and dynamic crescendos
 * during Tripartite combo progression.
 */
UCLASS()
class ASHENOATH_API UAshenHarmonizedAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenHarmonizedAudioSubsystem();

	/** Evaluates chord frequency and volume based on combo progression */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Trio")
	float CalculateResonanceCrescendoGain(ETripartiteComboPhase Phase) const;
};
