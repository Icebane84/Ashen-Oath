// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ExecutionPromptOverlay.generated.h"

/**
 * UAshenUserWidget_ExecutionPromptOverlay
 * UMG HUD prompt indicating execution readiness with stance-tailored iconography.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ExecutionPromptOverlay : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bExecutionPromptVisible = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FString ActiveStanceIcon = "Razor";

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void ShowExecutionPrompt(bool bVisible, FString StanceName);
};
