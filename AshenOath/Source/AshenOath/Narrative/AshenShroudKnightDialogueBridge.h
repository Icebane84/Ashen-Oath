// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenShroudKnightDialogueBridge.generated.h"

/**
 * UAshenShroudKnightDialogueBridge
 * 
 * Generates combat barks for companion callouts and Eldrin's mocking whispers during the Shroud-Knight encounter.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShroudKnightDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenShroudKnightDialogueBridge();

	/** Formats dialogue bark for phase change or Trinity Strike execution */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Boss")
	FText FormatBossCombatBark(EShroudKnightPhaseState PhaseState, ETrinityStrikeStep TrinityStep) const;
};
