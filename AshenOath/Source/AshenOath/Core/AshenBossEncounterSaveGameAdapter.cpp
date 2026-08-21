// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenBossEncounterSaveGameAdapter.h"

UAshenBossEncounterSaveGameAdapter::UAshenBossEncounterSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenBossEncounterSaveGameAdapter::PackageBossData(
	bool bDefeated,
	int32 PillarsSundered,
	int32 RescuesPerformed)
{
	bSavedDefeated = bDefeated;
	SavedPillarsSundered = PillarsSundered;
	SavedRescuesPerformed = RescuesPerformed;
	bHasSavedData = true;
}

bool UAshenBossEncounterSaveGameAdapter::RestoreBossData(
	bool& OutDefeated,
	int32& OutPillarsSundered,
	int32& OutRescuesPerformed)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutDefeated = bSavedDefeated;
	OutPillarsSundered = SavedPillarsSundered;
	OutRescuesPerformed = SavedRescuesPerformed;
	return true;
}
