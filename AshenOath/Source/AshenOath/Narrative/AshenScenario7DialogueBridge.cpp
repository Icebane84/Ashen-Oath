// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenScenario7DialogueBridge.h"

UAshenScenario7DialogueBridge::UAshenScenario7DialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenScenario7DialogueBridge::FormatCalderaDialogueBark(
	EHeatExhaustionTier Tier,
	ECalderaSurgePhase Phase) const
{
	if (Phase == ECalderaSurgePhase::ActiveEruption)
	{
		return FText::FromString(TEXT("[Garrett]: 'MAGMA ERUPTION! GET BEHIND SERAFINA'S BARRIER NOW!'"));
	}

	if (Phase == ECalderaSurgePhase::TelegraphWarning)
	{
		return FText::FromString(TEXT("[Serafina]: 'The ground fissures are glowing white-hot... move!'"));
	}

	if (Tier == EHeatExhaustionTier::Incinerating || Tier == EHeatExhaustionTier::Heatstroke)
	{
		return FText::FromString(TEXT("[Garrett]: 'The air is searing my lungs! Drop into my cryo mist!'"));
	}

	return FText::FromString(TEXT("[Serafina]: 'The Ashen Crucible is near. The magma vents can temper our steel.'"));
}
