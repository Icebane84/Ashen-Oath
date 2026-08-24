// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenChaosSpatialAudioSubsystem.generated.h"

/**
 * UAshenChaosSpatialAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing spatialized structural stone cracking, rubble collision thuds, and room occlusion.
 */
UCLASS()
class ASHENOATH_API UAshenChaosSpatialAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenChaosSpatialAudioSubsystem();

	/** Computes low-pass filter cutoff frequency in Hz based on rubble occlusion [500Hz to 20000Hz] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Chaos")
	float EvaluateOccludedAudioLPF(float RubbleMassKg) const;
};
