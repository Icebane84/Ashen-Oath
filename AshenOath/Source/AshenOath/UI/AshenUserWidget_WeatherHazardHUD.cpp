// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_WeatherHazardHUD.h"

UAshenUserWidget_WeatherHazardHUD::UAshenUserWidget_WeatherHazardHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedAtmosphere.WeatherState = EWeatherHazardState::ClearTemperate;
	DisplayedAtmosphere.Severity = EAtmosphericSeverity::MildDrift;
	DisplayedAtmosphere.TemperatureCelsius = 18.0f;
	DisplayedAtmosphere.VisibilityDistanceUU = 5000.0f;
	DisplayedAtmosphere.WindShearVelocityMps = 5.0f;
	DisplayedAtmosphere.AcidCorrosionRatePerSec = 0.0f;
	DisplayedAtmosphere.LightningChargeBuildup01 = 0.0f;
	DisplayedShelter = EWeatherShelterType::ExposedWilds;
}

void UAshenUserWidget_WeatherHazardHUD::UpdateWeatherHUD(
	const FWeatherAtmosphericVector& Atmosphere,
	EWeatherShelterType Shelter)
{
	DisplayedAtmosphere = Atmosphere;
	DisplayedShelter = Shelter;
}
