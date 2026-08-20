// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenPatternContinuityComponent.h"

UAshenPatternContinuityComponent::UAshenPatternContinuityComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenPatternContinuityComponent::CalculateSynarchyRatio(int32 SyncCount, int32 TotalEvents) const
{
	if (TotalEvents <= 0)
	{
		return 0.50f;
	}
	return FMath::Clamp(static_cast<float>(SyncCount) / static_cast<float>(TotalEvents), 0.0f, 1.0f);
}

FAshenRepairMatrix UAshenPatternContinuityComponent::EvaluateRepairHistory(
	const FGuid& CompanionId,
	const TArray<FMemoryImprintPayload>& MemoryGraph) const
{
	FAshenRepairMatrix Matrix;
	int32 SyncCount = 0;
	int32 TotalEvents = 0;
	int32 ConsecutiveBeats = 0;

	for (const FMemoryImprintPayload& Imprint : MemoryGraph)
	{
		if (Imprint.ImprintType == EMemoryImprintType::SyncFinisherExecuted ||
			Imprint.ImprintType == EMemoryImprintType::CompanionRescue)
		{
			SyncCount++;
			ConsecutiveBeats++;
			TotalEvents++;
		}
		else if (Imprint.ImprintType == EMemoryImprintType::CompanionConflict ||
				 Imprint.ImprintType == EMemoryImprintType::Retreat ||
				 Imprint.ImprintType == EMemoryImprintType::Betrayal)
		{
			ConsecutiveBeats = 0; // Reset streak on rupture
			TotalEvents++;
		}
	}

	Matrix.ConsecutiveCohesionBeats = ConsecutiveBeats;
	Matrix.SynarchyRatio = CalculateSynarchyRatio(SyncCount, TotalEvents);

	// Repair velocity scales with synarchy ratio and consecutive cohesion beats (clamped to 10 beats)
	const float CohesionFactor = FMath::Clamp(static_cast<float>(ConsecutiveBeats) / 10.0f, 0.0f, 1.0f);
	Matrix.ActiveRepairVelocity = FMath::Clamp(Matrix.SynarchyRatio * CohesionFactor, 0.0f, 1.0f);

	if (Matrix.ActiveRepairVelocity >= 0.70f)
	{
		Matrix.CurrentRuptureState = ERelationalRuptureState::RememberedReconciliation;
	}
	else if (Matrix.ActiveRepairVelocity >= 0.40f)
	{
		Matrix.CurrentRuptureState = ERelationalRuptureState::Harmonious;
	}
	else if (ConsecutiveBeats == 0 && TotalEvents > 0)
	{
		Matrix.CurrentRuptureState = ERelationalRuptureState::ActiveRupture;
	}
	else
	{
		Matrix.CurrentRuptureState = ERelationalRuptureState::FrictionGuarded;
	}

	return Matrix;
}

bool UAshenPatternContinuityComponent::ShouldExecuteCostlyPresence(
	float CompanionTrust,
	float CurrentThreat,
	const FAshenRepairMatrix& RepairHistory) const
{
	const float ClampedThreat = FMath::Clamp(CurrentThreat, 0.0f, 1.0f);
	const float RawThreshold = (ClampedThreat * 0.50f) - (RepairHistory.ActiveRepairVelocity * 0.40f);
	const float FaithThreshold = FMath::Clamp(RawThreshold, 0.15f, 0.85f);

	return (CompanionTrust >= FaithThreshold);
}
