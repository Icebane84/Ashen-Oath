// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 284: Ashen Vendor Item Slot UMG Widget

#include "AshenUserWidget_VendorItemSlot.h"

void UAshenUserWidget_VendorItemSlot::UpdateVendorItemSlot(FName ItemID, const FText& ItemNameText, float EmberCost, int32 AvailableStock)
{
	DisplayedItemID = ItemID;
	DisplayedItemName = ItemNameText;
	DisplayedEmberCost = EmberCost;
	DisplayedStock = AvailableStock;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_VendorItemSlot: Vendor item slot updated — '%s' ('%s'), Cost: %.0f Embers, Stock: %d."),
		*ItemID.ToString(), *ItemNameText.ToString(), EmberCost, AvailableStock);
}
