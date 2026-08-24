// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenTripartiteDialogueBridge.h"

UAshenTripartiteDialogueBridge::UAshenTripartiteDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenTripartiteDialogueBridge::FormatTripartiteBark(
	ETripartiteBehaviorMode Mode,
	ECompanionAttunementPhase Phase) const
{
	switch (Mode)
	{
	case ETripartiteBehaviorMode::CombatEngagement:
		if (Phase == ECompanionAttunementPhase::UnifiedResonance)
		{
			return FText::FromString(TEXT("[Garrett]: 'Flank locked! Cleave now, Kaelen!' [Serafina]: 'The light is synchronized!'"));
		}
		return FText::FromString(TEXT("[Garrett]: 'Watch the left vector! Don't let them split us!'"));

	case ETripartiteBehaviorMode::ContemplativeSilence:
		return FText::FromString(TEXT("(Wordless solidarity: Garrett and Serafina match your stride in contemplative silence)."));

	case ETripartiteBehaviorMode::TraumaAftermath:
		return FText::FromString(TEXT("(Traumatic Silence: Nobody speaks. Companions keep a wide, guarded distance)."));

	case ETripartiteBehaviorMode::CampfireRestoration:
	default:
		return FText::FromString(TEXT("[Serafina]: 'The fire holds back the shadows. Let us record what was learned.'"));
	}
}
