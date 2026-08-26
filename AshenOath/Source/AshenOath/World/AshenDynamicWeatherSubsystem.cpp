// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenDynamicWeatherSubsystem.h"

UAshenDynamicWeatherSubsystem::UAshenDynamicWeatherSubsystem()
{
	CurrentAtmosphere.WeatherState = EWeatherHazardState::ClearTemperate;
	CurrentAtmosphere.Severity = EAtmosphericSeverity::MildDrift;
	CurrentAtmosphere.TemperatureCelsius = 18.0f;
	CurrentAtmosphere.VisibilityDistanceUU = 5000.0f;
	CurrentAtmosphere.WindShearVelocityMps = 5.0f;
	CurrentAtmosphere.AcidCorrosionRatePerSec = 0.0f;
	CurrentAtmosphere.LightningChargeBuildup01 = 0.0f;
}

void UAshenDynamicWeatherSubsystem::SetWeatherState(
	EWeatherHazardState NewState,
	EAtmosphericSeverity NewSeverity)
{
	CurrentAtmosphere.WeatherState = NewState;
	CurrentAtmosphere.Severity = NewSeverity;

	switch (NewState)
	{
	case EWeatherHazardState::BlizzardWhiteout:
		CurrentAtmosphere.TemperatureCelsius = -35.0f;
		CurrentAtmosphere.VisibilityDistanceUU = 400.0f;
		CurrentAtmosphere.WindShearVelocityMps = 32.0f;
		CurrentAtmosphere.AcidCorrosionRatePerSec = 0.0f;
		CurrentAtmosphere.LightningChargeBuildup01 = 0.0f;
		break;
	case EWeatherHazardState::VolcanicAshStorm:
		CurrentAtmosphere.TemperatureCelsius = 52.0f;
		CurrentAtmosphere.VisibilityDistanceUU = 800.0f;
		CurrentAtmosphere.WindShearVelocityMps = 18.0f;
		CurrentAtmosphere.AcidCorrosionRatePerSec = 0.0f;
		CurrentAtmosphere.LightningChargeBuildup01 = 0.0f;
		break;
	case EWeatherHazardState::AcidRainCorrosion:
		CurrentAtmosphere.TemperatureCelsius = 14.0f;
		CurrentAtmosphere.VisibilityDistanceUU = 1500.0f;
		CurrentAtmosphere.WindShearVelocityMps = 12.0f;
		CurrentAtmosphere.AcidCorrosionRatePerSec = 2.5f;
		CurrentAtmosphere.LightningChargeBuildup01 = 0.0f;
		break;
	case EWeatherHazardState::LightningSurge:
		CurrentAtmosphere.TemperatureCelsius = 16.0f;
		CurrentAtmosphere.VisibilityDistanceUU = 2000.0f;
		CurrentAtmosphere.WindShearVelocityMps = 24.0f;
		CurrentAtmosphere.AcidCorrosionRatePerSec = 0.0f;
		CurrentAtmosphere.LightningChargeBuildup01 = 0.85f;
		break;
	case EWeatherHazardState::ClearTemperate:
	default:
		CurrentAtmosphere.TemperatureCelsius = 18.0f;
		CurrentAtmosphere.VisibilityDistanceUU = 5000.0f;
		CurrentAtmosphere.WindShearVelocityMps = 5.0f;
		CurrentAtmosphere.AcidCorrosionRatePerSec = 0.0f;
		CurrentAtmosphere.LightningChargeBuildup01 = 0.0f;
		break;
	}

	OnWeatherStateChanged.Broadcast(CurrentAtmosphere.WeatherState, CurrentAtmosphere.TemperatureCelsius);
}

void UAshenDynamicWeatherSubsystem::UpdateWeatherCycle(float DeltaSeconds)
{
	if (CurrentAtmosphere.WeatherState == EWeatherHazardState::LightningSurge)
	{
		CurrentAtmosphere.LightningChargeBuildup01 = FMath::Clamp(CurrentAtmosphere.LightningChargeBuildup01 + (DeltaSeconds * 0.15f), 0.0f, 1.0f);
		if (CurrentAtmosphere.LightningChargeBuildup01 >= 1.0f)
		{
			FLightningStrikeHazardVector Strike;
			Strike.StrikeLocation = FVector(0.0f, 0.0f, 0.0f);
			Strike.TelegraphRadiusUU = 250.0f;
			Strike.TimeUntilImpactSeconds = 1.5f;
			Strike.StrikeDamage = 850.0f;
			OnLightningTelegraphed.Broadcast(Strike);
			CurrentAtmosphere.LightningChargeBuildup01 = 0.0f;
		}
	}
}
