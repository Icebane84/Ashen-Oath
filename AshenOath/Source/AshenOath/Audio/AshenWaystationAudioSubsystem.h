// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenWaystationAudioSubsystem.generated.h"

/**
 * UAshenWaystationAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing twin-blade cross-parry clangs, healing chimes, and panic heartbeats.
 */
UCLASS()
class ASHENOATH_API UAshenWaystationAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenWaystationAudioSubsystem();

	/** Computes acoustic resonance frequency based on active run mode */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Waystation")
	float EvaluateResonanceFrequency(EWaystationRunMode Mode) const;
};
