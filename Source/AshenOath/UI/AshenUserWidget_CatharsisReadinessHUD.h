// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CatharsisReadinessHUD.generated.h"

/**
 * UAshenUserWidget_CatharsisReadinessHUD
 * Dual-gauge HUD rendering Kaelen's Resolve (>=0.90) and Serafina's Burnout (>=0.65) convergence readiness for White Flame activation.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CatharsisReadinessHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsCatharsisReady = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateConvergenceReadiness(float Resolve, float Burnout);
};
