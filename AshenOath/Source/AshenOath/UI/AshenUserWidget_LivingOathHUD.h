// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenLivingOathSubsystem.h"
#include "AshenUserWidget_LivingOathHUD.generated.h"

/**
 * UAshenUserWidget_LivingOathHUD
 * HUD widget displaying active oath tenet icons, vow fulfillment progress, and resonance status.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LivingOathHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EAshenLivingOathType DisplayedOathType = EAshenLivingOathType::None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float FulfillmentRatio = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateLivingOathHUD(EAshenLivingOathType OathType, float Fulfillment);
};
