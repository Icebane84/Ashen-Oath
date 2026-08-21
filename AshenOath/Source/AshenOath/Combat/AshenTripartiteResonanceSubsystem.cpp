// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenTripartiteResonanceSubsystem.h"
#include "Combat/AshenComboChainEvaluatorComponent.h"
#include "Combat/AshenDualSenseHapticResonanceComponent.h"
#include "Combat/AshenHarmonizedFinisherOrchestratorComponent.h"

UAshenTripartiteResonanceSubsystem::UAshenTripartiteResonanceSubsystem()
{
}

void UAshenTripartiteResonanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	EvaluatorComponent = NewObject<UAshenComboChainEvaluatorComponent>(this);
	HapticComponent = NewObject<UAshenDualSenseHapticResonanceComponent>(this);
	OrchestratorComponent = NewObject<UAshenHarmonizedFinisherOrchestratorComponent>(this);
}

void UAshenTripartiteResonanceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

FTripartiteComboState UAshenTripartiteResonanceSubsystem::InitiateComboStep1(
	AActor* TargetActor,
	float WindowDurationSeconds)
{
	FTripartiteComboState State;

	if (EvaluatorComponent)
	{
		State = EvaluatorComponent->StartCombo(WindowDurationSeconds);
		OnTripartiteComboPhaseChanged.Broadcast(State);
	}

	return State;
}

FTripartiteComboState UAshenTripartiteResonanceSubsystem::AdvanceComboStep2(bool bGarrettNear)
{
	FTripartiteComboState State;

	if (EvaluatorComponent)
	{
		State = EvaluatorComponent->ProgressToStep2(bGarrettNear);
		OnTripartiteComboPhaseChanged.Broadcast(State);
	}

	return State;
}

FTripartiteComboState UAshenTripartiteResonanceSubsystem::AdvanceComboStep3(bool bSerafinaNear)
{
	FTripartiteComboState State;

	if (EvaluatorComponent)
	{
		State = EvaluatorComponent->ProgressToStep3(bSerafinaNear);
		OnTripartiteComboPhaseChanged.Broadcast(State);
	}

	return State;
}

bool UAshenTripartiteResonanceSubsystem::ExecuteHarmonizedFinisher(AActor* TargetActor, float BaseDamage)
{
	if (!OrchestratorComponent || !EvaluatorComponent)
	{
		return false;
	}

	const FTripartiteComboState CurrentState = EvaluatorComponent->GetCurrentState();
	if (CurrentState.CurrentPhase != ETripartiteComboPhase::FinisherReady)
	{
		return false;
	}

	const float TotalDamage = OrchestratorComponent->CalculateFinisherDamage(BaseDamage, CurrentState.FinisherTier);
	OnHarmonizedFinisherExecuted.Broadcast(CurrentState.FinisherTier, TotalDamage);

	const float TrustGained = 0.15f;
	const float DysregulationPurged = 0.30f;
	OnFellowshipCatharsisTriggered.Broadcast(TrustGained, DysregulationPurged);

	EvaluatorComponent->ResetCombo();
	return true;
}
