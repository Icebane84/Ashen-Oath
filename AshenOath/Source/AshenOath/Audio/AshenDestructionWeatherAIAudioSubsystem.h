// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenDestructionWeatherAIAudioSubsystem.generated.h"

/**
 * UAshenDestructionWeatherAIAudioSubsystem
 * 
 * Synthesizes dynamic MetaSounds acoustic layers for 45Hz sub-bass thunderclaps, sizzling conductive electric chain arcs (2.4kHz), and stone rubble collapse Foley.
 */
UCLASS()
class ASHENOATH_API UAshenDestructionWeatherAIAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenDestructionWeatherAIAudioSubsystem();

	/** Evaluates acoustic parameters for conductive lightning discharge */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Audio")
	void EvaluateLightningAcoustics(
		bool bConductiveSurface,
		float& OutThunderVolume,
		float& OutElectricArcSizzleGain,
		float& OutDebrisRumbleGain) const;
};
