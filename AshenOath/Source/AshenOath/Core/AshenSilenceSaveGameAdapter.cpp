// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenSilenceSaveGameAdapter.h"

UAshenSilenceSaveGameAdapter::UAshenSilenceSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenSilenceSaveGameAdapter::PackageSilenceData(
	int32 WordlessActionsCount,
	int32 BoundaryRefusalsCount)
{
	SavedWordlessCount = WordlessActionsCount;
	SavedBoundaryCount = BoundaryRefusalsCount;
	bHasSavedData = true;
}

bool UAshenSilenceSaveGameAdapter::RestoreSilenceData(
	int32& OutWordlessCount,
	int32& OutBoundaryCount)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutWordlessCount = SavedWordlessCount;
	OutBoundaryCount = SavedBoundaryCount;
	return true;
}
