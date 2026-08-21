// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenTripartiteSaveGameAdapter.h"

UAshenTripartiteSaveGameAdapter::UAshenTripartiteSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenTripartiteSaveGameAdapter::PackageTripartiteData(
	int32 TotalFinishers,
	int32 UnbrokenStreaks,
	float TotalCatharsisScore)
{
	SavedTotalFinishers = TotalFinishers;
	SavedUnbrokenStreaks = UnbrokenStreaks;
	SavedCatharsisScore = TotalCatharsisScore;
	bHasSavedData = true;
}

bool UAshenTripartiteSaveGameAdapter::RestoreTripartiteData(
	int32& OutTotalFinishers,
	int32& OutUnbrokenStreaks,
	float& OutTotalCatharsisScore)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutTotalFinishers = SavedTotalFinishers;
	OutUnbrokenStreaks = SavedUnbrokenStreaks;
	OutTotalCatharsisScore = SavedCatharsisScore;
	return true;
}
