// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_EmpathicDialogueOverlay.generated.h"

/**
 * UAshenUserWidget_EmpathicDialogueOverlay
 * UMG widget displaying dynamic companion thought bubbles and empathic cues.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_EmpathicDialogueOverlay : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FText ActiveSpeakerName;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FText ActiveDialogueText;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayEmpathicDialogue(FText Speaker, FText Text);
};
