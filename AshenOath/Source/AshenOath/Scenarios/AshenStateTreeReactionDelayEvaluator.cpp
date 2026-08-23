// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenStateTreeReactionDelayEvaluator.h"

UAshenStateTreeReactionDelayEvaluator::UAshenStateTreeReactionDelayEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenStateTreeReactionDelayEvaluator::EvaluateHesitationLatencyMS(EWaystationRunMode Mode) const
{
	switch (Mode)
	{
	case EWaystationRunMode::RunB_PureGrace:
		return 0.0f; // Instant solidarity
	case EWaystationRunMode::RunD_AvoidantMercy:
		return 150.0f; // Brief hesitation
	case EWaystationRunMode::RunA_ShadowHarvest:
		return 300.0f; // Distrustful hesitation
	case EWaystationRunMode::RunC_TheSpiral:
	default:
		return 600.0f; // Panic-locked hesitation
	}
}
