// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenJournalDialogueBridge.h"

UAshenJournalDialogueBridge::UAshenJournalDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenJournalDialogueBridge::FormatScenarioCampfireBark(int32 ScenarioIndex, ECampfireReflectionMood Mood) const
{
	switch (ScenarioIndex)
	{
	case 1:
		return FText::FromString(TEXT("[Garrett]: 'The Bleeding Waystation... that was where we first learned blood alone cannot seal an Oath.'"));
	case 6:
		return FText::FromString(TEXT("[Serafina]: 'The hearth brazier in the northern marches... without its warmth, we would have frozen in our own doubts.'"));
	case 8:
		return FText::FromString(TEXT("[Kaelen]: 'In the Searing Abyss, even when the torch died, Garrett's twin-blade tap kept us grounded.'"));
	case 10:
		return FText::FromString(TEXT("[Serafina]: 'The Sovereign Convergence. Whatever our ending, the ink in this journal will never fade.'"));
	default:
		return FText::FromString(TEXT("[Kaelen]: 'Every scar has a page in this chronicle.'"));
	}
}
