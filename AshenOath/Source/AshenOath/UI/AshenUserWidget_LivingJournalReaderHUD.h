// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenUserWidget_LivingJournalReaderHUD.generated.h"

/**
 * UAshenUserWidget_LivingJournalReaderHUD
 * 
 * Interactive UMG/Slate widget for reading the living journal and companion marginalia.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LivingJournalReaderHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_LivingJournalReaderHUD(const FObjectInitializer& ObjectInitializer);

	/** Flips to next or previous page */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Journal")
	void NavigatePage(int32 DeltaPages);

	/** Inspects a companion marginalia entry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Journal")
	void InspectMarginaliaEntry(const FString& EntryId);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Journal")
	int32 GetCurrentPageIndex() const { return CurrentPageIndex; }

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Journal")
	int32 GetDiscoveredNotesCount() const { return DiscoveredNotesCount; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	int32 CurrentPageIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	int32 DiscoveredNotesCount = 0;
};
