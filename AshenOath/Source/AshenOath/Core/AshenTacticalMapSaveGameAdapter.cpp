// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenTacticalMapSaveGameAdapter.h"

UAshenTacticalMapSaveGameAdapter::UAshenTacticalMapSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedCurrentSanctuary = TEXT("Waypoint_Hearth_01");
	SavedDiscoveredCount = 1;
	SavedAttunedCount = 1;
}

void UAshenTacticalMapSaveGameAdapter::PackageMapState(
	const FString& CurrentSanctuary,
	int32 DiscoveredCount,
	int32 AttunedCount)
{
	SavedCurrentSanctuary = CurrentSanctuary;
	SavedDiscoveredCount = DiscoveredCount;
	SavedAttunedCount = AttunedCount;
	bHasSavedData = true;
}

bool UAshenTacticalMapSaveGameAdapter::RestoreMapState(
	FString& OutCurrentSanctuary,
	int32& OutDiscoveredCount,
	int32& OutAttunedCount)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutCurrentSanctuary = SavedCurrentSanctuary;
	OutDiscoveredCount = SavedDiscoveredCount;
	OutAttunedCount = SavedAttunedCount;
	return true;
}
