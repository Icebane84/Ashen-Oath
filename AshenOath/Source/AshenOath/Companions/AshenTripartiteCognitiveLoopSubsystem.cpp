// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenTripartiteCognitiveLoopSubsystem.h"

UAshenTripartiteCognitiveLoopSubsystem::UAshenTripartiteCognitiveLoopSubsystem()
{
	CurrentVector.ActiveMode = ETripartiteBehaviorMode::CombatEngagement;
	CurrentVector.AttunementPhase = ECompanionAttunementPhase::GuardedAlignment;
	CurrentVector.TripartiteAttunementScore = 0.50f;
	CurrentVector.GarrettFlankAngleDegrees = 90.0f;
	CurrentVector.SerafinaSupportDistanceUU = 450.0f;
	CurrentVector.bSilenceContractMaintained = true;
}

void UAshenTripartiteCognitiveLoopSubsystem::TransitionMode(ETripartiteBehaviorMode NewMode)
{
	CurrentVector.ActiveMode = NewMode;

	switch (NewMode)
	{
	case ETripartiteBehaviorMode::CombatEngagement:
		CurrentVector.GarrettFlankAngleDegrees = 90.0f;
		CurrentVector.SerafinaSupportDistanceUU = (CurrentVector.TripartiteAttunementScore >= 0.70f) ? 300.0f : 550.0f;
		break;
	case ETripartiteBehaviorMode::ContemplativeSilence:
		CurrentVector.GarrettFlankAngleDegrees = 45.0f;
		CurrentVector.SerafinaSupportDistanceUU = 350.0f;
		CurrentVector.bSilenceContractMaintained = true;
		break;
	case ETripartiteBehaviorMode::TraumaAftermath:
		CurrentVector.GarrettFlankAngleDegrees = 135.0f;
		CurrentVector.SerafinaSupportDistanceUU = 850.0f;
		CurrentVector.bSilenceContractMaintained = true;
		break;
	case ETripartiteBehaviorMode::CampfireRestoration:
		CurrentVector.GarrettFlankAngleDegrees = 60.0f;
		CurrentVector.SerafinaSupportDistanceUU = 250.0f;
		break;
	}

	OnTripartiteModeChanged.Broadcast(NewMode, CurrentVector.AttunementPhase);
	OnEQSSpatialCoordinatesShifted.Broadcast(CurrentVector.GarrettFlankAngleDegrees, CurrentVector.SerafinaSupportDistanceUU);
}

void UAshenTripartiteCognitiveLoopSubsystem::RecordSynchronizedAction(float AttunementDelta)
{
	CurrentVector.TripartiteAttunementScore = FMath::Clamp(CurrentVector.TripartiteAttunementScore + AttunementDelta, 0.0f, 1.0f);

	ECompanionAttunementPhase NewPhase = ECompanionAttunementPhase::GuardedAlignment;
	if (CurrentVector.TripartiteAttunementScore >= 0.70f)
	{
		NewPhase = ECompanionAttunementPhase::UnifiedResonance;
	}
	else if (CurrentVector.TripartiteAttunementScore < 0.30f)
	{
		NewPhase = ECompanionAttunementPhase::FracturedDivergence;
	}

	CurrentVector.AttunementPhase = NewPhase;

	const float Multiplier = 1.0f + (CurrentVector.TripartiteAttunementScore * 2.0f); // 1.0x to 3.0x
	OnAttunementScoreUpdated.Broadcast(CurrentVector.TripartiteAttunementScore, Multiplier);

	const bool bFinisherReady = (CurrentVector.TripartiteAttunementScore >= 0.70f);
	OnTripartiteFinisherReady.Broadcast(bFinisherReady);
}
