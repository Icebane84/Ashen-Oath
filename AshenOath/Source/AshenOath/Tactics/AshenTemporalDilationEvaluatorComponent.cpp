// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Tactics/AshenTemporalDilationEvaluatorComponent.h"

UAshenTemporalDilationEvaluatorComponent::UAshenTemporalDilationEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenTemporalDilationEvaluatorComponent::EvaluateTargetDilation(ETemporalDilationState State) const
{
	switch (State)
	{
	case ETemporalDilationState::TacticalSlowMo:
		return 0.20f;
	case ETemporalDilationState::ComboFreezeFrame:
		return 0.05f;
	case ETemporalDilationState::Realtime:
	default:
		return 1.00f;
	}
}
