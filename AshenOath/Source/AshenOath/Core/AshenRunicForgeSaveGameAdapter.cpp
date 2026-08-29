// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenRunicForgeSaveGameAdapter.h"

UAshenRunicForgeSaveGameAdapter::UAshenRunicForgeSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedTier = EOathbringerAscensionTier::Tier1_DullNightsteel;
	SavedVomTag = ESigilResonanceEffect::None;
	SavedPflug = ESigilResonanceEffect::None;
}

void UAshenRunicForgeSaveGameAdapter::PackageForgeState(
	EOathbringerAscensionTier Tier,
	ESigilResonanceEffect VomTagSigil,
	ESigilResonanceEffect PflugSigil)
{
	SavedTier = Tier;
	SavedVomTag = VomTagSigil;
	SavedPflug = PflugSigil;
	bHasSavedData = true;
}

bool UAshenRunicForgeSaveGameAdapter::RestoreForgeState(
	EOathbringerAscensionTier& OutTier,
	ESigilResonanceEffect& OutVomTag,
	ESigilResonanceEffect& OutPflug)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutTier = SavedTier;
	OutVomTag = SavedVomTag;
	OutPflug = SavedPflug;
	return true;
}

void UAshenRunicForgeSaveGameAdapter::PackageWeaponState(
	const FSoulForgeWeaponState& State)
{
	SavedWeaponState = State;
	bHasSavedData = true;
}

bool UAshenRunicForgeSaveGameAdapter::RestoreWeaponState(
	FSoulForgeWeaponState& OutState)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutState = SavedWeaponState;
	return true;
}
