// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenMassKineticCleaveComponent.h"

UAshenMassKineticCleaveComponent::UAshenMassKineticCleaveComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FKineticSwingSnapshot UAshenMassKineticCleaveComponent::CalculateKineticPayload(
	EKineticCleaveStance Stance,
	float BladeTipVelocityMetersPerSec) const
{
	FKineticSwingSnapshot Snapshot;
	Snapshot.SwingId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	Snapshot.Stance = Stance;
	Snapshot.BladeTipVelocity = BladeTipVelocityMetersPerSec * 100.0f; // cm/s

	const float MassKG = (Stance == EKineticCleaveStance::DarkShadowUnleashed) ? 180.0f : 45.0f;
	Snapshot.WeaponMassKG = MassKG;

	// Ek = 0.5 * m * v^2
	float BaseEnergy = 0.5f * MassKG * (BladeTipVelocityMetersPerSec * BladeTipVelocityMetersPerSec);
	if (Stance == EKineticCleaveStance::DarkShadowUnleashed)
	{
		BaseEnergy *= 2.5f; // Umbral kinetic multiplier
	}
	Snapshot.KineticEnergyJoules = BaseEnergy;

	if (BaseEnergy >= 4500.0f)
	{
		Snapshot.FractureTier = EStructuralFractureTier::CatastrophicCleave;
	}
	else if (BaseEnergy >= 1500.0f)
	{
		Snapshot.FractureTier = EStructuralFractureTier::StructuralCrack;
	}
	else
	{
		Snapshot.FractureTier = EStructuralFractureTier::SurfaceChipping;
	}

	return Snapshot;
}
