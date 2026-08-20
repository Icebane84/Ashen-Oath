// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 370: Ashen Crafting Ember Forge UMG Widget

#include "AshenUserWidget_CraftingEmberForge.h"

void UAshenUserWidget_CraftingEmberForge::UpdateCraftingDisplay(FName ItemID, float EmberCost)
{
	DisplayedCraftItem = ItemID;
	DisplayedCost = EmberCost;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CraftingEmberForge: Crafting Ember Forge UI updated — '%s' (Cost: %.0f Embers)."),
		*ItemID.ToString(), EmberCost);
}
