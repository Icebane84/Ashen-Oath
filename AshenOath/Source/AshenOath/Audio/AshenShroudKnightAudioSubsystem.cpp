// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenShroudKnightAudioSubsystem.h"

UAshenShroudKnightAudioSubsystem::UAshenShroudKnightAudioSubsystem()
{
}

float UAshenShroudKnightAudioSubsystem::EvaluateParanoiaRingingGain(float Infection01) const
{
	return FMath::Clamp(Infection01 * 0.75f, 0.0f, 0.75f);
}

float UAshenShroudKnightAudioSubsystem::EvaluatePhaseWhooshVolume(EShroudKnightPhaseState PhaseState) const
{
	return (PhaseState == EShroudKnightPhaseState::SpectralPhasing) ? 0.85f : 0.0f;
}
