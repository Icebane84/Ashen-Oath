// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenGarrettTacticalPredictabilityComponent.h"

UAshenGarrettTacticalPredictabilityComponent::UAshenGarrettTacticalPredictabilityComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	MinTightSpacingUU = 250.0f;
	MaxGuardedSpacingUU = 800.0f;
	SpacingInterpSpeed = 3.5f;
	CurrentSpacingUU = 400.0f;
	TargetSpacingUU = 400.0f;
}

void UAshenGarrettTacticalPredictabilityComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentSpacingUU = FMath::FInterpTo(CurrentSpacingUU, TargetSpacingUU, DeltaTime, SpacingInterpSpeed);
}

float UAshenGarrettTacticalPredictabilityComponent::CalculateTargetSpacing(
	float InternalFriction,
	float TrustGarrett,
	float FatigueGarrett) const
{
	// Alienation scalar combines high friction, low trust, and fatigue
	const float AlienationFactor = FMath::Clamp(
		(InternalFriction * 0.50f) + ((1.0f - TrustGarrett) * 0.35f) + (FatigueGarrett * 0.15f),
		0.0f, 1.0f);

	return FMath::Lerp(MinTightSpacingUU, MaxGuardedSpacingUU, AlienationFactor);
}

bool UAshenGarrettTacticalPredictabilityComponent::CanExecuteRiskyFlank(
	float TrustGarrett,
	float ActiveRepairVelocity) const
{
	// Garrett accepts high-risk flank attacks if trust is >= 0.50 and repair velocity is >= 0.30
	return (TrustGarrett >= 0.50f) && (ActiveRepairVelocity >= 0.30f);
}
