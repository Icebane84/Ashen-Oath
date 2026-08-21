// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenRunicForgeSaveGameAdapter.h"

UAshenRunicForgeSaveGameAdapter::UAshenRunicForgeSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenRunicForgeSaveGameAdapter::PackageWeaponState(const FSoulForgeWeaponState& State)
{
	SavedState = State;
	bHasSavedData = true;
}

bool UAshenRunicForgeSaveGameAdapter::RestoreWeaponState(FSoulForgeWeaponState& OutState)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutState = SavedState;
	return true;
}
