// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_DestructibleWallPrompt.generated.h"

/**
 * UAshenUserWidget_DestructibleWallPrompt
 *
 * UMG backing widget rendering contextual cracked wall interaction prompts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DestructibleWallPrompt : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void ShowWallPrompt(const FText& WallPromptText);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void HideWallPrompt();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText CurrentWallPromptText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bPromptVisible = false;
};
