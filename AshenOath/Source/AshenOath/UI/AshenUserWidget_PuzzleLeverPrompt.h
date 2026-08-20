// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_PuzzleLeverPrompt.generated.h"

/**
 * UAshenUserWidget_PuzzleLeverPrompt
 *
 * UMG backing widget rendering contextual lever interaction prompts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PuzzleLeverPrompt : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void ShowLeverPrompt(FName LeverID, const FText& LeverActionText, bool bIsAlreadyActivated);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void HideLeverPrompt();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedLeverID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedLeverActionText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bLeverActivated = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bPromptActive = false;
};
