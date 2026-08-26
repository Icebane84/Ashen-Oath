// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenMapParchmentPostProcessAdapter.h"

UAshenMapParchmentPostProcessAdapter::UAshenMapParchmentPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMapParchmentPostProcessAdapter::EvaluateMapParchmentPostProcess(
	bool bMapOpen,
	float& OutSepiaIntensity,
	float& OutInkContourContrast,
	float& OutVignetteRadius)
{
	if (bMapOpen)
	{
		OutSepiaIntensity = 0.85f;
		OutInkContourContrast = 1.30f;
		OutVignetteRadius = 0.40f;
	}
	else
	{
		OutSepiaIntensity = 0.0f;
		OutInkContourContrast = 1.0f;
		OutVignetteRadius = 0.0f;
	}
}
