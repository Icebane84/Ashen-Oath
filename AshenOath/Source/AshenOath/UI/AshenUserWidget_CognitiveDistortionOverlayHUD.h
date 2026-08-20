// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "AshenUserWidget_CognitiveDistortionOverlayHUD.generated.h"

/**
 * UAshenUserWidget_CognitiveDistortionOverlayHUD
 * 
 * Overlay widget rendering cognitive UI distortions:
 * - Edge desaturation and chromatic fringe
 * - Scanline interference and soot vignette
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CognitiveDistortionOverlayHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_CognitiveDistortionOverlayHUD(const FObjectInitializer& ObjectInitializer);

	/** Sets active distortion parameters */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Distortion")
	void SetDistortionParameters(const FGameplayTag& DistortionType, float Intensity);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Distortion")
	float GetDistortionIntensity() const { return CurrentIntensity; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Distortion")
	FGameplayTag ActiveDistortionTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Distortion")
	float CurrentIntensity = 0.0f;
};
