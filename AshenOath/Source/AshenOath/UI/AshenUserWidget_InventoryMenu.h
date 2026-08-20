// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_InventoryMenu.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemEquippedSignature, FName, ItemID, FName, SlotName);

/**
 * UAshenUserWidget_InventoryMenu
 *
 * UMG backing widget for Kaelen's inventory and equipment interface.
 * Displays item grids, equipment slots, and quickbar assignments.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_InventoryMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void RefreshInventoryGrid();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	bool EquipSelectedItem(FName ItemID, FName SlotName);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	bool AssignToQuickbar(FName ItemID, int32 SlotIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 TotalInventoryItemCount = 0;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UI|Events")
	FOnInventoryItemEquippedSignature OnItemEquipped;
};
