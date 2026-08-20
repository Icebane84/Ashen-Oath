// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 185: Ashen Quick-Belt UMG Widget

#include "AshenUserWidget_QuickBelt.h"

void UAshenUserWidget_QuickBelt::RefreshSlotDisplay(int32 SlotIndex, FAshenItemData ItemData)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_QuickBelt: Slot %d refreshed with item '%s' (Qty: %d)."),
		SlotIndex, *ItemData.ItemName, ItemData.Quantity);
}

void UAshenUserWidget_QuickBelt::SetActiveSlotHighlight(int32 SlotIndex)
{
	CurrentActiveSlot = SlotIndex;
	OnQuickBeltRefreshed.Broadcast(CurrentActiveSlot);

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_QuickBelt: Active slot highlight set to slot %d."), CurrentActiveSlot);
}
