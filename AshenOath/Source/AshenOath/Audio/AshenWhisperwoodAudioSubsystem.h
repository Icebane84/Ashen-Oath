// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenWhisperwoodAudioSubsystem.generated.h"

/**
 * UAshenWhisperwoodAudioSubsystem
 * 
 * Synthesizes eerie whispering wind ambiences, hallucination pitch warps, and soot wipe swooshes.
 */
UCLASS()
class ASHENOATH_API UAshenWhisperwoodAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenWhisperwoodAudioSubsystem();

	/** Computes pitch warble depth for auditory mirages */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario4")
	float EvaluateWhisperPitchWarble(float Sanity) const;
};
