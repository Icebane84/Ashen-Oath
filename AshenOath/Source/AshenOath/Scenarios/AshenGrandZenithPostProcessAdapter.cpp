// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenGrandZenithPostProcessAdapter.h"

UAshenGrandZenithPostProcessAdapter::UAshenGrandZenithPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenGrandZenithPostProcessAdapter::EvaluateApotheosisBloomIntensity(float Resonance01) const
{
	return FMath::Clamp(Resonance01, 0.0f, 1.0f);
}

float UAshenGrandZenithPostProcessAdapter::EvaluateChromaticRayIntensity(EApotheosisResonanceStage Stage) const
{
	switch (Stage)
	{
	case EApotheosisResonanceStage::SovereignApotheosis:
		return 1.0f;
	case EApotheosisResonanceStage::HarmonicBuildup:
		return 0.50f;
	default:
		return 0.10f;
	}
}
