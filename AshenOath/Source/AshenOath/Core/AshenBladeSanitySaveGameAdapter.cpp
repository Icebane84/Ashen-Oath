// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenBladeSanitySaveGameAdapter.h"

UAshenBladeSanitySaveGameAdapter::UAshenBladeSanitySaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedBladeHunger01 = 0.0f;
	SavedCurrentSanity = 100.0f;
	SavedDissonanceTier = ESanityDissonanceTier::LucidHarmonic;
}

void UAshenBladeSanitySaveGameAdapter::PackageConvergenceState(
	float BladeHunger01,
	float CurrentSanity,
	ESanityDissonanceTier DissonanceTier)
{
	SavedBladeHunger01 = BladeHunger01;
	SavedCurrentSanity = CurrentSanity;
	SavedDissonanceTier = DissonanceTier;
	bHasSavedData = true;
}

bool UAshenBladeSanitySaveGameAdapter::RestoreConvergenceState(
	float& OutBladeHunger01,
	float& OutCurrentSanity,
	ESanityDissonanceTier& OutDissonanceTier)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutBladeHunger01 = SavedBladeHunger01;
	OutCurrentSanity = SavedCurrentSanity;
	OutDissonanceTier = SavedDissonanceTier;
	return true;
}
