// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenAdrenalineSurgeEvaluator.h"

UAshenAdrenalineSurgeEvaluator::UAshenAdrenalineSurgeEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenAdrenalineSurgeEvaluator::EvaluateAdrenalineGain(
	ESeveranceSeverityTier Severity) const
{
	switch (Severity)
	{
	case ESeveranceSeverityTier::Decapitation:
		return 35.0f;
	case ESeveranceSeverityTier::TotalBisection:
		return 40.0f;
	case ESeveranceSeverityTier::MajorLimb:
		return 25.0f;
	case ESeveranceSeverityTier::MinorLimb:
	default:
		return 15.0f;
	}
}

float UAshenAdrenalineSurgeEvaluator::EvaluateStaminaRefill(
	float CurrentAdrenaline) const
{
	return FMath::Clamp(CurrentAdrenaline * 0.50f, 15.0f, 50.0f);
}
