// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenDestructionCoverDurabilityEvaluator.h"

UAshenDestructionCoverDurabilityEvaluator::UAshenDestructionCoverDurabilityEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenDestructionCoverDurabilityEvaluator::EvaluateRemainingCoverHP(
	float CurrentHP,
	float IncomingDamage) const
{
	return FMath::Max(0.0f, CurrentHP - IncomingDamage);
}

float UAshenDestructionCoverDurabilityEvaluator::EvaluateShrapnelDamage(
	float MaxCoverHP) const
{
	return 250.0f; // Fixed lethal shrapnel detonation
}
