// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenScenario7DialogueBridge.generated.h"

/**
 * UAshenScenario7DialogueBridge
 * 
 * Generates contextual companion dialogue during volcanic caldera navigation and magma surge emergencies.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario7DialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario7DialogueBridge();

	/** Formats dialogue bark based on heat tier and magma surge phase */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Scenario7")
	FText FormatCalderaDialogueBark(EHeatExhaustionTier Tier, ECalderaSurgePhase Phase) const;
};
