// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenScenario10DialogueBridge.h"

UAshenScenario10DialogueBridge::UAshenScenario10DialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenScenario10DialogueBridge::FormatEndingDialogue(EZenithConsequenceEnding Ending) const
{
	switch (Ending)
	{
	case EZenithConsequenceEnding::RadiantTransfiguration:
		return FText::FromString(TEXT("[Serafina & Garrett]: 'The White Flame burns pure. The three of us stand whole—our Oath is fulfilled.'"));
	case EZenithConsequenceEnding::CauterizedHegemony:
		return FText::FromString(TEXT("[Kaelen]: 'Through blood and iron, the Void is subjugated. Stand with me or step aside.'"));
	case EZenithConsequenceEnding::BleedingFracture:
		return FText::FromString(TEXT("[Garrett]: 'We survived... but the cost was our humanity. We walk alone from here.'"));
	case EZenithConsequenceEnding::AshenEclipse:
		return FText::FromString(TEXT("[The Void Sovereign]: 'The flesh has surrendered. A new age of eclipse awakens across the cosmos.'"));
	default:
		return FText::FromString(TEXT("[Serafina]: 'The Grand Zenith awaits our judgment.'"));
	}
}
