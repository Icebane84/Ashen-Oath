// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenDialogueTypes.h"
#include "AshenDialogueChoiceEvaluator.h"
#include "AshenUserWidget_DialogueOverlay.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDialogueChoiceClickedSignature, int32, ChoiceIndex);

/**
 * UAshenUserWidget_DialogueOverlay
 *
 * UMG/Slate backing widget for interactive narrative dialogue nodes.
 * Displays speaker name, line text, and 2-4 interactive choices.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DialogueOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_DialogueOverlay(const FObjectInitializer& ObjectInitializer);

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Dialogue")
	void DisplayDialogueLine(const FText& SpeakerName, const FText& LineText, const TArray<FDialogueChoiceRecord>& Choices);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Dialogue")
	void SelectChoice(int32 ChoiceIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Dialogue")
	FText ActiveSpeakerName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Dialogue")
	FText ActiveLineText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Dialogue")
	TArray<FDialogueChoiceRecord> ActiveChoices;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Dialogue|Events")
	FOnDialogueChoiceClickedSignature OnChoiceClicked;
};
