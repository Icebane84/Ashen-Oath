// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario1MissionSubsystem.h"

UAshenScenario1MissionSubsystem::UAshenScenario1MissionSubsystem()
{
}

void UAshenScenario1MissionSubsystem::UpdateEncounterState(const FMalakorEncounterState& NewState)
{
	const bool bPhaseChanged = (EncounterState.CurrentPhase != NewState.CurrentPhase);
	EncounterState = NewState;

	if (bPhaseChanged)
	{
		OnMalakorPhaseShifted.Broadcast(EncounterState.CurrentPhase, EncounterState.BossHealthPercent);
	}
}

void UAshenScenario1MissionSubsystem::ProcessRitualDisruption(float CurrentProgress, float DebtSpike)
{
	EncounterState.RitualInterruptionCount += 1.0f;
	OnRitualInterrupted.Broadcast(CurrentProgress, DebtSpike);
}
