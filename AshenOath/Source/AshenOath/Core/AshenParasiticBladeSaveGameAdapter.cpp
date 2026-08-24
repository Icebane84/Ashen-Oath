// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenParasiticBladeSaveGameAdapter.h"

UAshenParasiticBladeSaveGameAdapter::UAshenParasiticBladeSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedCorruption01 = 0.15f;
	SavedMassKg = 45.0f;
	SavedNeedles = 3;
	SavedState = EBladeParasiteState::DormantSteel;
}

void UAshenParasiticBladeSaveGameAdapter::PackageBladeState(
	float Corruption01,
	float MassKg,
	int32 NeedlesRemaining,
	EBladeParasiteState State)
{
	SavedCorruption01 = Corruption01;
	SavedMassKg = MassKg;
	SavedNeedles = NeedlesRemaining;
	SavedState = State;
	bHasSavedData = true;
}

bool UAshenParasiticBladeSaveGameAdapter::RestoreBladeState(
	float& OutCorruption01,
	float& OutMassKg,
	int32& OutNeedlesRemaining,
	EBladeParasiteState& OutState)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutCorruption01 = SavedCorruption01;
	OutMassKg = SavedMassKg;
	OutNeedlesRemaining = SavedNeedles;
	OutState = SavedState;
	return true;
}
