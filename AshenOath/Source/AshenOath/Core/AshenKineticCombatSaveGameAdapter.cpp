// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenKineticCombatSaveGameAdapter.h"

UAshenKineticCombatSaveGameAdapter::UAshenKineticCombatSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenKineticCombatSaveGameAdapter::PackageKineticData(
	int32 DestroyedPillarsCount,
	float PeakKineticJoules,
	int32 SuccessfulParries)
{
	SavedDestroyedPillars = DestroyedPillarsCount;
	SavedPeakJoules = PeakKineticJoules;
	SavedParries = SuccessfulParries;
	bHasSavedData = true;
}

bool UAshenKineticCombatSaveGameAdapter::RestoreKineticData(
	int32& OutDestroyedPillars,
	float& OutPeakKineticJoules,
	int32& OutSuccessfulParries)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutDestroyedPillars = SavedDestroyedPillars;
	OutPeakKineticJoules = SavedPeakJoules;
	OutSuccessfulParries = SavedParries;
	return true;
}
