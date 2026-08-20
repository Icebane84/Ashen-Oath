// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_StaminaPulseHUD.generated.h"

/**
 * UAshenUserWidget_StaminaPulseHUD
 * Beating cardiac stamina ring widget expanding and contracting in real-time.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_StaminaPulseHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float StaminaRatio = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float HeartPulseScale = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateStaminaPulseDisplay(float CurrentStamina, float MaxStamina);
};
