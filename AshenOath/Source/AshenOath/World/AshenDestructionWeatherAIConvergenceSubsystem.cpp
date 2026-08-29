// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenDestructionWeatherAIConvergenceSubsystem.h"

UAshenDestructionWeatherAIConvergenceSubsystem::UAshenDestructionWeatherAIConvergenceSubsystem()
{
	CurrentPerception.VisibilityTier = EAtmosphericVisibilityTier::ClearDaylight;
	CurrentPerception.MaxLockOnRangeUU = 1500.0f;
	CurrentPerception.AISightRadiusUU = 2000.0f;
	CurrentPerception.AIVisionConeDegrees = 90.0f;
	CurrentPerception.bStealthAmbushEligible = false;
}

void UAshenDestructionWeatherAIConvergenceSubsystem::UpdateWeatherPerceptionBounds(
	EAtmosphericVisibilityTier VisibilityTier)
{
	CurrentPerception.VisibilityTier = VisibilityTier;

	switch (VisibilityTier)
	{
	case EAtmosphericVisibilityTier::BlizzardWhiteout:
		CurrentPerception.MaxLockOnRangeUU = 500.0f;
		CurrentPerception.AISightRadiusUU = 600.0f;
		CurrentPerception.AIVisionConeDegrees = 45.0f;
		CurrentPerception.bStealthAmbushEligible = true;
		break;

	case EAtmosphericVisibilityTier::VolcanicAshStorm:
		CurrentPerception.MaxLockOnRangeUU = 750.0f;
		CurrentPerception.AISightRadiusUU = 900.0f;
		CurrentPerception.AIVisionConeDegrees = 55.0f;
		CurrentPerception.bStealthAmbushEligible = true;
		break;

	case EAtmosphericVisibilityTier::AcidRainMist:
		CurrentPerception.MaxLockOnRangeUU = 1100.0f;
		CurrentPerception.AISightRadiusUU = 1400.0f;
		CurrentPerception.AIVisionConeDegrees = 75.0f;
		CurrentPerception.bStealthAmbushEligible = false;
		break;

	case EAtmosphericVisibilityTier::ClearDaylight:
	default:
		CurrentPerception.MaxLockOnRangeUU = 1500.0f;
		CurrentPerception.AISightRadiusUU = 2000.0f;
		CurrentPerception.AIVisionConeDegrees = 90.0f;
		CurrentPerception.bStealthAmbushEligible = false;
		break;
	}

	OnWeatherPerceptionClamped.Broadcast(VisibilityTier, CurrentPerception.MaxLockOnRangeUU);
}

void UAshenDestructionWeatherAIConvergenceSubsystem::TriggerConductiveLightningArc(
	FVector Origin,
	const TArray<FConductiveArcTargetInfo>& PotentialTargets)
{
	const float ArcRadius = 350.0f;
	int32 TargetsChained = 0;
	float TotalDamage = 0.0f;

	for (const FConductiveArcTargetInfo& Target : PotentialTargets)
	{
		if (Target.SurfaceType != EConductiveSurfaceType::NonConductiveStone)
		{
			const float Dist = FVector::Dist(Origin, Target.Location);
			if (Dist <= ArcRadius)
			{
				TargetsChained++;
				TotalDamage += Target.ShockDamage;
			}
		}
	}

	OnConductiveLightningArced.Broadcast(Origin, TargetsChained, TotalDamage);
}

void UAshenDestructionWeatherAIConvergenceSubsystem::RegisterCleavedRubbleObstacle(
	FVector ObstacleLocation,
	float Radius)
{
	OnRubbleChokepointFormed.Broadcast(ObstacleLocation, Radius);
}

void UAshenDestructionWeatherAIConvergenceSubsystem::TriggerCoverShatter(
	FVector ShatterLocation,
	float ShrapnelDmg)
{
	OnCoverShattered.Broadcast(ShatterLocation, ShrapnelDmg);
}
