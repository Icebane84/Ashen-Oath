// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Archive/AshenRelicInspectionEvaluatorComponent.h"

UAshenRelicInspectionEvaluatorComponent::UAshenRelicInspectionEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenRelicInspectionEvaluatorComponent::EvaluateSecretAngleAlignment(
	float CurrentYawDegrees,
	float TargetYawDegrees,
	float ToleranceDegrees) const
{
	const float Delta = FMath::Abs(FRotator::NormalizeAxis(CurrentYawDegrees - TargetYawDegrees));
	return Delta <= ToleranceDegrees;
}

float UAshenRelicInspectionEvaluatorComponent::EvaluateDecodedPercentage(
	float DwellTimeSeconds,
	float RequiredTimeSeconds) const
{
	if (RequiredTimeSeconds <= 0.0f)
	{
		return 1.0f;
	}

	return FMath::Clamp(DwellTimeSeconds / RequiredTimeSeconds, 0.0f, 1.0f);
}
