// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSeveranceBloodSplatterPostProcessAdapter.h"

UAshenSeveranceBloodSplatterPostProcessAdapter::UAshenSeveranceBloodSplatterPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenSeveranceBloodSplatterPostProcessAdapter::EvaluateLensBloodIntensity(
	ESeveranceSeverityTier Severity) const
{
	switch (Severity)
	{
	case ESeveranceSeverityTier::Decapitation:
		return 0.85f;
	case ESeveranceSeverityTier::TotalBisection:
		return 0.95f;
	case ESeveranceSeverityTier::MajorLimb:
		return 0.50f;
	case ESeveranceSeverityTier::MinorLimb:
	default:
		return 0.20f;
	}
}
