// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenSymbioticFlowPostProcessAdapter.h"

UAshenSymbioticFlowPostProcessAdapter::UAshenSymbioticFlowPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenSymbioticFlowPostProcessAdapter::EvaluateGoldenBloomIntensity(ECombatFlowState FlowState) const
{
	return (FlowState == ECombatFlowState::SymbioticResonance) ? 1.50f : 0.20f;
}

float UAshenSymbioticFlowPostProcessAdapter::EvaluateChromaticDamping(ECombatFlowState FlowState) const
{
	return (FlowState == ECombatFlowState::SymbioticResonance) ? 0.0f : 1.0f; // Fully cleanses aberration
}
