// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenScenario10SaveGameAdapter.h"

UAshenScenario10SaveGameAdapter::UAshenScenario10SaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedEnding = EZenithConsequenceEnding::RadiantTransfiguration;
	SavedFinalTrust01 = 0.85f;
	SavedFinalDebt01 = 0.20f;
	bSavedNewGamePlusUnlocked = false;
}

void UAshenScenario10SaveGameAdapter::PackageScenario10State(
	EZenithConsequenceEnding Ending,
	float FinalTrust01,
	float FinalDebt01,
	bool bNewGamePlusUnlocked)
{
	SavedEnding = Ending;
	SavedFinalTrust01 = FinalTrust01;
	SavedFinalDebt01 = FinalDebt01;
	bSavedNewGamePlusUnlocked = bNewGamePlusUnlocked;
	bHasSavedData = true;
}

bool UAshenScenario10SaveGameAdapter::RestoreScenario10State(
	EZenithConsequenceEnding& OutEnding,
	float& OutTrust01,
	float& OutDebt01,
	bool& OutNGPlus)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutEnding = SavedEnding;
	OutTrust01 = SavedFinalTrust01;
	OutDebt01 = SavedFinalDebt01;
	OutNGPlus = bSavedNewGamePlusUnlocked;
	return true;
}
