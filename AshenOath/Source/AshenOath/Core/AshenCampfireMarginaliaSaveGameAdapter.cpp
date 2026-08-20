// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenCampfireMarginaliaSaveGameAdapter.h"

UAshenCampfireMarginaliaSaveGameAdapter::UAshenCampfireMarginaliaSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenCampfireMarginaliaSaveGameAdapter::PackageMarginaliaHistory(const TArray<FMarginaliaEntry>& Entries)
{
	SavedEntries = Entries;
	bHasSavedData = true;
}

bool UAshenCampfireMarginaliaSaveGameAdapter::RestoreMarginaliaHistory(TArray<FMarginaliaEntry>& OutEntries)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutEntries = SavedEntries;
	return true;
}
