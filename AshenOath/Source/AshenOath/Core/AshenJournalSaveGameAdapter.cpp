// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenJournalSaveGameAdapter.h"

UAshenJournalSaveGameAdapter::UAshenJournalSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedUnlockedCount = 0;
	SavedTotalSoot = 0.0f;
	bSavedGarrettUnlocked = false;
	bSavedSerafinaUnlocked = false;
}

void UAshenJournalSaveGameAdapter::PackageJournalState(
	int32 UnlockedCount,
	float TotalSoot,
	bool bGarrettUnlocked,
	bool bSerafinaUnlocked)
{
	SavedUnlockedCount = UnlockedCount;
	SavedTotalSoot = TotalSoot;
	bSavedGarrettUnlocked = bGarrettUnlocked;
	bSavedSerafinaUnlocked = bSerafinaUnlocked;
	bHasSavedData = true;
}

bool UAshenJournalSaveGameAdapter::RestoreJournalState(
	int32& OutUnlockedCount,
	float& OutTotalSoot,
	bool& OutGarrettUnlocked,
	bool& OutSerafinaUnlocked)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutUnlockedCount = SavedUnlockedCount;
	OutTotalSoot = SavedTotalSoot;
	OutGarrettUnlocked = bSavedGarrettUnlocked;
	OutSerafinaUnlocked = bSavedSerafinaUnlocked;
	return true;
}
