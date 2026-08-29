// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenDestructionWeatherAINarrativeBridge.h"

UAshenDestructionWeatherAINarrativeBridge::UAshenDestructionWeatherAINarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenDestructionWeatherAINarrativeBridge::FormatTacticalBark(
	bool bConductiveHazard,
	bool bBlizzardAmbush,
	bool bCoverCollapse) const
{
	if (bConductiveHazard)
	{
		return FText::FromString(TEXT("[Garrett]: 'Get clear of that wet iron! The next lightning bolt will fry everything in the pool!'"));
	}
	else if (bCoverCollapse)
	{
		return FText::FromString(TEXT("[Serafina]: 'The archway is crumbling! Watch the falling stone!'"));
	}
	else if (bBlizzardAmbush)
	{
		return FText::FromString(TEXT("[Garrett]: 'They're using the whiteout to flank us! Watch the flanks!'"));
	}
	return FText::FromString(TEXT("[Serafina]: 'Hold the line. We use the terrain to break their charge.'"));
}
