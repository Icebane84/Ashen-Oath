// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 366: Ashen Ember Economy Crafting Subsystem

#include "AshenEmberEconomyCraftingSubsystem.h"
#include "AshenOath_CurrencyComponent.h"

void UAshenEmberEconomyCraftingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenEmberEconomyCraftingSubsystem: Initialized — Ember Forge Crafting Subsystem ONLINE."));
}

bool UAshenEmberEconomyCraftingSubsystem::CraftItemWithEmbers(FName ItemID, float EmberCost, AActor* CraftingActor)
{
	if (ItemID.IsNone() || !CraftingActor) return false;

	UAshenOath_CurrencyComponent* Currency = CraftingActor->FindComponentByClass<UAshenOath_CurrencyComponent>();
	if (Currency && Currency->GetEmbers() >= EmberCost)
	{
		Currency->DeductEmbers(EmberCost);
		OnItemCrafted.Broadcast(ItemID, EmberCost);

		UE_LOG(LogTemp, Warning, TEXT("UAshenEmberEconomyCraftingSubsystem: ITEM CRAFTED — '%s' (Spent %.0f Embers)."),
			*ItemID.ToString(), EmberCost);

		return true;
	}

	return false;
}
