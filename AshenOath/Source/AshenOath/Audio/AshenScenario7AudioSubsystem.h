// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenScenario7AudioSubsystem.generated.h"

/**
 * UAshenScenario7AudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing bubbling magma pits, roaring geyser eruptions, and quenching steam hiss audio.
 */
UCLASS()
class ASHENOATH_API UAshenScenario7AudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario7AudioSubsystem();

	/** Computes magma roar pitch multiplier based on eruption proximity [0.8x to 1.6x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario7")
	float EvaluateMagmaRoarPitch(ECalderaSurgePhase Phase) const;
};
