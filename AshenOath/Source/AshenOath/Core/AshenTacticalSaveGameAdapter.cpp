// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenTacticalSaveGameAdapter.h"

UAshenTacticalSaveGameAdapter::UAshenTacticalSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenTacticalSaveGameAdapter::PackageTacticalSettings(
	bool bEnableBulletTime,
	float DilationScale,
	int32 DefaultSector)
{
	bSavedEnableBulletTime = bEnableBulletTime;
	SavedDilationScale = DilationScale;
	SavedDefaultSector = DefaultSector;
	bHasSavedData = true;
}

bool UAshenTacticalSaveGameAdapter::RestoreTacticalSettings(
	bool& OutEnableBulletTime,
	float& OutDilationScale,
	int32& OutDefaultSector)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutEnableBulletTime = bSavedEnableBulletTime;
	OutDilationScale = SavedDilationScale;
	OutDefaultSector = SavedDefaultSector;
	return true;
}
