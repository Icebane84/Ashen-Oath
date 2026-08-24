// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenScenario8AudioSubsystem.generated.h"

/**
 * UAshenScenario8AudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing reverberant catacomb acoustics, sonar ping echo bounces, and shadow whispers.
 */
UCLASS()
class ASHENOATH_API UAshenScenario8AudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario8AudioSubsystem();

	/** Computes reverberation decay time in seconds based on cavern size [1.5s to 6.0s] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario8")
	float EvaluateReverbDecayTime(float CavernVolumeM3) const;
};
