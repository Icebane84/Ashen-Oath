// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenUnchainedCombatEvaluatorComponent.h"

UAshenUnchainedCombatEvaluatorComponent::UAshenUnchainedCombatEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenUnchainedCombatEvaluatorComponent::EvaluateDamageMultiplier(EUnchainedVesselPhase Phase) const
{
	switch (Phase)
	{
	case EUnchainedVesselPhase::UnchainedFrenzy:
		return 1.50f; // +50% damage
	case EUnchainedVesselPhase::ExhaustedVulnerable:
		return 0.70f; // -30% damage while exhausted
	case EUnchainedVesselPhase::Dormant:
	default:
		return 1.0f;
	}
}

float UAshenUnchainedCombatEvaluatorComponent::EvaluateLungeVelocityMultiplier(EUnchainedVesselPhase Phase) const
{
	switch (Phase)
	{
	case EUnchainedVesselPhase::UnchainedFrenzy:
		return 1.80f; // +80% lunge leap velocity
	case EUnchainedVesselPhase::ExhaustedVulnerable:
		return 0.50f;
	case EUnchainedVesselPhase::Dormant:
	default:
		return 1.0f;
	}
}
