// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSeveranceDismembermentConvergenceSubsystem.h"

UAshenSeveranceDismembermentConvergenceSubsystem::UAshenSeveranceDismembermentConvergenceSubsystem()
{
	AdrenalineState.CurrentAdrenaline = 0.0f;
	AdrenalineState.MaxAdrenaline = 100.0f;
	AdrenalineState.bHyperArmorActive = false;
	AdrenalineState.DurationRemainingSeconds = 0.0f;
	MaxActiveGibs = 16;
}

FSeveranceDismembermentResult UAshenSeveranceDismembermentConvergenceSubsystem::ExecuteSeverance(
	AActor* TargetActor,
	ESeveranceBoneTarget BoneTarget,
	const FSeveranceSlicePlaneData& SlicePlane)
{
	FSeveranceDismembermentResult Result;
	Result.bSeveranceExecuted = false;
	Result.SeveredBone = BoneTarget;

	if (!TargetActor || BoneTarget == ESeveranceBoneTarget::None)
	{
		return Result;
	}

	Result.bSeveranceExecuted = true;

	switch (BoneTarget)
	{
	case ESeveranceBoneTarget::Head:
		Result.SeverityTier = ESeveranceSeverityTier::Decapitation;
		Result.BloodSplatterVolume = 1.50f;
		Result.AdrenalineGranted = 35.0f;
		break;
	case ESeveranceBoneTarget::TorsoWaist:
		Result.SeverityTier = ESeveranceSeverityTier::TotalBisection;
		Result.BloodSplatterVolume = 2.00f;
		Result.AdrenalineGranted = 40.0f;
		break;
	case ESeveranceBoneTarget::RightArm:
	case ESeveranceBoneTarget::LeftArm:
		Result.SeverityTier = ESeveranceSeverityTier::MajorLimb;
		Result.BloodSplatterVolume = 1.00f;
		Result.AdrenalineGranted = 25.0f;
		break;
	case ESeveranceBoneTarget::RightLeg:
	case ESeveranceBoneTarget::LeftLeg:
		Result.SeverityTier = ESeveranceSeverityTier::MajorLimb;
		Result.BloodSplatterVolume = 1.10f;
		Result.AdrenalineGranted = 25.0f;
		break;
	default:
		Result.SeverityTier = ESeveranceSeverityTier::MinorLimb;
		Result.BloodSplatterVolume = 0.50f;
		Result.AdrenalineGranted = 15.0f;
		break;
	}

	// Add adrenaline
	AddAdrenaline(Result.AdrenalineGranted);

	// Broadcast delegates
	OnSeveranceExecuted.Broadcast(Result);
	OnBloodSplatterSpawned.Broadcast(SlicePlane.PlanePosition, SlicePlane.ImpulseDirection);
	OnNearbyAIWitnessedExecution.Broadcast(TargetActor);

	return Result;
}

void UAshenSeveranceDismembermentConvergenceSubsystem::AddAdrenaline(float Amount)
{
	AdrenalineState.CurrentAdrenaline = FMath::Clamp(AdrenalineState.CurrentAdrenaline + Amount, 0.0f, AdrenalineState.MaxAdrenaline);

	if (AdrenalineState.CurrentAdrenaline >= 50.0f)
	{
		AdrenalineState.bHyperArmorActive = true;
		AdrenalineState.DurationRemainingSeconds = 6.0f;
		OnAdrenalineSurgeTriggered.Broadcast(EAdrenalineSurgeType::MomentumBurst, 1.25f);
	}
	else
	{
		OnAdrenalineSurgeTriggered.Broadcast(EAdrenalineSurgeType::StaminaRefill, Amount);
	}
}
