// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenBossPhaseEvaluatorComponent.h"

UAshenBossPhaseEvaluatorComponent::UAshenBossPhaseEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentPhase = EBossEncounterPhase::Phase1_Guardian;
}

bool UAshenBossPhaseEvaluatorComponent::EvaluateHealth(
	float HealthPercent,
	EBossEncounterPhase& OutCurrentPhase)
{
	EBossEncounterPhase NewPhase = CurrentPhase;

	if (HealthPercent <= 0.0f)
	{
		NewPhase = EBossEncounterPhase::Defeated;
	}
	else if (HealthPercent <= 0.30f)
	{
		NewPhase = EBossEncounterPhase::Phase3_UmbralMeltdown;
	}
	else if (HealthPercent <= 0.65f)
	{
		NewPhase = EBossEncounterPhase::Phase2_NightsteelTitan;
	}
	else
	{
		NewPhase = EBossEncounterPhase::Phase1_Guardian;
	}

	const bool bPhaseChanged = (NewPhase != CurrentPhase);
	CurrentPhase = NewPhase;
	OutCurrentPhase = CurrentPhase;
	return bPhaseChanged;
}
