// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenScenario5SaveGameAdapter.h"

UAshenScenario5SaveGameAdapter::UAshenScenario5SaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	bSavedMireCleared = false;
	SavedGasPocketsDetonated = 0;
	bSavedZeroDowned = true;
}

void UAshenScenario5SaveGameAdapter::PackageScenario5State(
	bool bMireCleared,
	int32 GasPocketsDetonated,
	bool bZeroDowned)
{
	bSavedMireCleared = bMireCleared;
	SavedGasPocketsDetonated = GasPocketsDetonated;
	bSavedZeroDowned = bZeroDowned;
	bHasSavedData = true;
}

bool UAshenScenario5SaveGameAdapter::RestoreScenario5State(
	bool& OutMireCleared,
	int32& OutGasPocketsDetonated,
	bool& OutZeroDowned)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutMireCleared = bSavedMireCleared;
	OutGasPocketsDetonated = SavedGasPocketsDetonated;
	OutZeroDowned = bSavedZeroDowned;
	return true;
}
