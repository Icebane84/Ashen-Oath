// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario5MissionSubsystem.h"

UAshenScenario5MissionSubsystem::UAshenScenario5MissionSubsystem()
{
	CurrentPhase = EUnchainedVesselPhase::Dormant;
	Telemetry.DamageMultiplier = 1.0f;
	Telemetry.HeartRateBPM = 80.0f;
	Telemetry.FrenzyRemainingSeconds = 0.0f;
	Telemetry.GasPocketsDetonated = 0;
}

void UAshenScenario5MissionSubsystem::SetUnchainedPhase(EUnchainedVesselPhase NewPhase)
{
	CurrentPhase = NewPhase;
	if (CurrentPhase == EUnchainedVesselPhase::UnchainedFrenzy)
	{
		Telemetry.DamageMultiplier = 1.50f;
		Telemetry.HeartRateBPM = 140.0f;
		Telemetry.FrenzyRemainingSeconds = 12.0f;
	}
	else if (CurrentPhase == EUnchainedVesselPhase::ExhaustedVulnerable)
	{
		Telemetry.DamageMultiplier = 0.70f;
		Telemetry.HeartRateBPM = 110.0f;
		Telemetry.FrenzyRemainingSeconds = 0.0f;
	}
	else
	{
		Telemetry.DamageMultiplier = 1.0f;
		Telemetry.HeartRateBPM = 80.0f;
		Telemetry.FrenzyRemainingSeconds = 0.0f;
	}

	OnUnchainedPhaseChanged.Broadcast(CurrentPhase);
}

void UAshenScenario5MissionSubsystem::IgniteGasPocket(const FName& PocketId, float Radius)
{
	Telemetry.GasPocketsDetonated++;
	OnGasPocketIgnited.Broadcast(PocketId, Radius);
}

void UAshenScenario5MissionSubsystem::TriggerBoundaryDefense(ECompanionBoundaryDefenseState State, float Radius)
{
	OnBoundaryDefenseTriggered.Broadcast(State, Radius);
}
