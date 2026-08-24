// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenPhaseShiftDitherEvaluator.h"

UAshenPhaseShiftDitherEvaluator::UAshenPhaseShiftDitherEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenPhaseShiftDitherEvaluator::EvaluateDitherOpacity(EShroudKnightPhaseState PhaseState) const
{
	switch (PhaseState)
	{
	case EShroudKnightPhaseState::SpectralPhasing:
		return 0.15f; // Translucent outline
	case EShroudKnightPhaseState::ThreadAnchored:
	case EShroudKnightPhaseState::TrinityVulnerable:
	case EShroudKnightPhaseState::PhysicalSolid:
	default:
		return 1.00f; // Solid plate
	}
}

bool UAshenPhaseShiftDitherEvaluator::IsCollisionEnabled(EShroudKnightPhaseState PhaseState) const
{
	return PhaseState != EShroudKnightPhaseState::SpectralPhasing;
}

float UAshenPhaseShiftDitherEvaluator::EvaluateMistParticleDensity(EShroudKnightPhaseState PhaseState) const
{
	return (PhaseState == EShroudKnightPhaseState::SpectralPhasing) ? 100.0f : 10.0f;
}
