// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenTacticalAudioSubsystem.h"

UAshenTacticalAudioSubsystem::UAshenTacticalAudioSubsystem()
{
}

float UAshenTacticalAudioSubsystem::EvaluateTemporalFilterCutoff(ETemporalDilationState State) const
{
	switch (State)
	{
	case ETemporalDilationState::TacticalSlowMo:
		return 450.0f; // Muffled underwater bullet time
	case ETemporalDilationState::ComboFreezeFrame:
		return 200.0f; // Deep bass sub-rumble
	case ETemporalDilationState::Realtime:
	default:
		return 20000.0f; // Full bandwidth
	}
}
