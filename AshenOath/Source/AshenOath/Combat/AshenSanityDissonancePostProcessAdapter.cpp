// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSanityDissonancePostProcessAdapter.h"

UAshenSanityDissonancePostProcessAdapter::UAshenSanityDissonancePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSanityDissonancePostProcessAdapter::EvaluateSanityPostProcess(
	float CurrentSanity,
	bool bFlowStateActive,
	float& OutChromaticAberration,
	float& OutVignetteIntensity,
	float& OutEldritchDistortion)
{
	if (bFlowStateActive)
	{
		OutChromaticAberration = 0.0f;
		OutVignetteIntensity = 0.10f; // Soft clean focus
		OutEldritchDistortion = 0.0f;
		return;
	}

	const float SafeSanity = FMath::Clamp(CurrentSanity, 0.0f, 100.0f);
	const float Deficit = (100.0f - SafeSanity) / 100.0f; // 0.0 to 1.0

	OutChromaticAberration = Deficit * 0.85f;
	OutVignetteIntensity = 0.20f + (Deficit * 0.70f); // 0.20 to 0.90
	OutEldritchDistortion = Deficit * 0.65f;
}
