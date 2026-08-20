// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenPromiseSaveGameAdapter.h"

UAshenPromiseSaveGameAdapter::UAshenPromiseSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenPromiseSaveGameAdapter::PackagePromiseData(
	int32 ActiveCount,
	int32 FulfilledCount,
	int32 MarginaliaCount)
{
	SavedActiveCount = ActiveCount;
	SavedFulfilledCount = FulfilledCount;
	SavedMarginaliaCount = MarginaliaCount;
	bHasSavedData = true;
}

bool UAshenPromiseSaveGameAdapter::RestorePromiseData(
	int32& OutActiveCount,
	int32& OutFulfilledCount,
	int32& OutMarginaliaCount)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutActiveCount = SavedActiveCount;
	OutFulfilledCount = SavedFulfilledCount;
	OutMarginaliaCount = SavedMarginaliaCount;
	return true;
}
