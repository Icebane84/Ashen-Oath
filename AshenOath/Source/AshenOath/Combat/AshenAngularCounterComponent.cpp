// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenAngularCounterComponent.h"
#include "GameFramework/Actor.h"

UAshenAngularCounterComponent::UAshenAngularCounterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

EAshenCounterAttackZone UAshenAngularCounterComponent::CalculateCounterTrajectory(
	const FVector& AttackerLocation,
	const FVector& AttackDirection,
	float& OutTargetBlendAngleDegrees) const
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor)
	{
		OutTargetBlendAngleDegrees = 0.0f;
		return EAshenCounterAttackZone::VerticalOverhead;
	}

	const FVector ForwardVector = OwnerActor->GetActorForwardVector();
	const FVector RightVector = OwnerActor->GetActorRightVector();
	const FVector InvertedAttack = -AttackDirection.GetSafeNormal();

	const float ForwardDot = FVector::DotProduct(ForwardVector, InvertedAttack);
	const float RightDot = FVector::DotProduct(RightVector, InvertedAttack);

	float AngleRadians = FMath::Atan2(RightDot, ForwardDot);
	float AngleDegrees = FMath::RadiansToDegrees(AngleRadians);

	if (AngleDegrees < 0.0f)
	{
		AngleDegrees += 360.0f;
	}

	OutTargetBlendAngleDegrees = AngleDegrees;

	// 4-Zone Mapping:
	// Overhead: 315° to 45°
	// Right Cleave: 45° to 135°
	// Underhand Lift: 135° to 225°
	// Left Cleave: 225° to 315°
	if (AngleDegrees >= 45.0f && AngleDegrees < 135.0f)
	{
		return EAshenCounterAttackZone::HorizontalRight;
	}
	else if (AngleDegrees >= 135.0f && AngleDegrees < 225.0f)
	{
		return EAshenCounterAttackZone::DiagonalUnderhand;
	}
	else if (AngleDegrees >= 225.0f && AngleDegrees < 315.0f)
	{
		return EAshenCounterAttackZone::HorizontalLeft;
	}

	return EAshenCounterAttackZone::VerticalOverhead;
}
