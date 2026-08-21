// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenScenario4SaveGameAdapter.h"

UAshenScenario4SaveGameAdapter::UAshenScenario4SaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	bSavedWhisperwoodCleared = false;
	SavedCognitiveLociCount = 0;
	SavedResultingSanity = 1.0f;
}

void UAshenScenario4SaveGameAdapter::PackageScenario4State(
	bool bWhisperwoodCleared,
	int32 CognitiveLociCount,
	float ResultingSanity)
{
	bSavedWhisperwoodCleared = bWhisperwoodCleared;
	SavedCognitiveLociCount = CognitiveLociCount;
	SavedResultingSanity = ResultingSanity;
	bHasSavedData = true;
}

bool UAshenScenario4SaveGameAdapter::RestoreScenario4State(
	bool& OutWhisperwoodCleared,
	int32& OutCognitiveLociCount,
	float& OutResultingSanity)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutWhisperwoodCleared = bSavedWhisperwoodCleared;
	OutCognitiveLociCount = SavedCognitiveLociCount;
	OutResultingSanity = SavedResultingSanity;
	return true;
}
