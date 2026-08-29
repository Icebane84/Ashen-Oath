// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenMindscapeSpectralPostProcessAdapter.h"

UAshenMindscapeSpectralPostProcessAdapter::UAshenMindscapeSpectralPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMindscapeSpectralPostProcessAdapter::EvaluateSpectralPostProcess(
	bool bInsideMindscape,
	float SynthesisScore,
	float& OutSpectralAberrationIntensity,
	float& OutHolographicScanlineIntensity) const
{
	if (!bInsideMindscape)
	{
		OutSpectralAberrationIntensity = 0.0f;
		OutHolographicScanlineIntensity = 0.0f;
		return;
	}

	OutSpectralAberrationIntensity = 0.40f + (SynthesisScore * 0.40f);
	OutHolographicScanlineIntensity = 0.65f;
}
