// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_InventoryComponent.h"

UAshenOath_InventoryComponent::UAshenOath_InventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenOath_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenOath_InventoryComponent::AddItem(const FAshenItemData& Item)
{
	if (Item.ItemID == NAME_None || Item.Quantity <= 0) return;

	for (FAshenItemData& ExistingItem : InventoryItems)
	{
		if (ExistingItem.ItemID == Item.ItemID)
		{
			ExistingItem.Quantity += Item.Quantity;
			OnInventoryUpdated.Broadcast();
			return;
		}
	}

	InventoryItems.Add(Item);
	OnInventoryUpdated.Broadcast();
}

bool UAshenOath_InventoryComponent::RemoveItem(FName ItemID, int32 QuantityToRemove)
{
	if (ItemID == NAME_None || QuantityToRemove <= 0) return false;

	for (int32 Index = 0; Index < InventoryItems.Num(); ++Index)
	{
		if (InventoryItems[Index].ItemID == ItemID)
		{
			if (InventoryItems[Index].Quantity > QuantityToRemove)
			{
				InventoryItems[Index].Quantity -= QuantityToRemove;
				OnInventoryUpdated.Broadcast();
				return true;
			}
			else if (InventoryItems[Index].Quantity == QuantityToRemove)
			{
				InventoryItems.RemoveAt(Index);
				OnInventoryUpdated.Broadcast();
				return true;
			}
			return false; // Not enough quantity
		}
	}

	return false; // Item not found
}

void UAshenOath_InventoryComponent::LoadInventoryState(const TArray<FAshenItemData>& InItems)
{
	InventoryItems = InItems;
	OnInventoryUpdated.Broadcast();
}
