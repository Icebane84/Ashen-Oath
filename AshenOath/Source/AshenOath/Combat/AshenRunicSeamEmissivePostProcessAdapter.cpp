// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenRunicSeamEmissivePostProcessAdapter.h"

UAshenRunicSeamEmissivePostProcessAdapter::UAshenRunicSeamEmissivePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRunicSeamEmissivePostProcessAdapter::EvaluateSeamBloom(
	EOathbringerAscensionTier Tier,
	bool bResonating,
	float& OutBloomIntensity,
	float& OutLensFlareIntensity) const
{
	if (bResonating)
	{
		OutBloomIntensity = 1.00f;
		OutLensFlareIntensity = 0.85f; // Radiant finisher bloom
		return;
	}

	switch (Tier)
	{
	case EOathbringerAscensionTier::Tier5_GodslayerApex:
		OutBloomIntensity = 0.75f;
		OutLensFlareIntensity = 0.50f;
		break;
	case EOathbringerAscensionTier::Tier4_EldrinsCrucible:
		OutBloomIntensity = 0.50f;
		OutLensFlareIntensity = 0.30f;
		break;
	case EOathbringerAscensionTier::Tier3_SunderedSovereign:
		OutBloomIntensity = 0.35f;
		OutLensFlareIntensity = 0.15f;
		break;
	case EOathbringerAscensionTier::Tier2_AwakenedFuller:
		OutBloomIntensity = 0.20f;
		OutLensFlareIntensity = 0.05f;
		break;
	case EOathbringerAscensionTier::Tier1_DullNightsteel:
	default:
		OutBloomIntensity = 0.05f;
		OutLensFlareIntensity = 0.0f;
		break;
	}
}
