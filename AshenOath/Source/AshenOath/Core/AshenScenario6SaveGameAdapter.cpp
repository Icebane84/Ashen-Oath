// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenScenario6SaveGameAdapter.h"

UAshenScenario6SaveGameAdapter::UAshenScenario6SaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedHearthIgnition = 0.0f;
	SavedFrostbite = 0.0f;
	SavedLowestTempCelsius = -15.0f;
	bSavedSanctuaryComplete = false;
}

void UAshenScenario6SaveGameAdapter::PackageScenario6State(
	float HearthIgnition,
	float Frostbite,
	float LowestTempCelsius,
	bool bSanctuaryComplete)
{
	SavedHearthIgnition = HearthIgnition;
	SavedFrostbite = Frostbite;
	SavedLowestTempCelsius = LowestTempCelsius;
	bSavedSanctuaryComplete = bSanctuaryComplete;
	bHasSavedData = true;
}

bool UAshenScenario6SaveGameAdapter::RestoreScenario6State(
	float& OutHearthIgnition,
	float& OutFrostbite,
	float& OutLowestTemp,
	bool& OutSanctuaryComplete)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutHearthIgnition = SavedHearthIgnition;
	OutFrostbite = SavedFrostbite;
	OutLowestTemp = SavedLowestTempCelsius;
	OutSanctuaryComplete = bSavedSanctuaryComplete;
	return true;
}
