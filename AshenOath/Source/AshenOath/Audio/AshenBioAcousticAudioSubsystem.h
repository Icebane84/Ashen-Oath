// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenBioAcousticAudioSubsystem.generated.h"

/**
 * UAshenBioAcousticAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing dynamic bio-acoustic heartbeats (60-170 BPM), jagged breaths, and superheated blade sizzle.
 */
UCLASS()
class ASHENOATH_API UAshenBioAcousticAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenBioAcousticAudioSubsystem();

	/** Computes acoustic low-pass filter frequency based on heart rate stress */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Somatics")
	float EvaluateHeartStressAudioFilter(float HeartRateBPM) const;
};
