// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_FalseConfidenceHUD.generated.h"

/**
 * UAshenUserWidget_FalseConfidenceHUD
 *
 * Deceptive HUD UMG widget rendering hyper-sharpened false confidence visual overlays (UMB-SYS-005).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_FalseConfidenceHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void SetFalseConfidenceDeceptionState(bool bInDeceptionActive, float Intensity);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bDeceptionOverlayActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DeceptionOverlayIntensity = 0.0f;
};
