// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_QuestTracker.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestTrackerRefreshedSignature, FName, ActiveQuestID, FText, ObjectiveText);

/**
 * UAshenUserWidget_QuestTracker
 *
 * UMG backing widget for HUD active quest & objective tracker display.
 * Displays quest title, active objective text, and progress status.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_QuestTracker : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayActiveQuest(FName QuestID, const FText& QuestTitle, const FText& ActiveObjective);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void ClearQuestDisplay();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName CurrentQuestID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText CurrentQuestTitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText CurrentObjectiveText;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UI|Events")
	FOnQuestTrackerRefreshedSignature OnQuestTrackerRefreshed;
};
