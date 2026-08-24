// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenScenario10AudioSubsystem.h"

UAshenScenario10AudioSubsystem::UAshenScenario10AudioSubsystem()
{
}

float UAshenScenario10AudioSubsystem::EvaluateApotheosisChoralGain(float Resonance01) const
{
	// Resonance 0.0 -> 0.0, 1.0 -> 1.0 full triad choral bloom
	return FMath::Clamp(Resonance01, 0.0f, 1.0f);
}
