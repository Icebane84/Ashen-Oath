// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenOath_QuickbarComponent.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_SanityComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"

UAshenOath_QuickbarComponent::UAshenOath_QuickbarComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// Default 4 slots
	QuickSlots.SetNum(4);
	CooldownTimers.Init(0.0f, 4);

	// Pre-populate canonical slots
	QuickSlots[0] = FQuickbarItemSlot{ FName("EmberVial"),            NSLOCTEXT("Quickbar", "Vial", "Ember Vial"),           3, 5, 2.0f };
	QuickSlots[1] = FQuickbarItemSlot{ FName("SulfurousSmokeBalm"),   NSLOCTEXT("Quickbar", "Smoke", "Sulfurous Smoke Balm"),  2, 3, 4.0f };
	QuickSlots[2] = FQuickbarItemSlot{ FName("GhostbloomTripwire"),  NSLOCTEXT("Quickbar", "Wire", "Ghostbloom Tripwire"),   2, 3, 5.0f };
	QuickSlots[3] = FQuickbarItemSlot{ FName("TransferenceCatalyst"), NSLOCTEXT("Quickbar", "Cat", "Transference Catalyst"), 1, 2, 8.0f };
}

void UAshenOath_QuickbarComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenOath_QuickbarComponent::EquipItemToSlot(int32 SlotIndex, FName ItemId, FText DisplayName, int32 Quantity, float Cooldown)
{
	if (!QuickSlots.IsValidIndex(SlotIndex))
	{
		return false;
	}

	QuickSlots[SlotIndex].ItemId = ItemId;
	QuickSlots[SlotIndex].ItemDisplayName = DisplayName;
	QuickSlots[SlotIndex].Quantity = Quantity;
	QuickSlots[SlotIndex].CooldownDuration = Cooldown;

	OnQuickSlotChanged.Broadcast(SlotIndex, QuickSlots[SlotIndex]);
	UE_LOG(LogTemp, Log, TEXT("UAshenOath_QuickbarComponent: Equipped '%s' (x%d) to Slot %d"), *ItemId.ToString(), Quantity, SlotIndex);
	return true;
}

bool UAshenOath_QuickbarComponent::UseQuickSlot(int32 SlotIndex)
{
	if (!QuickSlots.IsValidIndex(SlotIndex))
	{
		return false;
	}

	FQuickbarItemSlot& Slot = QuickSlots[SlotIndex];
	if (Slot.Quantity <= 0 || IsSlotOnCooldown(SlotIndex))
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenOath_QuickbarComponent: Cannot use Slot %d — empty or on cooldown!"), SlotIndex);
		return false;
	}

	// Consume item
	Slot.Quantity--;
	AActor* OwnerActor = GetOwner();

	// Apply canonical item effect
	if (Slot.ItemId == FName("EmberVial") && OwnerActor)
	{
		if (UAshenOath_HealthComponent* Health = OwnerActor->FindComponentByClass<UAshenOath_HealthComponent>())
		{
			Health->Heal(50.0f);
		}
	}
	else if (Slot.ItemId == FName("TransferenceCatalyst") && OwnerActor)
	{
		if (UAshenOath_SanityComponent* Sanity = OwnerActor->FindComponentByClass<UAshenOath_SanityComponent>())
		{
			Sanity->SetCurrentSanity(Sanity->GetCurrentSanity() + 25.0f);
		}
	}

	// Start Cooldown timer
	CooldownTimers[SlotIndex] = GetWorld() ? GetWorld()->GetTimeSeconds() + Slot.CooldownDuration : 0.0f;

	OnQuickItemUsed.Broadcast(SlotIndex, Slot.ItemId);
	OnQuickSlotChanged.Broadcast(SlotIndex, Slot);

	UE_LOG(LogTemp, Log, TEXT("UAshenOath_QuickbarComponent: Used Slot %d ('%s') — %d remaining"), SlotIndex, *Slot.ItemId.ToString(), Slot.Quantity);
	return true;
}

bool UAshenOath_QuickbarComponent::GetSlotData(int32 SlotIndex, FQuickbarItemSlot& OutSlotData) const
{
	if (QuickSlots.IsValidIndex(SlotIndex))
	{
		OutSlotData = QuickSlots[SlotIndex];
		return true;
	}
	return false;
}

bool UAshenOath_QuickbarComponent::IsSlotOnCooldown(int32 SlotIndex) const
{
	if (CooldownTimers.IsValidIndex(SlotIndex) && GetWorld())
	{
		return GetWorld()->GetTimeSeconds() < CooldownTimers[SlotIndex];
	}
	return false;
}
