// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_BerserkSensoryVignetteHUD.generated.h"

/**
 * UAshenUserWidget_BerserkSensoryVignetteHUD
 * 
 * Renders the high-intensity sensory distortion during Berserk State:
 * - Monochromatic crimson vignette
 * - Stripping standard HUD telemetry
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BerserkSensoryVignetteHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_BerserkSensoryVignetteHUD(const FObjectInitializer& ObjectInitializer);

	/** Sets intensity of the berserk sensory vignette */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Berserk")
	void SetVignetteIntensity(float TargetIntensity);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Berserk")
	float GetVignetteIntensity() const { return CurrentIntensity; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Berserk")
	float CurrentIntensity = 0.0f;
};
