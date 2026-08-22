// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenScenario5DialogueBridge.generated.h"

/**
 * UAshenScenario5DialogueBridge
 * 
 * Injects companion boundary defense barks and Kaelen's Unchained rage dialogue.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario5DialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario5DialogueBridge();

	/** Formats dialogue based on Unchained phase */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Scenario5")
	FText FormatPhaseBark(EUnchainedVesselPhase Phase) const;
};
