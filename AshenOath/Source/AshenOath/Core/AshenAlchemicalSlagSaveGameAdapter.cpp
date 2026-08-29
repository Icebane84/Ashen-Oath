// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenAlchemicalSlagSaveGameAdapter.h"

UAshenAlchemicalSlagSaveGameAdapter::UAshenAlchemicalSlagSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedSootLevel = 0.0f;
	SavedCoating = EAlchemicalBladeCoating::None;
	SavedCharges = 0;
}

void UAshenAlchemicalSlagSaveGameAdapter::PackageSlagState(
	float SootLevel,
	EAlchemicalBladeCoating Coating,
	int32 RemainingCharges)
{
	SavedSootLevel = SootLevel;
	SavedCoating = Coating;
	SavedCharges = RemainingCharges;
	bHasSavedData = true;
}

bool UAshenAlchemicalSlagSaveGameAdapter::RestoreSlagState(
	float& OutSootLevel,
	EAlchemicalBladeCoating& OutCoating,
	int32& OutRemainingCharges)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutSootLevel = SavedSootLevel;
	OutCoating = SavedCoating;
	OutRemainingCharges = SavedCharges;
	return true;
}
