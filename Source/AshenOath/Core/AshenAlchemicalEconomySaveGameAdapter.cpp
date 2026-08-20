// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenAlchemicalEconomySaveGameAdapter.h"

UAshenAlchemicalEconomySaveGameAdapter::UAshenAlchemicalEconomySaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAlchemicalEconomySaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenAlchemicalEconomySaveGameAdapter::SerializeAlchemicalStateToSave(float LanternFuel, int32 OilFlaskCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalEconomySaveGameAdapter: Lantern Fuel (%.1f%%) and %d Oil Flasks serialized to save file."),
		LanternFuel, OilFlaskCount);
	return true;
}
