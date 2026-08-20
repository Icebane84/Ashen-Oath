// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_MemoryThreadJournal.generated.h"

/**
 * UAshenUserWidget_MemoryThreadJournal
 *
 * UMG backing widget rendering collected memory threads and narrative logs.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MemoryThreadJournal : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateJournalDisplay(FName ThreadID, int32 TotalCollectedThreads);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedThreadID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 TotalCollected = 0;
};
