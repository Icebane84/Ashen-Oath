// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenKineticBerserkSaveGameAdapter.h"

UAshenKineticBerserkSaveGameAdapter::UAshenKineticBerserkSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedTotalRipostes = 0;
	SavedMaxRecordedJoules = 0.0f;
	SavedStructuralFractures = 0;
}

void UAshenKineticBerserkSaveGameAdapter::PackageKineticStats(
	int32 TotalRipostes,
	float MaxRecordedJoules,
	int32 StructuralFractures)
{
	SavedTotalRipostes = TotalRipostes;
	SavedMaxRecordedJoules = MaxRecordedJoules;
	SavedStructuralFractures = StructuralFractures;
	bHasSavedData = true;
}

bool UAshenKineticBerserkSaveGameAdapter::RestoreKineticStats(
	int32& OutTotalRipostes,
	float& OutMaxRecordedJoules,
	int32& OutStructuralFractures)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutTotalRipostes = SavedTotalRipostes;
	OutMaxRecordedJoules = SavedMaxRecordedJoules;
	OutStructuralFractures = SavedStructuralFractures;
	return true;
}
