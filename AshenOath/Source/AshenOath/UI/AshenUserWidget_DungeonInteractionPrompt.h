// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_DungeonInteractionPrompt.generated.h"

/**
 * UAshenUserWidget_DungeonInteractionPrompt
 *
 * UMG backing widget rendering HUD contextual interaction prompts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DungeonInteractionPrompt : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void ShowPrompt(const FText& ActionText, const FText& KeyNameText);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void HidePrompt();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText CurrentActionText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText CurrentKeyNameText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bPromptVisible = false;
};
