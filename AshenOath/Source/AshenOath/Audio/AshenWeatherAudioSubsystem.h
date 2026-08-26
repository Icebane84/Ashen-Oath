// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenWeatherAudioSubsystem.generated.h"

/**
 * UAshenWeatherAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing howling blizzard gusts (60-4000Hz), acid rain plate sizzles, and deep thunderclap explosions.
 */
UCLASS()
class ASHENOATH_API UAshenWeatherAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenWeatherAudioSubsystem();

	/** Evaluates blizzard howling wind gain [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Weather")
	float EvaluateBlizzardWindGain(EWeatherHazardState State, float WindShearMps) const;

	/** Evaluates acid rain metal hiss gain [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Weather")
	float EvaluateAcidRainHissGain(EWeatherHazardState State) const;
};
