// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenScenario1DialogueBridge.generated.h"

/**
 * UAshenScenario1DialogueBridge
 * 
 * Injects Brother Malakor and Elder Valerius dialogue confrontations into the narrative graph.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario1DialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario1DialogueBridge();

	/** Formats Malakor's confrontation dialogue based on current phase */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Scenario1")
	FText FormatMalakorConfrontation(EMalakorBossPhase Phase) const;
};
