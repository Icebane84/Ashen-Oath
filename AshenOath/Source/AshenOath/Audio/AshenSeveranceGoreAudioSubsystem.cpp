// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenSeveranceGoreAudioSubsystem.h"

UAshenSeveranceGoreAudioSubsystem::UAshenSeveranceGoreAudioSubsystem()
{
}

void UAshenSeveranceGoreAudioSubsystem::EvaluateSeveranceAcoustics(
	ESeveranceSeverityTier Severity,
	float& OutBoneCrushGain,
	float& OutBloodSplatterGain) const
{
	switch (Severity)
	{
	case ESeveranceSeverityTier::Decapitation:
		OutBoneCrushGain = 0.85f;
		OutBloodSplatterGain = 0.95f; // High arterial spray
		break;
	case ESeveranceSeverityTier::TotalBisection:
		OutBoneCrushGain = 1.00f; // Massive heavy bone cleavage
		OutBloodSplatterGain = 0.90f;
		break;
	case ESeveranceSeverityTier::MajorLimb:
		OutBoneCrushGain = 0.70f;
		OutBloodSplatterGain = 0.65f;
		break;
	case ESeveranceSeverityTier::MinorLimb:
	default:
		OutBoneCrushGain = 0.40f;
		OutBloodSplatterGain = 0.35f;
		break;
	}
}
