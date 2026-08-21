// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenCompanionGroundingEvaluatorComponent.h"

UAshenCompanionGroundingEvaluatorComponent::UAshenCompanionGroundingEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenCompanionGroundingEvaluatorComponent::EvaluateCompanionGazeAlignment(
	const FVector& CompanionLocation,
	const FVector& CompanionForwardVector,
	const FVector& ThreatLocation,
	float MaxConeAngleDegrees) const
{
	const FVector DirToThreat = (ThreatLocation - CompanionLocation).GetSafeNormal();
	const float Dot = FVector::DotProduct(CompanionForwardVector.GetSafeNormal(), DirToThreat);
	const float AngleDegrees = FMath::RadiansToDegrees(FMath::Acos(FMath::Clamp(Dot, -1.0f, 1.0f)));

	return AngleDegrees <= MaxConeAngleDegrees;
}
