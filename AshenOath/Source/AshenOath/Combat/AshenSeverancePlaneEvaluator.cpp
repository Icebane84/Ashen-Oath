// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSeverancePlaneEvaluator.h"

UAshenSeverancePlaneEvaluator::UAshenSeverancePlaneEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FSeveranceSlicePlaneData UAshenSeverancePlaneEvaluator::EvaluateSlicePlane(
	const FVector& HitLocation,
	const FVector& SwingTrajectory,
	ESeveranceBoneTarget BoneTarget) const
{
	FSeveranceSlicePlaneData Data;
	Data.PlanePosition = HitLocation;
	Data.ImpulseDirection = SwingTrajectory.GetSafeNormal();

	switch (BoneTarget)
	{
	case ESeveranceBoneTarget::Head:
		Data.PlaneNormal = FVector::UpVector;
		Data.ImpulseStrength = 750.0f;
		break;
	case ESeveranceBoneTarget::TorsoWaist:
		Data.PlaneNormal = FVector::UpVector;
		Data.ImpulseStrength = 1100.0f;
		break;
	case ESeveranceBoneTarget::RightArm:
	case ESeveranceBoneTarget::LeftArm:
		Data.PlaneNormal = FVector::CrossProduct(SwingTrajectory, FVector::UpVector).GetSafeNormal();
		Data.ImpulseStrength = 650.0f;
		break;
	case ESeveranceBoneTarget::RightLeg:
	case ESeveranceBoneTarget::LeftLeg:
		Data.PlaneNormal = FVector::CrossProduct(SwingTrajectory, FVector::ForwardVector).GetSafeNormal();
		Data.ImpulseStrength = 700.0f;
		break;
	default:
		Data.PlaneNormal = FVector::UpVector;
		Data.ImpulseStrength = 500.0f;
		break;
	}

	return Data;
}
