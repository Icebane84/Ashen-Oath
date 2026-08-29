// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenAlchemicalSlagAudioSubsystem.generated.h"

/**
 * UAshenAlchemicalSlagAudioSubsystem
 * 
 * Synthesizes dynamic MetaSounds acoustic layers for flask applications, thermal slag sizzles (3.4kHz), Conflagration deflagration booms (60Hz sub-bass), and Thermal Shock crystalline shattering.
 */
UCLASS()
class ASHENOATH_API UAshenAlchemicalSlagAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenAlchemicalSlagAudioSubsystem();

	/** Evaluates acoustic parameters for chemical/thermal reactions */
	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag|Audio")
	void EvaluateReactionAcoustics(
		EThermalReactionType Reaction,
		float& OutExplosionBassGain,
		float& OutLiquidSizzleGain,
		float& OutShatterPitchMultiplier) const;
};
