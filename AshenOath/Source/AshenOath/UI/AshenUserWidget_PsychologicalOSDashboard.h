// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenPOSTypes.h"
#include "AshenUserWidget_PsychologicalOSDashboard.generated.h"

/**
 * UAshenUserWidget_PsychologicalOSDashboard
 * Master UMG Widget backing Psychological Operating System single-question dashboard tabs.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PsychologicalOSDashboard : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FAshenQualitativeMindState ActiveQualitativeMindState;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayQualitativeMindState(FAshenQualitativeMindState MindState);
};
