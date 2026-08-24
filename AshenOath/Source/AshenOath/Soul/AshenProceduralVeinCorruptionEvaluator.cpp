// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenProceduralVeinCorruptionEvaluator.h"

UAshenProceduralVeinCorruptionEvaluator::UAshenProceduralVeinCorruptionEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenProceduralVeinCorruptionEvaluator::ComputeVeinCorruption(float IntegrationDebt, float ShadowBurnout) const
{
	return FMath::Clamp(IntegrationDebt * 1.15f + ShadowBurnout * 0.35f, 0.0f, 1.0f);
}

float UAshenProceduralVeinCorruptionEvaluator::ComputeSkinPallor(float IntegrationDebt) const
{
	return FMath::Clamp(IntegrationDebt * 0.85f, 0.0f, 1.0f);
}

float UAshenProceduralVeinCorruptionEvaluator::ComputeScleraRedness(float IntegrationDebt) const
{
	return FMath::Clamp((IntegrationDebt - 0.30f) / 0.70f, 0.0f, 1.0f);
}
