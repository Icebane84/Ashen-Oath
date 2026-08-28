// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenBladeSanityFeedbackEvaluator.h"

UAshenBladeSanityFeedbackEvaluator::UAshenBladeSanityFeedbackEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenBladeSanityFeedbackEvaluator::EvaluateBladeDamageMultiplier(float BladeHunger01) const
{
	const float SafeHunger = FMath::Clamp(BladeHunger01, 0.0f, 1.0f);
	return 1.0f + (SafeHunger * 0.45f); // Up to +45% bonus damage at max hunger
}

float UAshenBladeSanityFeedbackEvaluator::EvaluateParryWindowPenalty(float CurrentSanity) const
{
	const float SafeSanity = FMath::Clamp(CurrentSanity, 0.0f, 100.0f);
	const float Deficit = (100.0f - SafeSanity) / 100.0f;
	return Deficit * 0.35f; // Up to -35% narrower parry window at 0 sanity
}

float UAshenBladeSanityFeedbackEvaluator::EvaluateDodgeStaminaMultiplier(float CurrentSanity) const
{
	const float SafeSanity = FMath::Clamp(CurrentSanity, 0.0f, 100.0f);
	const float Deficit = (100.0f - SafeSanity) / 100.0f;
	return 1.0f + (Deficit * 0.50f); // 1.0x to 1.5x stamina cost on dodge
}
