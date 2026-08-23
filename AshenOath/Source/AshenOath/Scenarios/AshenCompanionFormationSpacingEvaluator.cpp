// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenCompanionFormationSpacingEvaluator.h"

UAshenCompanionFormationSpacingEvaluator::UAshenCompanionFormationSpacingEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenCompanionFormationSpacingEvaluator::EvaluateSerafinaFormationDistance(EWaystationRunMode Mode) const
{
	switch (Mode)
	{
	case EWaystationRunMode::RunB_PureGrace:
		return 300.0f; // Tight wedge
	case EWaystationRunMode::RunD_AvoidantMercy:
		return 750.0f; // Guarded hesitation
	case EWaystationRunMode::RunA_ShadowHarvest:
		return 1000.0f; // Alienated distance
	case EWaystationRunMode::RunC_TheSpiral:
	default:
		return 1200.0f; // Terrified perimeter
	}
}

float UAshenCompanionFormationSpacingEvaluator::EvaluateGarrettFormationDistance(EWaystationRunMode Mode) const
{
	switch (Mode)
	{
	case EWaystationRunMode::RunB_PureGrace:
		return 350.0f; // Close flank
	case EWaystationRunMode::RunA_ShadowHarvest:
		return 500.0f; // Pragmatic flank
	case EWaystationRunMode::RunD_AvoidantMercy:
		return 600.0f; // Guarded flank
	case EWaystationRunMode::RunC_TheSpiral:
	default:
		return 800.0f; // Defensive stance abort
	}
}
