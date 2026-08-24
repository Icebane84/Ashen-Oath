// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenAcousticEcholocationEvaluator.h"

UAshenAcousticEcholocationEvaluator::UAshenAcousticEcholocationEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenAcousticEcholocationEvaluator::EvaluateSonarPropagationRadius(EEcholocationPulseType PulseType) const
{
	switch (PulseType)
	{
	case EEcholocationPulseType::BladeClangEcho:
		return 900.0f;
	case EEcholocationPulseType::GroundSlamSonar:
		return 1800.0f;
	case EEcholocationPulseType::RadiantFlarePulse:
		return 1200.0f;
	default:
		return 350.0f; // Footstep
	}
}

float UAshenAcousticEcholocationEvaluator::EvaluateSonarContourOpacity(
	float TimeSincePulseSeconds,
	float PulseDurationSeconds) const
{
	if (PulseDurationSeconds <= 0.0f || TimeSincePulseSeconds >= PulseDurationSeconds)
	{
		return 0.0f;
	}

	// Quadratic fade out
	const float Alpha = 1.0f - (TimeSincePulseSeconds / PulseDurationSeconds);
	return Alpha * Alpha;
}
