// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenJournalMasterBridge.generated.h"

/**
 * UAshenJournalMasterBridge
 * 
 * Master orchestrator connecting the Campfire Journal UI, Multi-Author Marginalia, Soot Ledger, and SaveGame persistence.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenJournalMasterBridge();

	/** Broadcasts journal entry selection */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Journal")
	void BroadcastEntrySelection(int32 ScenarioIndex, const FForensicJournalEntry& Entry);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Journal")
	FOnJournalEntrySelected OnEntrySelectionBroadcaster;
};
