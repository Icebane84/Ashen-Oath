// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenRubbleMassImpulseEvaluator.h"

UAshenRubbleMassImpulseEvaluator::UAshenRubbleMassImpulseEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenRubbleMassImpulseEvaluator::EvaluateNavmeshCostModifier(
	ERubbleFractureTier FractureTier,
	float TotalMassKg) const
{
	switch (FractureTier)
	{
	case ERubbleFractureTier::MonolithicArch:
	case ERubbleFractureTier::HeavyBoulder:
		return 4.50f; // Impassable choke
	case ERubbleFractureTier::MediumMasonry:
		return FMath::Clamp(1.5f + (TotalMassKg / 150.0f) * 1.5f, 1.5f, 3.0f);
	case ERubbleFractureTier::FineGravel:
	default:
		return 1.00f; // Baseline traversal
	}
}

float UAshenRubbleMassImpulseEvaluator::EvaluateKineticImpulseForce(
	float MassKg,
	float ImpactVelocityMps) const
{
	const float SafeMass = FMath::Clamp(MassKg, 1.0f, 1000.0f);
	const float SafeVel = FMath::Clamp(ImpactVelocityMps, 0.0f, 50.0f);
	return SafeMass * SafeVel;
}

bool UAshenRubbleMassImpulseEvaluator::IsChokePointImpassable(float TotalMassKg) const
{
	return TotalMassKg >= 200.0f;
}
