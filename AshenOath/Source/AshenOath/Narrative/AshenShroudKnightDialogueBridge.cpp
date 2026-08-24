// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenShroudKnightDialogueBridge.h"

UAshenShroudKnightDialogueBridge::UAshenShroudKnightDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenShroudKnightDialogueBridge::FormatBossCombatBark(
	EShroudKnightPhaseState PhaseState,
	ETrinityStrikeStep TrinityStep) const
{
	switch (TrinityStep)
	{
	case ETrinityStrikeStep::KaelenGuardBreak:
		return FText::FromString(TEXT("[Kaelen]: 'His guard is shattered! Garrett, pin him to the stones!'"));
	case ETrinityStrikeStep::GarrettThreadLock:
		return FText::FromString(TEXT("[Garrett]: 'Threads anchored! He can't phase! Serafina, burn him down!'"));
	case ETrinityStrikeStep::SerafinaPurgeBeam:
		return FText::FromString(TEXT("[Serafina]: 'By the White Flame... be cleansed of the dark!'"));
	case ETrinityStrikeStep::None:
	default:
		break;
	}

	if (PhaseState == EShroudKnightPhaseState::SpectralPhasing)
	{
		return FText::FromString(TEXT("[Eldrin]: 'He is already dead, boy. You cannot cut mist with cold iron.'"));
	}

	return FText::FromString(TEXT("[Garrett]: 'Look at his eyes—five twitching void lenses. Don't look away!'"));
}
