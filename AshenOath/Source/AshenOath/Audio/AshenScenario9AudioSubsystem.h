// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenScenario9AudioSubsystem.generated.h"

/**
 * UAshenScenario9AudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing high-altitude gale howls, zero-g resonant hums, and 528Hz bridge chimes.
 */
UCLASS()
class ASHENOATH_API UAshenScenario9AudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario9AudioSubsystem();

	/** Computes wind howl pitch frequency based on wind speed [180Hz to 950Hz] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario9")
	float EvaluateWindHowlFrequency(float WindSpeedMps) const;
};
