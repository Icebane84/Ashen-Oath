// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenCampfireSaveGameAdapter.h"

UAshenCampfireSaveGameAdapter::UAshenCampfireSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenCampfireSaveGameAdapter::PackageCampfireData(
	int32 TotalRests,
	int32 UnlockedTraits,
	int32 DiscoveredNotes)
{
	SavedTotalRests = TotalRests;
	SavedUnlockedTraits = UnlockedTraits;
	SavedDiscoveredNotes = DiscoveredNotes;
	bHasSavedData = true;
}

bool UAshenCampfireSaveGameAdapter::RestoreCampfireData(
	int32& OutTotalRests,
	int32& OutUnlockedTraits,
	int32& OutDiscoveredNotes)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutTotalRests = SavedTotalRests;
	OutUnlockedTraits = SavedUnlockedTraits;
	OutDiscoveredNotes = SavedDiscoveredNotes;
	return true;
}
