// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenCombatKinematicsSaveGameAdapter.h"

UAshenCombatKinematicsSaveGameAdapter::UAshenCombatKinematicsSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedCurrentWeightKg = 25.0f;
	SavedMaxEquipLoadKg = 50.0f;
	SavedWeightClass = EAshenWeightClass::MediumLoad;
}

void UAshenCombatKinematicsSaveGameAdapter::PackageKinematicsState(
	float CurrentWeightKg,
	float MaxEquipLoadKg,
	EAshenWeightClass WeightClass)
{
	SavedCurrentWeightKg = CurrentWeightKg;
	SavedMaxEquipLoadKg = MaxEquipLoadKg;
	SavedWeightClass = WeightClass;
	bHasSavedData = true;
}

bool UAshenCombatKinematicsSaveGameAdapter::RestoreKinematicsState(
	float& OutCurrentWeightKg,
	float& OutMaxEquipLoadKg,
	EAshenWeightClass& OutWeightClass)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutCurrentWeightKg = SavedCurrentWeightKg;
	OutMaxEquipLoadKg = SavedMaxEquipLoadKg;
	OutWeightClass = SavedWeightClass;
	return true;
}
