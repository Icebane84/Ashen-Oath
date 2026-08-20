// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SanctuaryRunePrompt.generated.h"

/**
 * UAshenUserWidget_SanctuaryRunePrompt
 *
 * UMG backing widget rendering "Fast Travel Rune Activated" HUD banners.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SanctuaryRunePrompt : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayRunePrompt(FName RuneID, const FText& RuneNameText);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void HidePrompt();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedRuneID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedRuneName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bPromptActive = false;
};
