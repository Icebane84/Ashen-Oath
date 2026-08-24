// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenQuartzDialogueBridge.h"

UAshenQuartzDialogueBridge::UAshenQuartzDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenQuartzDialogueBridge::FormatFlowStateBark(ECombatFlowState FlowState) const
{
	switch (FlowState)
	{
	case ECombatFlowState::SymbioticResonance:
		return FText::FromString(TEXT("[Serafina]: 'I am holding the center. You will not break.'"));
	case ECombatFlowState::CrisisNearBreakdown:
		return FText::FromString(TEXT("[Garrett]: 'Check your fire! Kaelen, eyes on me!'"));
	case ECombatFlowState::SicknessDeepening:
		return FText::FromString(TEXT("[Kaelen]: 'Keep back... the blade is pulling hard today.'"));
	case ECombatFlowState::StandardTrioBaseline:
	default:
		return FText::FromString(TEXT("[Garrett]: 'Steady on the line. Watch the flanks.'"));
	}
}
