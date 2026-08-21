// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenCodexDialogueBridge.generated.h"

/**
 * UAshenCodexDialogueBridge
 * 
 * Generates Campfire narrative prompts when major lore entries are discovered.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCodexDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCodexDialogueBridge();

	/** Formats a Campfire conversation opener based on an unlocked lore entry */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Archive")
	FText FormatLoreConversationOpener(const FName& EntryId, const FText& EntryTitle) const;
};
