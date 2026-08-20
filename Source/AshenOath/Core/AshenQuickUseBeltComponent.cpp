// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 181: Ashen Quick-Use Item Belt Component

#include "AshenQuickUseBeltComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

UAshenQuickUseBeltComponent::UAshenQuickUseBeltComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxBeltSlots = 4;
	UseCooldownDuration = 1.0f;
	ActiveSlotIndex = 0;
	bOnCooldown = false;

	BeltSlots.SetNum(MaxBeltSlots);
}

void UAshenQuickUseBeltComponent::BeginPlay()
{
	Super::BeginPlay();
	if (BeltSlots.Num() != MaxBeltSlots)
	{
		BeltSlots.SetNum(MaxBeltSlots);
	}
}

void UAshenQuickUseBeltComponent::AssignItemToSlot(int32 SlotIndex, FAshenItemData ItemData)
{
	if (!BeltSlots.IsValidIndex(SlotIndex)) return;

	BeltSlots[SlotIndex] = ItemData;

	if (SlotIndex == ActiveSlotIndex)
	{
		OnQuickSlotChanged.Broadcast(ActiveSlotIndex, BeltSlots[ActiveSlotIndex]);
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenQuickUseBeltComponent: Assigned item '%s' (%d) to slot %d."),
		*ItemData.ItemName, ItemData.Quantity, SlotIndex);
}

void UAshenQuickUseBeltComponent::CycleSlot(bool bNextSlot)
{
	if (MaxBeltSlots <= 0) return;

	if (bNextSlot)
	{
		ActiveSlotIndex = (ActiveSlotIndex + 1) % MaxBeltSlots;
	}
	else
	{
		ActiveSlotIndex = (ActiveSlotIndex - 1 + MaxBeltSlots) % MaxBeltSlots;
	}

	OnQuickSlotChanged.Broadcast(ActiveSlotIndex, GetActiveItemData());

	UE_LOG(LogTemp, Log, TEXT("UAshenQuickUseBeltComponent: Cycled active slot to %d ('%s')."),
		ActiveSlotIndex, *GetActiveItemData().ItemName);
}

bool UAshenQuickUseBeltComponent::UseActiveItem()
{
	if (bOnCooldown)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenQuickUseBeltComponent: Item usage on cooldown."));
		return false;
	}

	if (!BeltSlots.IsValidIndex(ActiveSlotIndex)) return false;

	FAshenItemData& ActiveItem = BeltSlots[ActiveSlotIndex];
	if (ActiveItem.ItemID.IsNone() || ActiveItem.Quantity <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenQuickUseBeltComponent: Active slot %d is empty or depleted."), ActiveSlotIndex);
		return false;
	}

	// Consume one item
	ActiveItem.Quantity--;
	bOnCooldown = true;

	OnQuickItemUsed.Broadcast(ActiveItem.ItemID, ActiveItem.Quantity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenQuickUseBeltComponent: USED quick item '%s' (ID: %s) — %d remaining."),
		*ActiveItem.ItemName, *ActiveItem.ItemID.ToString(), ActiveItem.Quantity);

	// Trigger cooldown
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(
			CooldownTimerHandle,
			this,
			&UAshenQuickUseBeltComponent::ResetCooldown,
			UseCooldownDuration,
			false
		);
	}

	return true;
}

FAshenItemData UAshenQuickUseBeltComponent::GetActiveItemData() const
{
	if (BeltSlots.IsValidIndex(ActiveSlotIndex))
	{
		return BeltSlots[ActiveSlotIndex];
	}
	return FAshenItemData();
}

void UAshenQuickUseBeltComponent::ResetCooldown()
{
	bOnCooldown = false;
	UE_LOG(LogTemp, Verbose, TEXT("UAshenQuickUseBeltComponent: Item use cooldown reset."));
}
