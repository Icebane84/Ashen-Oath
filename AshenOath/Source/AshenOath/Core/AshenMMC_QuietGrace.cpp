// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenMMC_QuietGrace.h"
#include "AshenAttributeSet.h"

UAshenMMC_QuietGrace::UAshenMMC_QuietGrace()
{
}

float UAshenMMC_QuietGrace::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// Quiet Grace scales mitigation: Base 15% mitigation, up to 40% based on Empathy Resonance
	float EmpathyResonance = 1.0f;
	float BaseMitigation = 0.15f;
	float TotalMitigation = FMath::Clamp(BaseMitigation * EmpathyResonance, 0.10f, 0.40f);

	return TotalMitigation;
}
