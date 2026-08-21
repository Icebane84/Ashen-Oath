// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario4MissionSubsystem.h"

UAshenScenario4MissionSubsystem::UAshenScenario4MissionSubsystem()
{
	MistState.PurpleMistDensity = 0.50f;
	MistState.ChromaticAberrationIntensity = 1.0f;
	MistState.SootLayerOpacity = 0.60f; // Starts with initial soot on lens
	MistState.UnlockedCognitiveLoci = 0;
}

ECompanionGroundingState UAshenScenario4MissionSubsystem::PerformGroundingCheck(
	const FCompanionGroundingVerificationContext& Context)
{
	ECompanionGroundingState Result = ECompanionGroundingState::InvalidatedHallucination;

	if (Context.bCompanionHasLineOfSight && Context.bCompanionIsTargetingThreat)
	{
		Result = ECompanionGroundingState::VerifiedPhysicalThreat;
	}

	OnGroundingCheckExecuted.Broadcast(Context.PerceivedThreatId, Result);
	return Result;
}

void UAshenScenario4MissionSubsystem::WipeSoot(float WipeAmount)
{
	MistState.SootLayerOpacity = FMath::Clamp(MistState.SootLayerOpacity - WipeAmount, 0.0f, 1.0f);
	OnSootWiped.Broadcast(MistState.SootLayerOpacity);
}

void UAshenScenario4MissionSubsystem::DiscoverCognitiveLocus(const FName& LocusId)
{
	MistState.UnlockedCognitiveLoci++;
	OnCognitiveLocusDiscovered.Broadcast(LocusId, MistState.UnlockedCognitiveLoci);
}
