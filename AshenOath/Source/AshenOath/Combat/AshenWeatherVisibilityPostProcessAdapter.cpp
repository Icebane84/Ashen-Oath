// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenWeatherVisibilityPostProcessAdapter.h"

UAshenWeatherVisibilityPostProcessAdapter::UAshenWeatherVisibilityPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWeatherVisibilityPostProcessAdapter::EvaluateWeatherPostProcess(
	EAtmosphericVisibilityTier VisibilityTier,
	float& OutVolumetricFogDensity,
	float& OutDepthWhiteoutFactor,
	float& OutVignetteDarkening) const
{
	switch (VisibilityTier)
	{
	case EAtmosphericVisibilityTier::BlizzardWhiteout:
		OutVolumetricFogDensity = 0.90f;
		OutDepthWhiteoutFactor = 0.85f;
		OutVignetteDarkening = 0.40f;
		break;

	case EAtmosphericVisibilityTier::VolcanicAshStorm:
		OutVolumetricFogDensity = 0.70f;
		OutDepthWhiteoutFactor = 0.60f;
		OutVignetteDarkening = 0.65f;
		break;

	case EAtmosphericVisibilityTier::AcidRainMist:
		OutVolumetricFogDensity = 0.45f;
		OutDepthWhiteoutFactor = 0.30f;
		OutVignetteDarkening = 0.30f;
		break;

	case EAtmosphericVisibilityTier::ClearDaylight:
	default:
		OutVolumetricFogDensity = 0.05f;
		OutDepthWhiteoutFactor = 0.0f;
		OutVignetteDarkening = 0.10f;
		break;
	}
}
