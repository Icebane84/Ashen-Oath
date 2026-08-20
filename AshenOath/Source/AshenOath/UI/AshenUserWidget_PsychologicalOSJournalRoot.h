// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/AshenJournalSingleQuestionHubViewModel.h"
#include "AshenUserWidget_PsychologicalOSJournalRoot.generated.h"

UCLASS(Abstract)
class ASHENOATH_API UAshenUserWidget_PsychologicalOSJournalRoot : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayQualitativeSummary(const FAshenPsychologicalOSQualitativeSummary& Summary);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | UI")
	FText GetCurrentMindStateText() const { return CurrentMindStateText; }

private:
	FText CurrentMindStateText;
};
