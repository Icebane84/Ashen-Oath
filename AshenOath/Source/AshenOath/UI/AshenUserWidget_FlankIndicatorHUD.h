// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_FlankIndicatorHUD.generated.h"

/**
 * UAshenUserWidget_FlankIndicatorHUD
 * Somatic HUD reticle displaying enemy rear alignment angle and flank execution readiness.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_FlankIndicatorHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsFlankAligned = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float CurrentFlankAngle = 180.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateFlankReticle(bool bAligned, float AngleDegrees);
};
