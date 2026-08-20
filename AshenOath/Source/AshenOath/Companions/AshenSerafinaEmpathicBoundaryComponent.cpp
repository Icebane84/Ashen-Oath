// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenSerafinaEmpathicBoundaryComponent.h"

UAshenSerafinaEmpathicBoundaryComponent::UAshenSerafinaEmpathicBoundaryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxSafeAbsorptionToll = 0.60f;
	SootDecayRatePerSecond = 0.05f;
	CurrentAccumulatedSoot = 0.0f;
}

bool UAshenSerafinaEmpathicBoundaryComponent::ShouldCastCrisisSanctuary(
	float TrustSerafina,
	float KaelenInternalFriction,
	float ActiveRepairVelocity) const
{
	// Extreme crisis condition: Kaelen internal friction >= 0.70
	if (KaelenInternalFriction >= 0.70f)
	{
		// Serafina casts if trust >= 0.40 and repair velocity >= 0.25
		return (TrustSerafina >= 0.40f) && (ActiveRepairVelocity >= 0.25f);
	}
	return (TrustSerafina >= 0.60f);
}

float UAshenSerafinaEmpathicBoundaryComponent::CalculateTransferenceCapacity(
	float BurnoutSerafina,
	float TrustSerafina) const
{
	const float BaseCapacity = 1.0f - FMath::Clamp(BurnoutSerafina, 0.0f, 1.0f);
	return FMath::Clamp(BaseCapacity * FMath::Clamp(TrustSerafina, 0.20f, 1.0f), 0.0f, 1.0f);
}

float UAshenSerafinaEmpathicBoundaryComponent::ApplyTransferenceToll(float AbsorbedDysregulation)
{
	const float AddedSoot = FMath::Clamp(AbsorbedDysregulation * 0.75f, 0.0f, 1.0f);
	CurrentAccumulatedSoot = FMath::Clamp(CurrentAccumulatedSoot + AddedSoot, 0.0f, 1.0f);
	return CurrentAccumulatedSoot;
}
