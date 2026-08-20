// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenDiegeticJournalSubsystem.generated.h"

UCLASS()
class ASHENOATH_API UAshenDiegeticJournalSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Journal")
	FOnJournalEventDispatched OnJournalEventDispatched;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	TArray<FName> PermanentEntryTags;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Journal")
	void DispatchJournalEvent(const FJournalEvent& Event);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Journal")
	void AppendJournalEntry(FName EntryTag, const FString& EntryContent);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Journal")
	TArray<FJournalEvent> GetJournalHistoryForNode(FName MemoryNodeID) const;

private:
	UPROPERTY()
	TArray<FJournalEvent> JournalEventHistory;
};
