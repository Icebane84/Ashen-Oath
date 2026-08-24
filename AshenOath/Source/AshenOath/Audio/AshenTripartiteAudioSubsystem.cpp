// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenTripartiteAudioSubsystem.h"

UAshenTripartiteAudioSubsystem::UAshenTripartiteAudioSubsystem()
{
}

float UAshenTripartiteAudioSubsystem::EvaluateTripartiteResonanceFrequency(ETripartiteBehaviorMode Mode) const
{
	switch (Mode)
	{
	case ETripartiteBehaviorMode::CombatEngagement:
		return 396.0f; // Liberation of Guilt & Root Grounding
	case ETripartiteBehaviorMode::ContemplativeSilence:
		return 528.0f; // Transformation & Miracles (Zen Stride)
	case ETripartiteBehaviorMode::CampfireRestoration:
		return 639.0f; // Harmonizing Relationships & Marginalia
	case ETripartiteBehaviorMode::TraumaAftermath:
	default:
		return 174.0f; // Subterranean Natural Anesthetic Low Drone
	}
}
