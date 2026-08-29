// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenSeveranceSaveGameAdapter.h"

UAshenSeveranceSaveGameAdapter::UAshenSeveranceSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedDecapitations = 0;
	SavedBisections = 0;
	SavedLifetimeAdrenaline = 0.0f;
}

void UAshenSeveranceSaveGameAdapter::PackageSeveranceStats(
	int32 TotalDecapitations,
	int32 TotalBisections,
	float LifetimeAdrenalineGained)
{
	SavedDecapitations = TotalDecapitations;
	SavedBisections = TotalBisections;
	SavedLifetimeAdrenaline = LifetimeAdrenalineGained;
	bHasSavedData = true;
}

bool UAshenSeveranceSaveGameAdapter::RestoreSeveranceStats(
	int32& OutDecapitations,
	int32& OutBisections,
	float& OutLifetimeAdrenaline)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutDecapitations = SavedDecapitations;
	OutBisections = SavedBisections;
	OutLifetimeAdrenaline = SavedLifetimeAdrenaline;
	return true;
}
