// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_PeakResonanceHUD.generated.h"

/**
 * UAshenUserWidget_PeakResonanceHUD
 *
 * UMG backing widget rendering visual telemetry for peak resonance state, silent execution status, and synchronized rhythm.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PeakResonanceHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdatePeakResonanceHUDDisplay(bool bPeakActive, float Multiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bDisplayedPeakActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedMultiplier = 1.0f;
};
