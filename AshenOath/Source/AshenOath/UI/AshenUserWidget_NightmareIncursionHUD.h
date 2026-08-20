// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenPsychicStrainTypes.h"
#include "AshenUserWidget_NightmareIncursionHUD.generated.h"

/**
 * UAshenUserWidget_NightmareIncursionHUD
 * Somatic UI widget displaying reality fracture cracks, incursion intensity gauges, and active rift proximity alerts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_NightmareIncursionHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedIncursionIntensity = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float RealityStabilityPercent = 100.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateIncursionDisplay(float InIntensity, float InStability);
};
