// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenCardiacExhaustionEvaluator.h"

UAshenCardiacExhaustionEvaluator::UAshenCardiacExhaustionEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenCardiacExhaustionEvaluator::EvaluateSwingWindupMultiplier(float CurrentStaminaPercent) const
{
	if (CurrentStaminaPercent < 0.35f)
	{
		// +25% slower swing windup during cardiac exhaustion
		return 0.75f;
	}
	return 1.0f;
}

float UAshenCardiacExhaustionEvaluator::EvaluateParryRecoveryMultiplier(float CurrentStaminaPercent) const
{
	if (CurrentStaminaPercent < 0.35f)
	{
		// +30% longer vulnerable recovery frames on missed parries
		return 1.30f;
	}
	return 1.0f;
}

float UAshenCardiacExhaustionEvaluator::EvaluateTriggerResistance(float CurrentStaminaPercent) const
{
	if (CurrentStaminaPercent < 0.35f)
	{
		const float Deficit = (0.35f - CurrentStaminaPercent) / 0.35f;
		return 0.50f + (Deficit * 0.35f); // 0.50 to 0.85 heavy resistance
	}
	return 0.10f; // Soft tactile tension
}
