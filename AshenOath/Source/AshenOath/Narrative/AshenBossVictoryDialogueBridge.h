// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenBossVictoryDialogueBridge.generated.h"

/**
 * UAshenBossVictoryDialogueBridge
 * 
 * Injects boss battle victory reflections and crisis outcome context into campfire dialogue.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossVictoryDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossVictoryDialogueBridge();

	/** Formats dialogue reflecting boss encounter outcome */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Boss")
	FText FormatVictoryDialogue(
		const FString& BasePrompt,
		int32 RescuesPerformed,
		int32 PillarsSundered) const;
};
