// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenStanceDamageEvaluatorComponent.h"

UAshenStanceDamageEvaluatorComponent::UAshenStanceDamageEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenStanceDamageEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

FStanceModifiers UAshenStanceDamageEvaluatorComponent::GetModifiersForStance(ECombatStance Stance) const
{
	FStanceModifiers Modifiers;

	switch (Stance)
	{
	case ECombatStance::Aegis:
		Modifiers.DamageMultiplier = 0.85f;
		Modifiers.AttackSpeedMultiplier = 0.80f;
		Modifiers.PoiseBonus = 50.0f; // +50 Poise
		Modifiers.DamageTakenMultiplier = 0.70f; // -30% Damage Taken
		break;
	case ECombatStance::Berserk:
		Modifiers.DamageMultiplier = 1.30f; // +30% Outgoing Damage
		Modifiers.AttackSpeedMultiplier = 1.35f; // +35% Attack Speed
		Modifiers.PoiseBonus = -15.0f;
		Modifiers.DamageTakenMultiplier = 1.20f; // +20% Damage Taken
		break;
	case ECombatStance::Flow:
	default:
		Modifiers.DamageMultiplier = 1.0f;
		Modifiers.AttackSpeedMultiplier = 1.0f;
		Modifiers.PoiseBonus = 0.0f;
		Modifiers.DamageTakenMultiplier = 1.0f;
		break;
	}

	return Modifiers;
}
