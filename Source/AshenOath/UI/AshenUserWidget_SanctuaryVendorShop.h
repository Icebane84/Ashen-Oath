// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SanctuaryVendorShop.generated.h"

/**
 * UAshenUserWidget_SanctuaryVendorShop
 *
 * UMG backing widget rendering sanctuary vendor stock, discounts, and restock timers.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SanctuaryVendorShop : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateSanctuaryVendorShopDisplay(FName VendorID, float DiscountMultiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedVendorID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedDiscountMultiplier = 1.0f;
};
