// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_TraversalStaminaHUD.generated.h"

/**
 * UAshenUserWidget_TraversalStaminaHUD
 * Somatic HUD displaying player dash charges, sprint stamina meters, and environmental wind resistance warnings.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TraversalStaminaHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float StaminaPercent = 100.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 AvailableDashCharges = 2;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateTraversalHUD(float InStamina, int32 InCharges);
};
