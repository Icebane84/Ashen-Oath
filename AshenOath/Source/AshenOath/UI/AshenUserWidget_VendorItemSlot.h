// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_VendorItemSlot.generated.h"

/**
 * UAshenUserWidget_VendorItemSlot
 *
 * UMG backing widget rendering merchant shop item slots (Item Icon, Ember Cost, Stock Quantity, Buy Button).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_VendorItemSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateVendorItemSlot(FName ItemID, const FText& ItemNameText, float EmberCost, int32 AvailableStock);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedItemID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedItemName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedEmberCost = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 DisplayedStock = 0;
};
