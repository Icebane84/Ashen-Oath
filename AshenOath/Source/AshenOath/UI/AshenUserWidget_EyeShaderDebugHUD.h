// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_EyeShaderDebugHUD.generated.h"

/**
 * UAshenUserWidget_EyeShaderDebugHUD
 *
 * UMG backing widget rendering visual telemetry for eye shader emissive intensity and sanity thresholds.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_EyeShaderDebugHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateEyeShaderHUDDisplay(float Intensity, FLinearColor Color);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedEmissiveIntensity = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FLinearColor DisplayedEyeGlowColor = FLinearColor::Blue;
};
