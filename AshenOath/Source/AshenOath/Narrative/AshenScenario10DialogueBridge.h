// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenScenario10DialogueBridge.generated.h"

/**
 * UAshenScenario10DialogueBridge
 * 
 * Generates contextual companion dialogue during apotheosis buildup and the 4 Grand Consequence epilogues.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario10DialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario10DialogueBridge();

	/** Formats dialogue bark based on consequence ending */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Scenario10")
	FText FormatEndingDialogue(EZenithConsequenceEnding Ending) const;
};
