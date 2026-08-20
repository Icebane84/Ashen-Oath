// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_MiasmaCorruptionGaugeHUD.generated.h"

/**
 * UAshenUserWidget_MiasmaCorruptionGaugeHUD
 * UMG backing widget presenting diegetic miasma corruption visual HUD telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MiasmaCorruptionGaugeHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float MiasmaGaugePercent = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateMiasmaGaugeDisplay(float NewCorruptionLevel);
};
