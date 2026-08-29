// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCSESubsystem.h"

UAshenCSESubsystem::UAshenCSESubsystem()
{
	CurrentDissonanceIndex = 0.15f;
	CurrentDissonanceTier = ECognitiveDissonanceTier::HarmonicConsensus;
}

void UAshenCSESubsystem::UpdateCognitivePerspectives(
	const FCognitiveStateVector& KaelenVector,
	const FCognitiveStateVector& GarrettVector,
	const FCognitiveStateVector& SerafinaVector,
	const FCognitiveStateVector& ObjectiveVector)
{
	CachedKaelen = KaelenVector;
	CachedGarrett = GarrettVector;
	CachedSerafina = SerafinaVector;
	CachedObjective = ObjectiveVector;

	// Calculate Euclidean distance deltas from Objective Truth
	auto CalcDelta = [](const FCognitiveStateVector& A, const FCognitiveStateVector& B) -> float
	{
		const float dP = A.Pragmatism - B.Pragmatism;
		const float dD = A.Dogma - B.Dogma;
		const float dT = A.HistoricalTruth - B.HistoricalTruth;
		return FMath::Sqrt((dP * dP) + (dD * dD) + (dT * dT)) / FMath::Sqrt(3.0f);
	};

	const float DeltaK = CalcDelta(KaelenVector, ObjectiveVector);
	const float DeltaG = CalcDelta(GarrettVector, ObjectiveVector);
	const float DeltaS = CalcDelta(SerafinaVector, ObjectiveVector);

	CurrentDissonanceIndex = FMath::Clamp((DeltaK + DeltaG + DeltaS) / 3.0f, 0.0f, 1.0f);

	// Resolve Tier
	if (CurrentDissonanceIndex > 0.75f)
	{
		CurrentDissonanceTier = ECognitiveDissonanceTier::PsychologicalFracture;
	}
	else if (CurrentDissonanceIndex > 0.50f)
	{
		CurrentDissonanceTier = ECognitiveDissonanceTier::IdeologicalDivergence;
	}
	else if (CurrentDissonanceIndex >= 0.25f)
	{
		CurrentDissonanceTier = ECognitiveDissonanceTier::PhilosophicalFriction;
	}
	else
	{
		CurrentDissonanceTier = ECognitiveDissonanceTier::HarmonicConsensus;
	}

	OnCognitiveDissonanceShifted.Broadcast(CurrentDissonanceIndex, CurrentDissonanceTier);
	OnCompanionAlignmentUpdated.Broadcast(GarrettVector.Pragmatism, SerafinaVector.Dogma);
}
