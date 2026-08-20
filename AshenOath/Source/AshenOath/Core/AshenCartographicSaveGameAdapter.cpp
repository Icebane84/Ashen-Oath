// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenCartographicSaveGameAdapter.h"

UAshenCartographicSaveGameAdapter::UAshenCartographicSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCartographicSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenCartographicSaveGameAdapter::SaveCartographicState(int32 TotalPins, int32 DiscoveredRegionsCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCartographicSaveGameAdapter: Saved Cartographic State -> %d Pins, %d Regions Discovered."),
		TotalPins, DiscoveredRegionsCount);
	return true;
}
