// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenBladeSanityFeedbackEvaluator.h"

UAshenBladeSanityFeedbackEvaluator::UAshenBladeSanityFeedbackEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	BalanceDataAsset = nullptr;
}

float UAshenBladeSanityFeedbackEvaluator::EvaluateBladeDamageMultiplier(float BladeHunger01) const
{
	const float ClampedHunger = FMath::Clamp(BladeHunger01, 0.0f, 1.0f);
	float MaxMultiplier = 1.45f;

	if (BalanceDataAsset)
	{
		MaxMultiplier = BalanceDataAsset->GetClampedBladeHunger().MaxDamageMultiplier;
	}

	// Linear scaling from 1.0x to MaxMultiplier
	return 1.0f + ((MaxMultiplier - 1.0f) * ClampedHunger);
}

float UAshenBladeSanityFeedbackEvaluator::EvaluateParryWindowPenalty(float CurrentSanity) const
{
	const float NormalizedSanity = FMath::Clamp(CurrentSanity / 100.0f, 0.0f, 1.0f);
	float MaxPenalty = 0.35f;

	if (BalanceDataAsset)
	{
		MaxPenalty = BalanceDataAsset->GetClampedBladeHunger().MaxParryWindowPenalty;
	}

	// 100 Sanity -> 0.0 penalty, 0 Sanity -> MaxPenalty
	return (1.0f - NormalizedSanity) * MaxPenalty;
}

float UAshenBladeSanityFeedbackEvaluator::EvaluateDodgeStaminaMultiplier(float CurrentSanity) const
{
	const float NormalizedSanity = FMath::Clamp(CurrentSanity / 100.0f, 0.0f, 1.0f);
	float MaxDodgeMultiplier = 1.50f;

	if (BalanceDataAsset)
	{
		MaxDodgeMultiplier = BalanceDataAsset->GetClampedBladeHunger().MaxDodgeStaminaMultiplier;
	}

	// 100 Sanity -> 1.0x cost, 0 Sanity -> MaxDodgeMultiplier
	return 1.0f + ((MaxDodgeMultiplier - 1.0f) * (1.0f - NormalizedSanity));
}
