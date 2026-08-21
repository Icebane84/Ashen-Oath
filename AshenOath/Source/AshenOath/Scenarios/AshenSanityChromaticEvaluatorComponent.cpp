// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenSanityChromaticEvaluatorComponent.h"

UAshenSanityChromaticEvaluatorComponent::UAshenSanityChromaticEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenSanityChromaticEvaluatorComponent::EvaluateChromaticAberration(float Sanity) const
{
	const float ClampedSanity = FMath::Clamp(Sanity, 0.0f, 1.0f);
	// Low sanity = extreme color splitting (up to 5.0)
	return (1.0f - ClampedSanity) * 5.0f;
}
