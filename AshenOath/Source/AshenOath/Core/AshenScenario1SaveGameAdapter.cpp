// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenScenario1SaveGameAdapter.h"

UAshenScenario1SaveGameAdapter::UAshenScenario1SaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	bSavedChapelCleared = false;
	SavedIsolation = 0.0f;
	SavedDebt = 0.0f;
}

void UAshenScenario1SaveGameAdapter::PackageScenario1State(
	bool bChapelCleared,
	float ResultingIsolation,
	float ResultingDebt)
{
	bSavedChapelCleared = bChapelCleared;
	SavedIsolation = ResultingIsolation;
	SavedDebt = ResultingDebt;
	bHasSavedData = true;
}

bool UAshenScenario1SaveGameAdapter::RestoreScenario1State(
	bool& OutChapelCleared,
	float& OutIsolation,
	float& OutDebt)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutChapelCleared = bSavedChapelCleared;
	OutIsolation = SavedIsolation;
	OutDebt = SavedDebt;
	return true;
}
