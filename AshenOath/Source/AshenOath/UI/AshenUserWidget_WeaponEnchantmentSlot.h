// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenWeaponEnchantmentComponent.h"
#include "AshenUserWidget_WeaponEnchantmentSlot.generated.h"

/**
 * UAshenUserWidget_WeaponEnchantmentSlot
 *
 * UMG backing widget rendering the HUD weapon elemental infusion slot & duration bar.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WeaponEnchantmentSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateInfusionSlot(EAshenElementInfusion Infusion, float RemainingDuration, float BonusDamage);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	EAshenElementInfusion CurrentInfusion = EAshenElementInfusion::None;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float CurrentRemainingDuration = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float CurrentBonusDamage = 0.0f;
};
