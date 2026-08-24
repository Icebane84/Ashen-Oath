// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenScenario8DialogueBridge.generated.h"

/**
 * UAshenScenario8DialogueBridge
 * 
 * Generates contextual companion whispers and navigation barks during catacomb darkness and echolocation sonar bursts.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario8DialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario8DialogueBridge();

	/** Formats dialogue bark based on light state and echolocation pulse */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Scenario8")
	FText FormatAbyssDialogueBark(ELightEnvironmentState LightState, EEcholocationPulseType Pulse) const;
};
