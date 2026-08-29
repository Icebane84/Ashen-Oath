// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenOathbringerStanceAudioSubsystem.generated.h"

/**
 * UAshenOathbringerStanceAudioSubsystem
 * 
 * Synthesizes dynamic MetaSounds acoustic layers for Vom Tag deep swooshes (90Hz), Pflug piercing whistles (3.2kHz), Ochs steel binds (880Hz), Mordhau pommel crunches, and Flow Glint chimes.
 */
UCLASS()
class ASHENOATH_API UAshenOathbringerStanceAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenOathbringerStanceAudioSubsystem();

	/** Evaluates acoustic parameters for active stance strike */
	UFUNCTION(BlueprintPure, Category = "Ashen|Oathbringer|Audio")
	void EvaluateStanceAcoustics(
		EOathbringerMartialStance Stance,
		float& OutSwingPitchMultiplier,
		float& OutImpactLowBassGain,
		float& OutMetallicChimeGain) const;
};
