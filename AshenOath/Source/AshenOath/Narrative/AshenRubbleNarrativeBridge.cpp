// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenRubbleNarrativeBridge.h"

UAshenRubbleNarrativeBridge::UAshenRubbleNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenRubbleNarrativeBridge::FormatCollapseBark(
	EMasonryCollapseState CollapseState,
	EDemolitionToolType DemolitionTool) const
{
	switch (DemolitionTool)
	{
	case EDemolitionToolType::KaelenHeavyCleave:
		return FText::FromString(TEXT("[Kaelen]: 'Stand clear! The nightsteel will shatter these stones!'"));
	case EDemolitionToolType::GarrettBreachBomb:
		return FText::FromString(TEXT("[Garrett]: 'Breaching charge set. Cover your ears!'"));
	case EDemolitionToolType::SerafinaThermalPurge:
		return FText::FromString(TEXT("[Serafina]: 'The White Flame turns this granite to brittle chalk.'"));
	case EDemolitionToolType::None:
	default:
		break;
	}

	switch (CollapseState)
	{
	case EMasonryCollapseState::TelegraphWarning:
		return FText::FromString(TEXT("[Garrett]: 'Ceiling's giving way! MOVE!'"));
	case EMasonryCollapseState::StressGroaning:
		return FText::FromString(TEXT("[Serafina]: 'The archway is groaning... it won't hold much longer.'"));
	case EMasonryCollapseState::SettledDebrisPile:
		return FText::FromString(TEXT("[Garrett]: 'Corridor's blocked. We'll need heavy force to breach it.'"));
	case EMasonryCollapseState::CollapsingImpact:
	case EMasonryCollapseState::StableIntact:
	default:
		return FText::FromString(TEXT("[Kaelen]: 'Watch the overhead spans.'"));
	}
}
