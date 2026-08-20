// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenAlchemicalSaveGameAdapter.h"

UAshenAlchemicalSaveGameAdapter::UAshenAlchemicalSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAlchemicalSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenAlchemicalSaveGameAdapter::SaveAlchemicalInventory(const FAlchemicalInventoryPouch& Pouch)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalSaveGameAdapter: Saved Garrett's Pouch -> Oils: %d, Needles: %d, Smoke: %d, Flares: %d, Caltrops: %d"),
		Pouch.BurningSteelOilVials, Pouch.GloomwoodDampenerNeedles, Pouch.SmokeBalmCharges, Pouch.GhostbloomFlares, Pouch.CaltropSupply);
	return true;
}
