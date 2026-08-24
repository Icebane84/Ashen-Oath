// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenChaosSpatialAudioEvaluator.h"

UAshenChaosSpatialAudioEvaluator::UAshenChaosSpatialAudioEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenChaosSpatialAudioEvaluator::EvaluateImpactResonanceFrequency(
	EStructuralMaterialType Material,
	float ImpactJoules) const
{
	float BaseFreq = 450.0f; // Granite
	if (Material == EStructuralMaterialType::TimberSupport)
	{
		BaseFreq = 1200.0f;
	}
	else if (Material == EStructuralMaterialType::RunicBasalt)
	{
		BaseFreq = 639.0f;
	}

	const float Scaled = BaseFreq - (ImpactJoules / 50.0f);
	return FMath::Clamp(Scaled, 120.0f, 4500.0f);
}

float UAshenChaosSpatialAudioEvaluator::EvaluateRubbleSoundOcclusion(float DebrisMassKg) const
{
	// Up to 200kg debris blocks up to 75% sound transmission
	return FMath::Clamp(DebrisMassKg / 266.6f, 0.0f, 0.75f);
}
