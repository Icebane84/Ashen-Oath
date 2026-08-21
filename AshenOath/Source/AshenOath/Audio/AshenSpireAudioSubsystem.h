// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenSpireAudioSubsystem.generated.h"

/**
 * UAshenSpireAudioSubsystem
 * 
 * Synthesizes stone vault echoes, snapping tension wire haptics, and phosphor flare sizzles.
 */
UCLASS()
class ASHENOATH_API UAshenSpireAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenSpireAudioSubsystem();

	/** Evaluates pitch and tension for wire snap sound */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Scenario2")
	float EvaluateWireSnapPitch(float TensionScalar) const;
};
