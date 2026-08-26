// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenWeatherAtmosphericPostProcessAdapter.h"

UAshenWeatherAtmosphericPostProcessAdapter::UAshenWeatherAtmosphericPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWeatherAtmosphericPostProcessAdapter::EvaluateWeatherPostProcess(
	EWeatherHazardState State,
	float& OutFrostVignetteDensity,
	float& OutAshFogDensity,
	float& OutLightningFlashBloom)
{
	switch (State)
	{
	case EWeatherHazardState::BlizzardWhiteout:
		OutFrostVignetteDensity = 0.85f;
		OutAshFogDensity = 0.0f;
		OutLightningFlashBloom = 0.0f;
		break;
	case EWeatherHazardState::VolcanicAshStorm:
		OutFrostVignetteDensity = 0.0f;
		OutAshFogDensity = 0.90f;
		OutLightningFlashBloom = 0.0f;
		break;
	case EWeatherHazardState::LightningSurge:
		OutFrostVignetteDensity = 0.0f;
		OutAshFogDensity = 0.20f;
		OutLightningFlashBloom = 1.50f;
		break;
	case EWeatherHazardState::AcidRainCorrosion:
		OutFrostVignetteDensity = 0.0f;
		OutAshFogDensity = 0.40f;
		OutLightningFlashBloom = 0.0f;
		break;
	case EWeatherHazardState::ClearTemperate:
	default:
		OutFrostVignetteDensity = 0.0f;
		OutAshFogDensity = 0.0f;
		OutLightningFlashBloom = 0.0f;
		break;
	}
}
