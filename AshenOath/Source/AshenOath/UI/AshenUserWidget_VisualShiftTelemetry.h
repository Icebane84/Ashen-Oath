// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_VisualShiftTelemetry.generated.h"

/**
 * UAshenUserWidget_VisualShiftTelemetry
 * UMG widget displaying live corruption emissive scalar and duality shader blend ratio.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_VisualShiftTelemetry : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float EmissiveIntensity = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DualityBlendRatio = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshTelemetry(float Emissive, float BlendRatio);
};
