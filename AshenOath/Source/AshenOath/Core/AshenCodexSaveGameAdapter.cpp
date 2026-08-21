// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenCodexSaveGameAdapter.h"

UAshenCodexSaveGameAdapter::UAshenCodexSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedUnlockedCount = 0;
}

void UAshenCodexSaveGameAdapter::PackageCodexState(int32 UnlockedCount, const TArray<FName>& UnlockedIds)
{
	SavedUnlockedCount = UnlockedCount;
	SavedUnlockedIds = UnlockedIds;
	bHasSavedData = true;
}

bool UAshenCodexSaveGameAdapter::RestoreCodexState(int32& OutUnlockedCount, TArray<FName>& OutUnlockedIds)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutUnlockedCount = SavedUnlockedCount;
	OutUnlockedIds = SavedUnlockedIds;
	return true;
}
