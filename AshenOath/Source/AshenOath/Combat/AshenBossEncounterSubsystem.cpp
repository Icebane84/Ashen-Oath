// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenBossEncounterSubsystem.h"
#include "Combat/AshenBossPhaseEvaluatorComponent.h"
#include "Combat/AshenArenaDestructionCoordinatorComponent.h"
#include "Combat/AshenCompanionCrisisResolverComponent.h"

UAshenBossEncounterSubsystem::UAshenBossEncounterSubsystem()
{
}

void UAshenBossEncounterSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	PhaseEvaluator = NewObject<UAshenBossPhaseEvaluatorComponent>(this);
	DestructionCoordinator = NewObject<UAshenArenaDestructionCoordinatorComponent>(this);
	CrisisResolver = NewObject<UAshenCompanionCrisisResolverComponent>(this);
}

void UAshenBossEncounterSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

EBossEncounterPhase UAshenBossEncounterSubsystem::UpdateBossHealth(float HealthPercent)
{
	EBossEncounterPhase Phase = EBossEncounterPhase::Phase1_Guardian;

	if (PhaseEvaluator)
	{
		const bool bPhaseShifted = PhaseEvaluator->EvaluateHealth(HealthPercent, Phase);
		if (bPhaseShifted)
		{
			OnBossPhaseShifted.Broadcast(Phase);
		}
	}

	return Phase;
}

bool UAshenBossEncounterSubsystem::SunderArenaPillar(int32 PillarIndex)
{
	if (!DestructionCoordinator)
	{
		return false;
	}

	const float Obstruction = DestructionCoordinator->SunderPillar(PillarIndex);
	OnArenaPillarSundered.Broadcast(PillarIndex, Obstruction);
	return true;
}

FCompanionCrisisContext UAshenBossEncounterSubsystem::TriggerCompanionCrisis(
	FName CompanionName,
	float WindowDurationSeconds)
{
	FCompanionCrisisContext Context;

	if (CrisisResolver)
	{
		Context = CrisisResolver->OpenCrisisWindow(CompanionName, WindowDurationSeconds);
		OnCompanionCrisisTriggered.Broadcast(Context);
	}

	return Context;
}

bool UAshenBossEncounterSubsystem::ResolveCompanionCrisis(bool bIntervenedViaTransference)
{
	if (!CrisisResolver)
	{
		return false;
	}

	ECompanionCrisisState Outcome = ECompanionCrisisState::None;
	float TrustDelta = 0.0f;
	const bool bResolved = CrisisResolver->ResolveCrisis(bIntervenedViaTransference, Outcome, TrustDelta);

	if (bResolved)
	{
		OnCompanionCrisisResolved.Broadcast(Outcome, TrustDelta);
	}

	return bResolved;
}
