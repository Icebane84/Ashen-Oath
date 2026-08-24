// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenJournalDialogueBridge.generated.h"

/**
 * UAshenJournalDialogueBridge
 * 
 * Contextual companion voice lines and debates triggered while examining forensic scenario chronicles.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenJournalDialogueBridge();

	/** Formats companion campfire bark for a selected scenario entry */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Journal")
	FText FormatScenarioCampfireBark(int32 ScenarioIndex, ECampfireReflectionMood Mood) const;
};
