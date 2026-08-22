// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenWeepingMireAudioSubsystem.generated.h"

/**
 * UAshenWeepingMireAudioSubsystem
 * 
 * Synthesizes deep swamp squelches, volatile methane hisses, and visceral heart palpitation thumps.
 */
UCLASS()
class ASHENOATH_API UAshenWeepingMireAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenWeepingMireAudioSubsystem();

	/** Computes heart palpitation thump pitch based on current BPM */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario5")
	float EvaluateHeartThumpPitch(float HeartRateBPM) const;
};
