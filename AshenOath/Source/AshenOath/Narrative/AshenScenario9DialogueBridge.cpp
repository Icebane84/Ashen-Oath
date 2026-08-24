// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenScenario9DialogueBridge.h"

UAshenScenario9DialogueBridge::UAshenScenario9DialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenScenario9DialogueBridge::FormatCitadelDialogueBark(
	EWindShearGustState WindState,
	ETelekineticBridgeStatus Bridge) const
{
	if (Bridge == ETelekineticBridgeStatus::ChannelingForming)
	{
		return FText::FromString(TEXT("[Serafina]: 'Hold the perimeter! The light lattice is aligning across the chasm!'"));
	}

	if (WindState == EWindShearGustState::ViolentWindShear)
	{
		return FText::FromString(TEXT("[Garrett]: 'Incoming gale shear! Brace the anchors, don't get swept into the void!'"));
	}

	if (WindState == EWindShearGustState::GaleShearWarning)
	{
		return FText::FromString(TEXT("[Garrett]: 'Wind is picking up from the north... time your leaps between gusts!'"));
	}

	return FText::FromString(TEXT("[Serafina]: 'The void gravity feels weightless, but the fall is infinite. Stay focused.'"));
}
