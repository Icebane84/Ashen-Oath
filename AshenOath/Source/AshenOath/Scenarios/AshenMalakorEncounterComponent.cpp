// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenMalakorEncounterComponent.h"

UAshenMalakorEncounterComponent::UAshenMalakorEncounterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

EMalakorBossPhase UAshenMalakorEncounterComponent::EvaluatePhase(float HealthPercent) const
{
	if (HealthPercent <= 0.35f)
	{
		return EMalakorBossPhase::Phase3_AbominationCascade;
	}
	else if (HealthPercent <= 0.70f)
	{
		return EMalakorBossPhase::Phase2_PuristZealot;
	}
	return EMalakorBossPhase::Phase1_InquisitorSmash;
}

float UAshenMalakorEncounterComponent::EvaluateVoidSmashDamage(
	EMalakorBossPhase Phase,
	float BaseDamage) const
{
	switch (Phase)
	{
	case EMalakorBossPhase::Phase3_AbominationCascade:
		return BaseDamage * 2.20f;
	case EMalakorBossPhase::Phase2_PuristZealot:
		return BaseDamage * 1.50f;
	case EMalakorBossPhase::Phase1_InquisitorSmash:
	default:
		return BaseDamage;
	}
}
