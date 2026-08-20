// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_NarrativeChoiceUI.generated.h"

/**
 * UAshenUserWidget_NarrativeChoiceUI
 *
 * UMG backing widget rendering interactive branching dialogue choices and psychological alignment preview.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_NarrativeChoiceUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateNarrativeChoiceDisplay(FName NodeID, int32 SelectedOption);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedNodeID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 DisplayedSelectedOption = 0;
};
