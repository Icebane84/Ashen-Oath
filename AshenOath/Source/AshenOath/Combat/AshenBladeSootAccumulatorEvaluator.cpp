// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenBladeSootAccumulatorEvaluator.h"

UAshenBladeSootAccumulatorEvaluator::UAshenBladeSootAccumulatorEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenBladeSootAccumulatorEvaluator::EvaluateStrikeSootGain(bool bIsHeavyCleave) const
{
	return bIsHeavyCleave ? 0.08f : 0.04f;
}

float UAshenBladeSootAccumulatorEvaluator::EvaluateExecutionSootGain() const
{
	return 0.15f; // Execution grants +15% soot burst
}

bool UAshenBladeSootAccumulatorEvaluator::IsSuperheatedSlag(float SootLevel) const
{
	return SootLevel >= 0.80f;
}
