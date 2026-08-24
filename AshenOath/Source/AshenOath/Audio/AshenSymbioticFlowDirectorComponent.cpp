// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenSymbioticFlowDirectorComponent.h"

UAshenSymbioticFlowDirectorComponent::UAshenSymbioticFlowDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenSymbioticFlowDirectorComponent::EvaluateStaminaRegenMultiplier(ECombatFlowState FlowState) const
{
	return (FlowState == ECombatFlowState::SymbioticResonance) ? 2.0f : 1.0f;
}

float UAshenSymbioticFlowDirectorComponent::EvaluateFlowDamageBonus(ECombatFlowState FlowState) const
{
	return (FlowState == ECombatFlowState::SymbioticResonance) ? 0.30f : 0.0f;
}
