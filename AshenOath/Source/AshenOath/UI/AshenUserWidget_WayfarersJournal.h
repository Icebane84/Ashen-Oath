// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenWayfarerJournalSubsystem.h"
#include "AshenUserWidget_WayfarersJournal.generated.h"

/**
 * UAshenUserWidget_WayfarersJournal
 * Full interactive 2-page diegetic UMG book widget with Kaelen ledger on left, Garrett/Serafina marginalia on right.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WayfarersJournal : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FAshenJournalEntry ActiveDisplayedEntry;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsGuardedFrictionActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayJournalEntry(const FAshenJournalEntry& Entry, bool bGuardedFriction);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void FlipPageNext();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void FlipPagePrevious();
};
