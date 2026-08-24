// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenScenario8SaveGameAdapter.h"

UAshenScenario8SaveGameAdapter::UAshenScenario8SaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedRemainingFuel01 = 1.0f;
	SavedFinalLightRadiusUU = 800.0f;
	SavedLurkersDefeated = 0;
	SavedDiscoveredChasms = 0;
}

void UAshenScenario8SaveGameAdapter::PackageScenario8State(
	float RemainingFuel01,
	float FinalLightRadiusUU,
	int32 LurkersDefeated,
	int32 DiscoveredChasms)
{
	SavedRemainingFuel01 = RemainingFuel01;
	SavedFinalLightRadiusUU = FinalLightRadiusUU;
	SavedLurkersDefeated = LurkersDefeated;
	SavedDiscoveredChasms = DiscoveredChasms;
	bHasSavedData = true;
}

bool UAshenScenario8SaveGameAdapter::RestoreScenario8State(
	float& OutFuel01,
	float& OutLightRadiusUU,
	int32& OutLurkers,
	int32& OutChasms)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutFuel01 = SavedRemainingFuel01;
	OutLightRadiusUU = SavedFinalLightRadiusUU;
	OutLurkers = SavedLurkersDefeated;
	OutChasms = SavedDiscoveredChasms;
	return true;
}
