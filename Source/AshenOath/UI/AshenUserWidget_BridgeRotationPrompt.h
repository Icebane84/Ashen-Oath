// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_BridgeRotationPrompt.generated.h"

/**
 * UAshenUserWidget_BridgeRotationPrompt
 *
 * UMG backing widget rendering contextual rotating bridge interaction prompts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BridgeRotationPrompt : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void ShowBridgePrompt(float CurrentAngle, bool bIsAligned);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void HideBridgePrompt();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedAngle = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bBridgeAligned = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bPromptVisible = false;
};
