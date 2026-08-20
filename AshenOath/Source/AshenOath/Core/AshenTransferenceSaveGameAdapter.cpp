// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenTransferenceSaveGameAdapter.h"

UAshenTransferenceSaveGameAdapter::UAshenTransferenceSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenTransferenceSaveGameAdapter::PackageTransferenceData(
	float SerafinaBurnout,
	int32 MercyCount,
	int32 ExecutionCount)
{
	SavedBurnout = SerafinaBurnout;
	SavedMercyCount = MercyCount;
	SavedExecutionCount = ExecutionCount;
	bHasSavedData = true;
}

bool UAshenTransferenceSaveGameAdapter::RestoreTransferenceData(
	float& OutBurnout,
	int32& OutMercyCount,
	int32& OutExecutionCount)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutBurnout = SavedBurnout;
	OutMercyCount = SavedMercyCount;
	OutExecutionCount = SavedExecutionCount;
	return true;
}
