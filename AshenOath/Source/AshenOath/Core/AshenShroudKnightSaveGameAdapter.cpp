// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenShroudKnightSaveGameAdapter.h"

UAshenShroudKnightSaveGameAdapter::UAshenShroudKnightSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	bSavedDefeated = false;
	SavedFinalHealth = 1.0f;
	SavedMaxParanoia = 0.0f;
	SavedTrinityStrikes = 0;
}

void UAshenShroudKnightSaveGameAdapter::PackageBossMetrics(
	bool bDefeated,
	float FinalHealthPercent,
	float MaxParanoiaReached,
	int32 TrinityStrikesLanded)
{
	bSavedDefeated = bDefeated;
	SavedFinalHealth = FinalHealthPercent;
	SavedMaxParanoia = MaxParanoiaReached;
	SavedTrinityStrikes = TrinityStrikesLanded;
	bHasSavedData = true;
}

bool UAshenShroudKnightSaveGameAdapter::RestoreBossMetrics(
	bool& OutDefeated,
	float& OutFinalHealth,
	float& OutMaxParanoia,
	int32& OutTrinityStrikes)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutDefeated = bSavedDefeated;
	OutFinalHealth = SavedFinalHealth;
	OutMaxParanoia = SavedMaxParanoia;
	OutTrinityStrikes = SavedTrinityStrikes;
	return true;
}
