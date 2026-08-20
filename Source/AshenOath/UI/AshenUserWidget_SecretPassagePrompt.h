// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SecretPassagePrompt.generated.h"

/**
 * UAshenUserWidget_SecretPassagePrompt
 *
 * UMG backing widget rendering HUD secret passage prompts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SecretPassagePrompt : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void ShowSecretPassagePrompt(const FText& PromptText);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void HidePrompt();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedPromptText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bPromptVisible = false;
};
