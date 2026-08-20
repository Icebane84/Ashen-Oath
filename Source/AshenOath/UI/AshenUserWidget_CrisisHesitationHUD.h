// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenCrisisTypes.h"
#include "AshenUserWidget_CrisisHesitationHUD.generated.h"

/**
 * UAshenUserWidget_CrisisHesitationHUD
 * UMG backing widget rendering somatic peripheral ocular shadow vignetting during 2.0-second crisis dilation (UMB-UI-004 zero HUD).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CrisisHesitationHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float PeripheralOcularShadowAlpha = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateOcularShadowDisplay(float VignetteAlpha);
};
