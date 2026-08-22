// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenScenario5DialogueBridge.h"

UAshenScenario5DialogueBridge::UAshenScenario5DialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenScenario5DialogueBridge::FormatPhaseBark(EUnchainedVesselPhase Phase) const
{
	switch (Phase)
	{
	case EUnchainedVesselPhase::UnchainedFrenzy:
		return FText::FromString(TEXT("[Kaelen]: 'The oath shatters... ALL MUST BURN!'"));
	case EUnchainedVesselPhase::ExhaustedVulnerable:
		return FText::FromString(TEXT("[Garrett]: 'Kaelen's down! Form the line—nobody touches him!'"));
	case EUnchainedVesselPhase::Dormant:
	default:
		return FText::FromString(TEXT("[Garrett]: 'Watch the mud. Ignite the methane pockets with White Flame.'"));
	}
}
