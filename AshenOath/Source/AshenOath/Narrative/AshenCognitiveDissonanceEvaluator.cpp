// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCognitiveDissonanceEvaluator.h"

UAshenCognitiveDissonanceEvaluator::UAshenCognitiveDissonanceEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenCognitiveDissonanceEvaluator::EvaluateSynergyDamageBonus(float DissonanceIndex) const
{
	const float SafeD = FMath::Clamp(DissonanceIndex, 0.0f, 1.0f);
	if (SafeD < 0.25f)
	{
		// +30% bonus scaling linearly to 0% at 0.25 Dissonance
		const float HarmonyFactor = (0.25f - SafeD) / 0.25f;
		return HarmonyFactor * 0.30f;
	}
	return 0.0f;
}

float UAshenCognitiveDissonanceEvaluator::EvaluateTandemStaminaMultiplier(float DissonanceIndex) const
{
	const float SafeD = FMath::Clamp(DissonanceIndex, 0.0f, 1.0f);
	if (SafeD > 0.50f)
	{
		const float FrictionFactor = (SafeD - 0.50f) / 0.50f;
		return 1.0f + (FrictionFactor * 0.20f); // 1.0x to 1.20x stamina drain
	}
	return 1.0f;
}

float UAshenCognitiveDissonanceEvaluator::EvaluateCompanionAssistDelaySeconds(float DissonanceIndex) const
{
	const float SafeD = FMath::Clamp(DissonanceIndex, 0.0f, 1.0f);
	return SafeD * 0.60f; // 0.0s delay at harmony, 0.60s hesitation at fracture
}
