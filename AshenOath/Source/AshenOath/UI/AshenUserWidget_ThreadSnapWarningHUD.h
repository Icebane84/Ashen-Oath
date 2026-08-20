// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ThreadSnapWarningHUD.generated.h"

/**
 * UAshenUserWidget_ThreadSnapWarningHUD
 * Tactical HUD flashing when an active aegis filament thread is within 10% of snapping under kinetic load.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ThreadSnapWarningHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsRuptureImminent = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void SetRuptureAlert(bool bActive);
};
