// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenCampfireCookingSaveGameAdapter.h"

UAshenCampfireCookingSaveGameAdapter::UAshenCampfireCookingSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedActiveMeal = ECampfireRecipeType::None;
	SavedBuffTimeRemaining = 0.0f;
	SavedRationsCount = 0;
}

void UAshenCampfireCookingSaveGameAdapter::PackageCookingState(
	ECampfireRecipeType ActiveMeal,
	float BuffTimeRemaining,
	int32 RationsCount)
{
	SavedActiveMeal = ActiveMeal;
	SavedBuffTimeRemaining = BuffTimeRemaining;
	SavedRationsCount = RationsCount;
	bHasSavedData = true;
}

bool UAshenCampfireCookingSaveGameAdapter::RestoreCookingState(
	ECampfireRecipeType& OutActiveMeal,
	float& OutBuffTimeRemaining,
	int32& OutRationsCount)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutActiveMeal = SavedActiveMeal;
	OutBuffTimeRemaining = SavedBuffTimeRemaining;
	OutRationsCount = SavedRationsCount;
	return true;
}
