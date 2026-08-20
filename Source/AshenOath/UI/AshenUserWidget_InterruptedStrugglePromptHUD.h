// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_InterruptedStrugglePromptHUD.generated.h"

/**
 * UAshenUserWidget_InterruptedStrugglePromptHUD
 * 
 * UMG Widget displaying diegetic vocal hesitation ("I—", averted eyes indicator)
 * when Kaelen fails or releases a Will Struggle squeeze early.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_InterruptedStrugglePromptHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_InterruptedStrugglePromptHUD(const FObjectInitializer& ObjectInitializer);

	/** Triggers the interrupted struggle visual animation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Struggle")
	void TriggerInterruptedPrompt(float PartialCompletionRatio, float DisplayDuration = 2.5f);

	/** Fades out the hesitation prompt */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Struggle")
	void DismissPrompt();

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Struggle")
	bool IsPromptVisible() const { return bPromptVisible; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Struggle")
	FText HesitationText = FText::FromString(TEXT("I—"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Struggle")
	float HesitationOpacity = 0.0f;

private:
	bool bPromptVisible = false;
};
