// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenScenario6DialogueBridge.h"

UAshenScenario6DialogueBridge::UAshenScenario6DialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenScenario6DialogueBridge::FormatScenario6Bark(
	EFrostbiteSeverity Severity,
	EHearthSanctuaryState HearthState) const
{
	if (HearthState == EHearthSanctuaryState::SanctifiedBlaze)
	{
		return FText::FromString(TEXT("[Serafina]: 'The ancient flame breathes again! The cold cannot touch us here.'"));
	}

	if (Severity == EFrostbiteSeverity::Hypothermia)
	{
		return FText::FromString(TEXT("[Garrett]: 'Kaelen! Stay close to the torch! Your fingers are turning black!'"));
	}

	if (Severity == EFrostbiteSeverity::SlowingChill)
	{
		return FText::FromString(TEXT("[Serafina]: 'The storm bites deep. Channel the White Flame into the brazier before we freeze!'"));
	}

	return FText::FromString(TEXT("[Garrett]: 'Keep moving. The cold is relentless in these Northern Marches.'"));
}
