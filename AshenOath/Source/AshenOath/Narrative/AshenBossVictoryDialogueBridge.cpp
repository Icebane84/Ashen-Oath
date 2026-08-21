// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenBossVictoryDialogueBridge.h"

UAshenBossVictoryDialogueBridge::UAshenBossVictoryDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenBossVictoryDialogueBridge::FormatVictoryDialogue(
	const FString& BasePrompt,
	int32 RescuesPerformed,
	int32 PillarsSundered) const
{
	const FString Formatted = FString::Printf(
		TEXT("%s\n[Sundered Sanctuary Cleared: %d Pillars Sundered in the fracture, %d Fellowships Rescued under pinning crisis.]"),
		*BasePrompt,
		PillarsSundered,
		RescuesPerformed);
	return FText::FromString(Formatted);
}
