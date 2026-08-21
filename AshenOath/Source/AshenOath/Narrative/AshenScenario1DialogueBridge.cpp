// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenScenario1DialogueBridge.h"

UAshenScenario1DialogueBridge::UAshenScenario1DialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenScenario1DialogueBridge::FormatMalakorConfrontation(EMalakorBossPhase Phase) const
{
	switch (Phase)
	{
	case EMalakorBossPhase::Phase3_AbominationCascade:
		return FText::FromString(TEXT("[Brother Malakor]: 'Let the cage shatter! Only in total void is there true stillness!'"));
	case EMalakorBossPhase::Phase2_PuristZealot:
		return FText::FromString(TEXT("[Brother Malakor]: 'Your White Flame is a dying ember! It will not save your tainted vessel!'"));
	case EMalakorBossPhase::Phase1_InquisitorSmash:
	default:
		return FText::FromString(TEXT("[Brother Malakor]: 'You cling to false order, Kaelen. I will crush this altar to ash!'"));
	}
}
