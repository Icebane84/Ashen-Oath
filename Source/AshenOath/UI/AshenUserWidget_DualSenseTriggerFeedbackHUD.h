// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenEmpathicNovaTypes.h"
#include "AshenUserWidget_DualSenseTriggerFeedbackHUD.generated.h"

/**
 * UAshenUserWidget_DualSenseTriggerFeedbackHUD
 * Somatic HUD displaying DualSense trigger resistance telemetry (180-255) and dual-frequency haptic waveforms.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DualSenseTriggerFeedbackHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 DisplayedTriggerResistance = 180;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedLeftFrequency = 30.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedRightFrequency = 180.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateTriggerFeedbackHUD(const FHapticFrictionProfile& Profile);
};
