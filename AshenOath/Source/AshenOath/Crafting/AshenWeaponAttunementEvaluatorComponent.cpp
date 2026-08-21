// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Crafting/AshenWeaponAttunementEvaluatorComponent.h"

UAshenWeaponAttunementEvaluatorComponent::UAshenWeaponAttunementEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenWeaponAttunementEvaluatorComponent::EvaluateKineticEnergy(
	const FSoulForgeWeaponState& State,
	float SwingVelocity) const
{
	// E_k = 0.5 * m * v^2
	const float NormalizedVelocity = SwingVelocity / 100.0f;
	const float BaseJoules = 0.5f * State.EffectiveMassKg * (NormalizedVelocity * NormalizedVelocity);
	return BaseJoules * State.TotalPoiseMultiplier;
}

float UAshenWeaponAttunementEvaluatorComponent::EvaluateStaminaCostScalar(const FSoulForgeWeaponState& State) const
{
	// Normalized around 120kg standard Nightsteel greatsword
	const float MassRatio = State.EffectiveMassKg / 120.0f;
	return FMath::Clamp(MassRatio, 0.6f, 2.0f);
}
