// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenTacticalAudioSubsystem.generated.h"

/**
 * UAshenTacticalAudioSubsystem
 * 
 * Manages low-pass filter sweeps during temporal bullet-time and tactical order confirmation chimes.
 */
UCLASS()
class ASHENOATH_API UAshenTacticalAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenTacticalAudioSubsystem();

	/** Evaluates the low-pass filter cutoff (Hz) for temporal dilation */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Tactics")
	float EvaluateTemporalFilterCutoff(ETemporalDilationState State) const;
};
