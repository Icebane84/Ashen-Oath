// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ArmorDamageHUD.generated.h"

/**
 * UAshenUserWidget_ArmorDamageHUD
 *
 * UMG backing widget rendering visual telemetry for armor durability across limb slots.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ArmorDamageHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateArmorHUDDisplay(FName LimbSlot, float RemainingIntegrity);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedLimbSlot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedIntegrity = 100.0f;
};
