// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenScenario6DialogueBridge.generated.h"

/**
 * UAshenScenario6DialogueBridge
 * 
 * Injects contextual dialogue barks during freezing blizzards and sanctified hearth restoration.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario6DialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario6DialogueBridge();

	/** Formats dialogue bark based on weather, frostbite, and hearth state */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Scenario6")
	FText FormatScenario6Bark(EFrostbiteSeverity Severity, EHearthSanctuaryState HearthState) const;
};
