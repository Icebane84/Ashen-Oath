// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenQuartzDissonanceMixEvaluator.generated.h"

/**
 * UAshenQuartzDissonanceMixEvaluator
 * 
 * Computes real-time dynamic audio stem gains, low-pass filter cutoff frequencies, and melodic ducking parameters for Quartz Conductor.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenQuartzDissonanceMixEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenQuartzDissonanceMixEvaluator();

	/** Evaluates Stem 02 (Whispers) gain [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Audio")
	float EvaluateStem02WhisperGain(float CurrentSanity, bool bFlowStateActive) const;

	/** Evaluates Melodic Stem Ducking in decibels [0.0dB to -18.0dB] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Audio")
	float EvaluateMelodicDuckingDb(float CurrentSanity, bool bFlowStateActive) const;

	/** Evaluates Low Pass Filter Cutoff Frequency in Hz [300Hz to 8000Hz] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Audio")
	float EvaluateAudioLpfCutoffHz(float CurrentSanity) const;
};
