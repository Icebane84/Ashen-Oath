// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenFlowChainingTimingEvaluator.h"

UAshenFlowChainingTimingEvaluator::UAshenFlowChainingTimingEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenFlowChainingTimingEvaluator::IsWithinFlowGlintWindow(
	float CurrentTime,
	float WindowStart,
	float WindowDuration) const
{
	return (CurrentTime >= WindowStart && CurrentTime <= (WindowStart + WindowDuration));
}

float UAshenFlowChainingTimingEvaluator::EvaluateTransitionStaminaCost(
	EFlowChainingTimingQuality Quality) const
{
	if (Quality == EFlowChainingTimingQuality::FlowGlintClean)
	{
		return 0.0f; // Stamina-Neutral Transition
	}
	return 15.0f; // Standard stance shift penalty
}

float UAshenFlowChainingTimingEvaluator::EvaluateMomentumDamageBonus(
	EFlowChainingTimingQuality Quality) const
{
	if (Quality == EFlowChainingTimingQuality::FlowGlintClean)
	{
		return 0.25f; // +25% Momentum Damage Bonus
	}
	return 0.0f;
}
