// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario1HapticBridge.h"

UAshenScenario1HapticBridge::UAshenScenario1HapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenScenario1HapticBridge::EvaluateTitansStandTriggerResistance(
	bool bIsParrying,
	EMalakorBossPhase Phase) const
{
	if (!bIsParrying)
	{
		return 10.0f; // Low baseline resting tension
	}

	switch (Phase)
	{
	case EMalakorBossPhase::Phase3_AbominationCascade:
		return 100.0f; // Maximum hard stop resistance against colossal blow
	case EMalakorBossPhase::Phase2_PuristZealot:
		return 85.0f;
	case EMalakorBossPhase::Phase1_InquisitorSmash:
	default:
		return 70.0f;
	}
}
