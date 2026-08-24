// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenScenario9DialogueBridge.generated.h"

/**
 * UAshenScenario9DialogueBridge
 * 
 * Generates contextual companion barks during low-gravity leaps, wind shear gusts, and bridge crossings.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario9DialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario9DialogueBridge();

	/** Formats dialogue bark based on wind state and bridge status */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Scenario9")
	FText FormatCitadelDialogueBark(EWindShearGustState WindState, ETelekineticBridgeStatus Bridge) const;
};
