// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "VFX/AshenCrimsonDischargeEvaluatorComponent.h"

UAshenCrimsonDischargeEvaluatorComponent::UAshenCrimsonDischargeEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCrimsonDischargeEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenCrimsonDischargeEvaluatorComponent::CalculateCrimsonSparksSpawnRate(float CorruptionScalar) const
{
	const float C = FMath::Clamp(CorruptionScalar, 0.0f, 1.0f);
	if (C < 0.70f) return 0.0f; // Fires aggressively only when unchained (>= 0.70)

	// Smoothstep from 0.70 to 1.0
	const float Alpha = (C - 0.70f) / (1.0f - 0.70f);
	const float SmoothAlpha = Alpha * Alpha * (3.0f - 2.0f * Alpha);
	const float SpawnRate = FMath::Lerp(0.0f, 250.0f, SmoothAlpha);

	return SpawnRate;
}

float UAshenCrimsonDischargeEvaluatorComponent::CalculateCurlNoiseStrength(float CorruptionScalar) const
{
	const float C = FMath::Clamp(CorruptionScalar, 0.0f, 1.0f);
	// Lerp(10.0, 450.0, C)
	const float Strength = FMath::Lerp(10.0f, 450.0f, C);
	return Strength;
}
