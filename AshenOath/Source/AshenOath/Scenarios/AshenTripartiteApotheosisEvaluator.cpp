// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenTripartiteApotheosisEvaluator.h"

UAshenTripartiteApotheosisEvaluator::UAshenTripartiteApotheosisEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenTripartiteApotheosisEvaluator::EvaluateApotheosisDamageMultiplier(float Resonance01) const
{
	const float ClampedRes = FMath::Clamp(Resonance01, 0.0f, 1.0f);
	// 0.0 -> 1.0x, 1.0 -> 4.0x
	return 1.0f + (3.0f * ClampedRes);
}

float UAshenTripartiteApotheosisEvaluator::EvaluateApotheosisDamageReduction(float Resonance01) const
{
	const float ClampedRes = FMath::Clamp(Resonance01, 0.0f, 1.0f);
	// 0.0 -> 0.0, 1.0 -> 0.75 (75% damage mitigation)
	return ClampedRes * 0.75f;
}
