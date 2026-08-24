// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenPitchBlackPostProcessAdapter.h"

UAshenPitchBlackPostProcessAdapter::UAshenPitchBlackPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenPitchBlackPostProcessAdapter::EvaluateDarknessVignetteOpacity(float LightRadiusUU) const
{
	if (LightRadiusUU >= 800.0f)
	{
		return 0.0f;
	}

	// 800uu down to 100uu scales 0.0 to 0.95 vignette darkness
	const float Alpha = 1.0f - FMath::Clamp((LightRadiusUU - 100.0f) / 700.0f, 0.0f, 1.0f);
	return Alpha * 0.95f;
}

float UAshenPitchBlackPostProcessAdapter::EvaluateSonarContourGlow(float SonarRadiusUU) const
{
	return FMath::Clamp(SonarRadiusUU / 1800.0f, 0.0f, 1.0f);
}
