// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenUserWidget_ForensicJournalHUD.generated.h"

/**
 * UAshenUserWidget_ForensicJournalHUD
 * 
 * UMG 2-page illuminated journal display featuring multi-author marginalia sidebars and soot provenance ledger.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ForensicJournalHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_ForensicJournalHUD(const FObjectInitializer& ObjectInitializer);

	/** Displays a selected scenario journal entry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Journal")
	void DisplayJournalEntry(const FForensicJournalEntry& Entry, float PartyTrust01);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	int32 DisplayedScenarioIndex = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	FString DisplayedTitle = TEXT("The Bleeding Waystation");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	FText DisplayedSummary;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	bool bKaelenNoteVisible = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	bool bGarrettNoteVisible = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	bool bSerafinaNoteVisible = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	float DisplayedSootMicrons = 0.0f;
};
