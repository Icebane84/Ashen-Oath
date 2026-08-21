// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenScenario4DialogueBridge.generated.h"

/**
 * UAshenScenario4DialogueBridge
 * 
 * Injects reality-grounding companion dialogue into Whisperwood narrative graphs.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario4DialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario4DialogueBridge();

	/** Formats companion grounding feedback dialogue */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Scenario4")
	FText FormatGroundingBark(ECompanionGroundingState GroundingResult) const;
};
