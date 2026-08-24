// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenCreepingParanoiaEvaluator.h"

UAshenCreepingParanoiaEvaluator::UAshenCreepingParanoiaEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenCreepingParanoiaEvaluator::IsPeripheralPhantomVisible(float AngleToCameraDegrees) const
{
	// Visible only in periphery (>= 45 deg). Vanishes immediately if player centers camera (< 35 deg)
	return FMath::Abs(AngleToCameraDegrees) >= 45.0f;
}

float UAshenCreepingParanoiaEvaluator::EvaluateChromaticJitter(float Infection01) const
{
	return FMath::Clamp(Infection01 * 4.5f, 0.0f, 4.5f);
}

float UAshenCreepingParanoiaEvaluator::EvaluateParanoiaVignette(float Infection01) const
{
	return FMath::Clamp(Infection01 * 0.85f, 0.0f, 0.85f);
}

float UAshenCreepingParanoiaEvaluator::EvaluateGroundingDecayRate(bool bHasCompanionEyeContact) const
{
	return bHasCompanionEyeContact ? -0.15f : 0.0f;
}
