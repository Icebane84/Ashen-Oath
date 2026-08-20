// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenUserWidget_TrialOfWillDecisionHUD.generated.h"

/**
 * UAshenUserWidget_TrialOfWillDecisionHUD
 * Somatic HUD rendering the 3 existential stagger options (Defiance, Wrath, Trust) during the 0.75s time-dilation window.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TrialOfWillDecisionHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsPromptVisible = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void SetPromptVisibility(bool bVisible);
};
