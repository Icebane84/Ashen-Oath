// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenUserWidget_StaggerExecutionPromptHUD.generated.h"

/**
 * UAshenUserWidget_StaggerExecutionPromptHUD
 * High-stakes execution prompt HUD flashing during the 0.75s Trial of Will stagger window.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_StaggerExecutionPromptHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsPromptActive = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float WindowTimeRemaining = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void ShowExecutionPrompt(float RemainingSeconds);
};
