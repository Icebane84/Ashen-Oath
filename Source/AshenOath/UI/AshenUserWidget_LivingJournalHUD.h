// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenLivingJournalConsequenceTypes.h"
#include "AshenUserWidget_LivingJournalHUD.generated.h"

/**
 * UAshenUserWidget_LivingJournalHUD
 * Diegetic field journal UI widget displaying Kaelen's prose on the left page, and Garrett's charcoal diagrams + Serafina's silver script on the right page.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LivingJournalHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FName DisplayedBestiaryID = NAME_None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FString DisplayedKaelenProse = TEXT("");

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FString DisplayedGarrettSketchNote = TEXT("");

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FString DisplayedSerafinaLeafScript = TEXT("");

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bHasUnlockedPerk = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void PopulateJournalPage(const FJournalResolutionEntry& Entry, bool bPerkUnlocked);
};
