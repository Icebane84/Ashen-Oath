// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenScenario2SaveGameAdapter.h"

UAshenScenario2SaveGameAdapter::UAshenScenario2SaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	bSavedSilentEscape = false;
	SavedEnemiesFunneled = 0;
	SavedTacticalProfile = TEXT("Calculated_Pragmatic");
}

void UAshenScenario2SaveGameAdapter::PackageScenario2State(
	bool bSilentEscape,
	int32 EnemiesFunneled,
	const FString& GarrettTacticalProfile)
{
	bSavedSilentEscape = bSilentEscape;
	SavedEnemiesFunneled = EnemiesFunneled;
	SavedTacticalProfile = GarrettTacticalProfile;
	bHasSavedData = true;
}

bool UAshenScenario2SaveGameAdapter::RestoreScenario2State(
	bool& OutSilentEscape,
	int32& OutEnemiesFunneled,
	FString& OutGarrettTacticalProfile)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutSilentEscape = bSavedSilentEscape;
	OutEnemiesFunneled = SavedEnemiesFunneled;
	OutGarrettTacticalProfile = SavedTacticalProfile;
	return true;
}
