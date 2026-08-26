// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenCookingPotSimmerPostProcessAdapter.h"

UAshenCookingPotSimmerPostProcessAdapter::UAshenCookingPotSimmerPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCookingPotSimmerPostProcessAdapter::EvaluateSimmerPostProcess(
	ECookingPotState PotState,
	float TemperatureCelsius,
	float& OutHeatHazeIntensity,
	float& OutCauldronAmberBloom,
	float& OutSteamVignette)
{
	if (PotState == ECookingPotState::ActiveStirring || PotState == ECookingPotState::SimmeringBoil)
	{
		const float TempRatio = FMath::Clamp((TemperatureCelsius - 60.0f) / 40.0f, 0.0f, 1.0f);
		OutHeatHazeIntensity = 0.40f + (TempRatio * 0.40f);
		OutCauldronAmberBloom = 0.80f + (TempRatio * 0.40f);
		OutSteamVignette = 0.25f;
	}
	else if (PotState == ECookingPotState::MealReadyServed)
	{
		OutHeatHazeIntensity = 0.20f;
		OutCauldronAmberBloom = 1.20f;
		OutSteamVignette = 0.15f;
	}
	else
	{
		OutHeatHazeIntensity = 0.0f;
		OutCauldronAmberBloom = 0.0f;
		OutSteamVignette = 0.0f;
	}
}
