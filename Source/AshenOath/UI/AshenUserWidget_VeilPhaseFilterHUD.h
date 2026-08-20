// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_VeilPhaseFilterHUD.generated.h"

/**
 * UAshenUserWidget_VeilPhaseFilterHUD
 * UMG backing widget presenting veil phase filter visual gauge and frequency pulse HUD telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_VeilPhaseFilterHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float VeilPhaseFilterGaugePercent = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateVeilFilterGaugeDisplay(float FilterIntensity);
};
