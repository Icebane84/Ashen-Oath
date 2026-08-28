// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenQuartzDissonanceMixEvaluator.h"

UAshenQuartzDissonanceMixEvaluator::UAshenQuartzDissonanceMixEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenQuartzDissonanceMixEvaluator::EvaluateStem02WhisperGain(
	float CurrentSanity,
	bool bFlowStateActive) const
{
	if (bFlowStateActive)
	{
		return 0.0f; // Complete silence during flow state
	}

	const float SafeSanity = FMath::Clamp(CurrentSanity, 0.0f, 100.0f);
	return 1.0f - (SafeSanity / 100.0f); // 0.0 at 100 sanity, 1.0 at 0 sanity
}

float UAshenQuartzDissonanceMixEvaluator::EvaluateMelodicDuckingDb(
	float CurrentSanity,
	bool bFlowStateActive) const
{
	if (bFlowStateActive)
	{
		return 0.0f;
	}

	const float WhisperGain = EvaluateStem02WhisperGain(CurrentSanity, bFlowStateActive);
	return -18.0f * WhisperGain; // -18dB at max dissonance
}

float UAshenQuartzDissonanceMixEvaluator::EvaluateAudioLpfCutoffHz(float CurrentSanity) const
{
	const float SafeSanity = FMath::Clamp(CurrentSanity, 0.0f, 100.0f);
	const float Ratio = SafeSanity / 100.0f;
	return 300.0f + (Ratio * 7700.0f); // 300Hz muffled at 0 sanity, 8000Hz clear at 100 sanity
}
