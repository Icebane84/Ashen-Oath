// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenThermalPostProcessVignetteAdapter.h"

UAshenThermalPostProcessVignetteAdapter::UAshenThermalPostProcessVignetteAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenThermalPostProcessVignetteAdapter::EvaluateThermalPostProcess(
	EThermalShelterTier Tier,
	float BodyTempC,
	float& OutFrostVignetteIntensity,
	float& OutWarmHearthGlowIntensity) const
{
	if (Tier == EThermalShelterTier::SanctuaryHearthRadius)
	{
		OutFrostVignetteIntensity = 0.0f;
		OutWarmHearthGlowIntensity = 1.0f; // Serene warm golden glow
		return;
	}

	// Hypothermia ice vignette scales below 35.0C
	if (BodyTempC < 35.0f)
	{
		OutFrostVignetteIntensity = FMath::Clamp((35.0f - BodyTempC) / 10.0f, 0.0f, 1.0f);
	}
	else
	{
		OutFrostVignetteIntensity = 0.0f;
	}

	OutWarmHearthGlowIntensity = (Tier == EThermalShelterTier::NaturalCavern) ? 0.35f : 0.0f;
}
