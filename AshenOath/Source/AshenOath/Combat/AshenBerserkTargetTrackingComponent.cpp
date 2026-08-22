// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenBerserkTargetTrackingComponent.h"

UAshenBerserkTargetTrackingComponent::UAshenBerserkTargetTrackingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TrackingMode = EAshenTargetTrackingMode::ManualFreeLook;
	TrackingRadiusCentimeters = 1200.0f;
}

FRotator UAshenBerserkTargetTrackingComponent::EvaluateTargetTrackingRotation(
	const FVector& CurrentLocation,
	const FRotator& CurrentRotation,
	const FVector& TargetLocation,
	float InterpSpeed,
	float DeltaSeconds) const
{
	if (TrackingMode == EAshenTargetTrackingMode::ManualFreeLook)
	{
		return CurrentRotation;
	}

	const FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
	const FRotator TargetRot = Direction.Rotation();
	return FMath::RInterpTo(CurrentRotation, TargetRot, DeltaSeconds, InterpSpeed);
}

void UAshenBerserkTargetTrackingComponent::SetTrackingMode(EAshenTargetTrackingMode NewMode)
{
	TrackingMode = NewMode;
}
