// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenDestructionWeatherAISaveGameAdapter.h"

UAshenDestructionWeatherAISaveGameAdapter::UAshenDestructionWeatherAISaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedTier = EAtmosphericVisibilityTier::ClearDaylight;
	SavedLockOnRangeUU = 1500.0f;
	SavedObstacleCount = 0;
}

void UAshenDestructionWeatherAISaveGameAdapter::PackageTacticalState(
	EAtmosphericVisibilityTier VisibilityTier,
	float LockOnRangeUU,
	int32 CleavedObstacleCount)
{
	SavedTier = VisibilityTier;
	SavedLockOnRangeUU = LockOnRangeUU;
	SavedObstacleCount = CleavedObstacleCount;
	bHasSavedData = true;
}

bool UAshenDestructionWeatherAISaveGameAdapter::RestoreTacticalState(
	EAtmosphericVisibilityTier& OutTier,
	float& OutLockOnRangeUU,
	int32& OutObstacleCount)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutTier = SavedTier;
	OutLockOnRangeUU = SavedLockOnRangeUU;
	OutObstacleCount = SavedObstacleCount;
	return true;
}
