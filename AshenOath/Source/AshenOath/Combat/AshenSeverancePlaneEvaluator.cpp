// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSeverancePlaneEvaluator.h"

UAshenSeverancePlaneEvaluator::UAshenSeverancePlaneEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	BalanceDataAsset = nullptr;
}

FSeveranceSlicePlaneData UAshenSeverancePlaneEvaluator::EvaluateSlicePlane(
	const FVector& HitLocation,
	const FVector& SwingTrajectory,
	ESeveranceBoneTarget BoneTarget) const
{
	FSeveranceSlicePlaneData Data;
	Data.PlanePosition = HitLocation;
	Data.ImpulseDirection = SwingTrajectory.GetSafeNormal();

	float DecapImpulse = 750.0f;
	float TorsoImpulse = 1100.0f;
	float LimbImpulse = 650.0f;
	float LegImpulse = 700.0f;

	if (BalanceDataAsset)
	{
		FSeveranceImpulseBalancing Impulses = BalanceDataAsset->GetClampedImpulses();
		DecapImpulse = Impulses.DecapitationImpulse;
		TorsoImpulse = Impulses.TorsoBisectionImpulse;
		LimbImpulse = Impulses.LimbAmputationImpulse;
		LegImpulse = Impulses.LegCrippleImpulse;
	}

	switch (BoneTarget)
	{
	case ESeveranceBoneTarget::Head:
		Data.PlaneNormal = FVector::UpVector;
		Data.ImpulseStrength = DecapImpulse;
		break;
	case ESeveranceBoneTarget::TorsoWaist:
		Data.PlaneNormal = FVector::UpVector;
		Data.ImpulseStrength = TorsoImpulse;
		break;
	case ESeveranceBoneTarget::RightArm:
	case ESeveranceBoneTarget::LeftArm:
		Data.PlaneNormal = FVector::CrossProduct(SwingTrajectory, FVector::UpVector).GetSafeNormal();
		Data.ImpulseStrength = LimbImpulse;
		break;
	case ESeveranceBoneTarget::RightLeg:
	case ESeveranceBoneTarget::LeftLeg:
		Data.PlaneNormal = FVector::CrossProduct(SwingTrajectory, FVector::ForwardVector).GetSafeNormal();
		Data.ImpulseStrength = LegImpulse;
		break;
	default:
		Data.PlaneNormal = FVector::UpVector;
		Data.ImpulseStrength = 500.0f;
		break;
	}

	return Data;
}
