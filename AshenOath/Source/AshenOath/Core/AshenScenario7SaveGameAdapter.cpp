// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenScenario7SaveGameAdapter.h"

UAshenScenario7SaveGameAdapter::UAshenScenario7SaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedMaxTempSurvivedC = 0.0f;
	SavedFinalHeatExhaustion = 0.0f;
	SavedFinalBladeTempC = 0.0f;
	SavedFinalBladeState = ETemperedBladeState::ColdSteel;
}

void UAshenScenario7SaveGameAdapter::PackageScenario7State(
	float MaxTempSurvivedC,
	float FinalHeatExhaustion,
	float FinalBladeTempC,
	ETemperedBladeState FinalBladeState)
{
	SavedMaxTempSurvivedC = MaxTempSurvivedC;
	SavedFinalHeatExhaustion = FinalHeatExhaustion;
	SavedFinalBladeTempC = FinalBladeTempC;
	SavedFinalBladeState = FinalBladeState;
	bHasSavedData = true;
}

bool UAshenScenario7SaveGameAdapter::RestoreScenario7State(
	float& OutMaxTempC,
	float& OutHeatExhaustion,
	float& OutBladeTempC,
	ETemperedBladeState& OutBladeState)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutMaxTempC = SavedMaxTempSurvivedC;
	OutHeatExhaustion = SavedFinalHeatExhaustion;
	OutBladeTempC = SavedFinalBladeTempC;
	OutBladeState = SavedFinalBladeState;
	return true;
}
