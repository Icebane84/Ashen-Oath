// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenChaosNavmeshSaveGameAdapter.h"

UAshenChaosNavmeshSaveGameAdapter::UAshenChaosNavmeshSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedFracturedPillarsCount = 0;
	SavedClearedDebrisCount = 0;
	SavedTotalDebrisMassKg = 0.0f;
}

void UAshenChaosNavmeshSaveGameAdapter::PackageChaosState(
	int32 FracturedPillarsCount,
	int32 ClearedDebrisCount,
	float TotalDebrisMassKg)
{
	SavedFracturedPillarsCount = FracturedPillarsCount;
	SavedClearedDebrisCount = ClearedDebrisCount;
	SavedTotalDebrisMassKg = TotalDebrisMassKg;
	bHasSavedData = true;
}

bool UAshenChaosNavmeshSaveGameAdapter::RestoreChaosState(
	int32& OutFracturedPillars,
	int32& OutClearedDebris,
	float& OutTotalMassKg)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutFracturedPillars = SavedFracturedPillarsCount;
	OutClearedDebris = SavedClearedDebrisCount;
	OutTotalMassKg = SavedTotalDebrisMassKg;
	return true;
}
