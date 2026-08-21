// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenBossTensionAudioSubsystem.h"

UAshenBossTensionAudioSubsystem::UAshenBossTensionAudioSubsystem()
{
}

float UAshenBossTensionAudioSubsystem::EvaluateMusicTension(EBossEncounterPhase Phase) const
{
	switch (Phase)
	{
	case EBossEncounterPhase::Phase1_Guardian:
		return 1.0f;
	case EBossEncounterPhase::Phase2_NightsteelTitan:
		return 1.4f;
	case EBossEncounterPhase::Phase3_UmbralMeltdown:
		return 2.0f; // Maximum frantic tempo and distortion
	default:
		return 0.5f;
	}
}
