// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_TriggerFrictionTelemetryHUD.generated.h"

/**
 * UAshenUserWidget_TriggerFrictionTelemetryHUD
 * Diagnostic HUD rendering L2/R2 travel percentages and trigger resistance status.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TriggerFrictionTelemetryHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float L2TravelPercentage = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float R2TravelPercentage = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateTriggerTelemetry(float InL2, float InR2);
};
