// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenParanoiaPostProcessAdapter.h"

UAshenParanoiaPostProcessAdapter::UAshenParanoiaPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenParanoiaPostProcessAdapter::EvaluatePostProcessParams(
	float Infection01,
	float& OutVignetteIntensity,
	float& OutChromaticJitter,
	float& OutDesaturation)
{
	const float SafeInf = FMath::Clamp(Infection01, 0.0f, 1.0f);
	OutVignetteIntensity = SafeInf * 0.85f;
	OutChromaticJitter = SafeInf * 4.5f;
	OutDesaturation = SafeInf * 0.40f;
}
