// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenUserWidget_InventoryMenu.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenOath_EquipmentComponent.h"
#include "AshenOath_QuickbarComponent.h"
#include "GameFramework/Pawn.h"

void UAshenUserWidget_InventoryMenu::RefreshInventoryGrid()
{
	APawn* OwningPawn = GetOwningPlayerPawn();
	if (!OwningPawn) return;

	if (UAshenOath_InventoryComponent* Inv = OwningPawn->FindComponentByClass<UAshenOath_InventoryComponent>())
	{
		TotalInventoryItemCount = Inv->GetInventoryItems().Num();
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_InventoryMenu: Inventory grid refreshed (%d items)."), TotalInventoryItemCount);
}

bool UAshenUserWidget_InventoryMenu::EquipSelectedItem(FName ItemID, FName SlotName)
{
	APawn* OwningPawn = GetOwningPlayerPawn();
	if (!OwningPawn) return false;

	if (UAshenOath_EquipmentComponent* EquipComp = OwningPawn->FindComponentByClass<UAshenOath_EquipmentComponent>())
	{
		OnItemEquipped.Broadcast(ItemID, SlotName);
		UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_InventoryMenu: Equipped item '%s' to slot '%s'."), *ItemID.ToString(), *SlotName.ToString());
		return true;
	}

	return false;
}

bool UAshenUserWidget_InventoryMenu::AssignToQuickbar(FName ItemID, int32 SlotIndex)
{
	APawn* OwningPawn = GetOwningPlayerPawn();
	if (!OwningPawn) return false;

	if (UAshenOath_QuickbarComponent* Quickbar = OwningPawn->FindComponentByClass<UAshenOath_QuickbarComponent>())
	{
		Quickbar->EquipItemToSlot(SlotIndex, ItemID, FText::FromName(ItemID), 1);
		UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_InventoryMenu: Assigned '%s' to quickbar slot %d."), *ItemID.ToString(), SlotIndex);
		return true;
	}

	return false;
}
