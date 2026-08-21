// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenScenario4DialogueBridge.h"

UAshenScenario4DialogueBridge::UAshenScenario4DialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenScenario4DialogueBridge::FormatGroundingBark(ECompanionGroundingState GroundingResult) const
{
	switch (GroundingResult)
	{
	case ECompanionGroundingState::InvalidatedHallucination:
		return FText::FromString(TEXT("[Garrett]: 'There's nothing there, Kaelen. It's the purple mist playing tricks on your eyes. Look at me.'"));
	case ECompanionGroundingState::VerifiedPhysicalThreat:
		return FText::FromString(TEXT("[Garrett]: 'I see it too. Real flesh and steel. Take the flank!'"));
	case ECompanionGroundingState::PendingAlignment:
	default:
		return FText::FromString(TEXT("[Garrett]: 'Stay close. Don't lose sight of my back.'"));
	}
}
