// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenScenario2DialogueBridge.generated.h"

/**
 * UAshenScenario2DialogueBridge
 * 
 * Injects Garrett's tactical dialogue nodes reflecting his 'Architect of Chaos' pragmatic philosophy.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario2DialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario2DialogueBridge();

	/** Formats Garrett's tactical dialogue when traps disrupt a patrol */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Scenario2")
	FText FormatGarrettTacticalBark(EPathfindingDisruptionTier DisruptionTier) const;
};
