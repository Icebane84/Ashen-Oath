// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenParasiticBladeMassEvaluator.h"

UAshenParasiticBladeMassEvaluator::UAshenParasiticBladeMassEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenParasiticBladeMassEvaluator::EvaluateBladeMass(float Corruption01, bool bGloomwoodFrozen) const
{
	const float SafeCorr = FMath::Clamp(Corruption01, 0.0f, 1.0f);
	float Mass = 45.0f + (175.0f * SafeCorr);

	if (bGloomwoodFrozen)
	{
		Mass = FMath::Max(45.0f, Mass - 80.0f);
	}

	return Mass;
}

float UAshenParasiticBladeMassEvaluator::EvaluateKineticImpactMultiplier(float MassKg) const
{
	const float Ratio = FMath::Clamp((MassKg - 45.0f) / 175.0f, 0.0f, 1.0f);
	// 45kg -> 1.0x, 220kg -> 2.5x
	return 1.0f + (1.5f * Ratio);
}

float UAshenParasiticBladeMassEvaluator::EvaluateSwingPlayRate(float MassKg) const
{
	const float Ratio = FMath::Clamp((MassKg - 45.0f) / 175.0f, 0.0f, 1.0f);
	// 45kg -> 1.00, 220kg -> 0.45 play-rate
	return 1.0f - (0.55f * Ratio);
}
