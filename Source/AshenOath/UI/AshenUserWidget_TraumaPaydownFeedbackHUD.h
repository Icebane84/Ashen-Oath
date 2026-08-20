// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_TraumaPaydownFeedbackHUD.generated.h"

/**
 * UAshenUserWidget_TraumaPaydownFeedbackHUD
 * Diegetic HUD indicator showing Integration Debt cleared, Burnout cleansed, and blade whisper muting.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TraumaPaydownFeedbackHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedDebtCleared = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedBurnoutCleansed = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void ShowTraumaResolution(float DebtCleared, float BurnoutCleansed);
};
