// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_LanternFuelHUD.generated.h"

/**
 * UAshenUserWidget_LanternFuelHUD
 * Circular brass gauge displaying remaining alchemical oil and burn status.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LanternFuelHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float FuelPercentage = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsLit = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateLanternHUD(float Fuel, bool bLitState);
};
