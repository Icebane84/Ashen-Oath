// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenHeatDistortionPostProcessAdapter.h"

UAshenHeatDistortionPostProcessAdapter::UAshenHeatDistortionPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenHeatDistortionPostProcessAdapter::EvaluateHeatShimmerIntensity(float AmbientTempC) const
{
	// 40C to 100C scales 0.0 to 1.0 shimmer
	return FMath::Clamp((AmbientTempC - 40.0f) / 60.0f, 0.0f, 1.0f);
}

float UAshenHeatDistortionPostProcessAdapter::EvaluateCombustionVignette(float HeatExhaustion01) const
{
	return FMath::Clamp(HeatExhaustion01 * 0.85f, 0.0f, 0.85f);
}
