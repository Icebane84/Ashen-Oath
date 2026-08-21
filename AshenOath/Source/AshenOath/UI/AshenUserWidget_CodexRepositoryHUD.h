// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenUserWidget_CodexRepositoryHUD.generated.h"

/**
 * UAshenUserWidget_CodexRepositoryHUD
 * 
 * UMG/Slate widget displaying the codex book chronicle, companion marginalia, and relic inspection viewport.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CodexRepositoryHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_CodexRepositoryHUD(const FObjectInitializer& ObjectInitializer);

	/** Displays a specific lore entry in the codex view */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Archive")
	void DisplayLoreEntry(const FCodexEntry& Entry, const FText& MarginaliaText);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Archive")
	FName GetActiveEntryId() const { return DisplayedEntryId; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Archive")
	FName DisplayedEntryId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Archive")
	FText DisplayedTitle = FText::GetEmpty();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Archive")
	FText DisplayedMarginalia = FText::GetEmpty();
};
