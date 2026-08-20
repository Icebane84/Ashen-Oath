// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_DiegeticBreathingHUD.generated.h"

/**
 * UAshenUserWidget_DiegeticBreathingHUD
 *
 * UMG backing widget rendering visual telemetry for breathing frequency, heart rate, and stamina fatigue.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DiegeticBreathingHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateBreathingHUDDisplay(float RateHz, float FatiguePercent, FName AudioBarkTag);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedRateHz = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedFatiguePercent = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedAudioBarkTag;
};
