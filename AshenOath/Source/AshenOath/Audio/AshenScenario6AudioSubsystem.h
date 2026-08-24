// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenScenario6AudioSubsystem.generated.h"

/**
 * UAshenScenario6AudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing sub-zero blizzard wind howling, frost crackling, and roaring hearth fire.
 */
UCLASS()
class ASHENOATH_API UAshenScenario6AudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario6AudioSubsystem();

	/** Computes blizzard wind howling intensity [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario6")
	float EvaluateBlizzardWindVolume(EBlizzardIntensity Intensity) const;

	/** Computes hearth crackle audio volume [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario6")
	float EvaluateHearthFireVolume(float IgnitionProgress) const;
};
