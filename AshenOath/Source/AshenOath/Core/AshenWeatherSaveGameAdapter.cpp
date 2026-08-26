// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenWeatherSaveGameAdapter.h"

UAshenWeatherSaveGameAdapter::UAshenWeatherSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedWeatherState = EWeatherHazardState::ClearTemperate;
	SavedSeverity = EAtmosphericSeverity::MildDrift;
	SavedTemperature = 18.0f;
}

void UAshenWeatherSaveGameAdapter::PackageWeatherState(
	EWeatherHazardState WeatherState,
	EAtmosphericSeverity Severity,
	float Temperature)
{
	SavedWeatherState = WeatherState;
	SavedSeverity = Severity;
	SavedTemperature = Temperature;
	bHasSavedData = true;
}

bool UAshenWeatherSaveGameAdapter::RestoreWeatherState(
	EWeatherHazardState& OutWeatherState,
	EAtmosphericSeverity& OutSeverity,
	float& OutTemperature)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutWeatherState = SavedWeatherState;
	OutSeverity = SavedSeverity;
	OutTemperature = SavedTemperature;
	return true;
}
