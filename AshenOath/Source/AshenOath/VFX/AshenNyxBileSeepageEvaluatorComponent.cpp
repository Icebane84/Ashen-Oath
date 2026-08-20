// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "VFX/AshenNyxBileSeepageEvaluatorComponent.h"

UAshenNyxBileSeepageEvaluatorComponent::UAshenNyxBileSeepageEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNyxBileSeepageEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenNyxBileSeepageEvaluatorComponent::CalculateBileSpawnRate(float CorruptionScalar) const
{
	const float C = FMath::Clamp(CorruptionScalar, 0.0f, 1.0f);
	if (C < 0.35f) return 0.0f; // Dormant during early corruption

	// Smoothstep from 0.35 to 1.0
	const float Alpha = (C - 0.35f) / (1.0f - 0.35f);
	const float SmoothAlpha = Alpha * Alpha * (3.0f - 2.0f * Alpha);
	const float SpawnRate = FMath::Lerp(0.0f, 35.0f, SmoothAlpha);

	return SpawnRate;
}

float UAshenNyxBileSeepageEvaluatorComponent::GetBileGravityForceZ() const
{
	return -450.0f;
}
