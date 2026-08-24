// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenAlchemicalAudioFilterEvaluator.generated.h"

/**
 * UAshenAlchemicalAudioFilterEvaluator
 * 
 * Computes frequency cutoff values (Hz), side-chain ducking gain (dB), and pitch offsets for Garrett's tactical interventions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalAudioFilterEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAlchemicalAudioFilterEvaluator();

	/** Evaluates Low-Pass Filter cutoff frequency in Hz [450Hz to 20000Hz] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Filter")
	float EvaluateLPFCutoffHz(EAlchemicalAudioFilter Filter) const;

	/** Evaluates master side-chain ducking gain in dB [-24.0dB to 0.0dB] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Filter")
	float EvaluateSideChainDuckingDB(EAlchemicalAudioFilter Filter) const;

	/** Evaluates pitch offset in semitones [0.0 to -12.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Filter")
	float EvaluatePitchOffsetSemitones(EAlchemicalAudioFilter Filter) const;
};
