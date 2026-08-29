// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenSanctuarySurvivalSaveGameAdapter.h"

UAshenSanctuarySurvivalSaveGameAdapter::UAshenSanctuarySurvivalSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedMeal = ECookedMealBuffType::None;
	SavedDuration = 0.0f;
	SavedIgnitedCount = 0;
}

void UAshenSanctuarySurvivalSaveGameAdapter::PackageSurvivalState(
	ECookedMealBuffType ActiveMeal,
	float MealDuration,
	int32 IgnitedBeaconsCount)
{
	SavedMeal = ActiveMeal;
	SavedDuration = MealDuration;
	SavedIgnitedCount = IgnitedBeaconsCount;
	bHasSavedData = true;
}

bool UAshenSanctuarySurvivalSaveGameAdapter::RestoreSurvivalState(
	ECookedMealBuffType& OutMeal,
	float& OutDuration,
	int32& OutIgnitedCount)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutMeal = SavedMeal;
	OutDuration = SavedDuration;
	OutIgnitedCount = SavedIgnitedCount;
	return true;
}
