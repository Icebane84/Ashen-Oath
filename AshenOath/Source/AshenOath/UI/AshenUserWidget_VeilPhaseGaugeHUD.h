// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_VeilPhaseGaugeHUD.generated.h"

/**
 * UAshenUserWidget_VeilPhaseGaugeHUD
 * UMG backing widget presenting veil phase shift visual gauge and frequency pulse HUD telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_VeilPhaseGaugeHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float VeilPhaseGaugePercent = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateVeilGaugeDisplay(float PhaseIntensity);
};
