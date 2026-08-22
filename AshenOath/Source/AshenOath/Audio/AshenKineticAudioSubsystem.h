// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenKineticAudioSubsystem.generated.h"

/**
 * UAshenKineticAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing sub-bass transients (30-60 Hz) and dynamic rubble occlusion filters.
 */
UCLASS()
class ASHENOATH_API UAshenKineticAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenKineticAudioSubsystem();

	/** Computes pitch down-tuning scalar from raw kinetic energy */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|KineticBerserk")
	float EvaluateKineticPitchMultiplier(float KineticEnergyJoules) const;
};
