// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_BulwarkLockoutHUD.generated.h"

/**
 * UAshenUserWidget_BulwarkLockoutHUD
 * Emergency HUD flashing when Serafina's Empathic Burnout crosses 0.70, indicating active healing lockouts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BulwarkLockoutHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsLockoutActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void SetLockoutVisibility(bool bActive);
};
