// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenScenario7AudioSubsystem.h"

UAshenScenario7AudioSubsystem::UAshenScenario7AudioSubsystem()
{
}

float UAshenScenario7AudioSubsystem::EvaluateMagmaRoarPitch(ECalderaSurgePhase Phase) const
{
	switch (Phase)
	{
	case ECalderaSurgePhase::ActiveEruption:
		return 1.45f;
	case ECalderaSurgePhase::TelegraphWarning:
		return 1.20f;
	case ECalderaSurgePhase::CoolingDissipation:
		return 0.95f;
	default:
		return 0.85f;
	}
}
