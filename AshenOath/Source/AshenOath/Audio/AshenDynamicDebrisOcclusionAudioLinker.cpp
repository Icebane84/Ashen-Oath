// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenDynamicDebrisOcclusionAudioLinker.h"

float UAshenDynamicDebrisOcclusionAudioLinker::CalculateDebrisLowPassCutoff(
	int32 ObstructingRubbleCount,
	float MaxDebrisCount,
	float BaseFrequency,
	float MuffledFloorFrequency)
{
	if (ObstructingRubbleCount <= 0)
	{
		return BaseFrequency;
	}

	const float Ratio = FMath::Clamp(static_cast<float>(ObstructingRubbleCount) / MaxDebrisCount, 0.0f, 1.0f);
	// Exponential audio attenuation curve
	const float Alpha = FMath::Pow(Ratio, 0.65f);
	return FMath::Lerp(BaseFrequency, MuffledFloorFrequency, Alpha);
}

EAshenDebrisOcclusionState UAshenDynamicDebrisOcclusionAudioLinker::EvaluateDebrisOcclusionState(int32 ObstructingRubbleCount)
{
	if (ObstructingRubbleCount >= 5)
	{
		return EAshenDebrisOcclusionState::BuriedUnderRubble;
	}
	else if (ObstructingRubbleCount >= 1)
	{
		return EAshenDebrisOcclusionState::PartialDebris;
	}

	return EAshenDebrisOcclusionState::Unoccluded;
}
