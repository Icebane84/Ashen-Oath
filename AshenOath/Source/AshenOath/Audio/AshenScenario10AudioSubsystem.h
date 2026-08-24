// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenScenario10AudioSubsystem.generated.h"

/**
 * UAshenScenario10AudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing the Grand Apotheosis Solfeggio Choral Triad (396Hz + 528Hz + 639Hz).
 */
UCLASS()
class ASHENOATH_API UAshenScenario10AudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario10AudioSubsystem();

	/** Evaluates the choral triad harmonic gain based on apotheosis resonance [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario10")
	float EvaluateApotheosisChoralGain(float Resonance01) const;
};
