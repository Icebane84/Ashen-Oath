// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenChaosNavMeshCutterComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenChaosNavMeshCutterComponent::UAshenChaosNavMeshCutterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	DefaultObstacleRadius = 250.0f;
	ParabolicElevationThreshold = 80.0f;
	CurrentImmediateThreat = 0.0f;
}

void UAshenChaosNavMeshCutterComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenChaosNavMeshCutterComponent::RegisterFractureRubbleCollapse(const FVector& ImpactLocation, float RubbleRadius, float RubbleHeight)
{
	const float EffectiveRadius = RubbleRadius > 0.0f ? RubbleRadius : DefaultObstacleRadius;
	ActiveRubbleLocations.Add(ImpactLocation);
	ActiveRubbleRadii.Add(EffectiveRadius);

	// Elevate structural ImmediateThreat
	CurrentImmediateThreat = FMath::Clamp(CurrentImmediateThreat + 0.25f, 0.0f, 1.0f);

	const bool bNeedsParabolic = RubbleHeight >= ParabolicElevationThreshold;
	OnChaosObstacleCreated.Broadcast(ImpactLocation, EffectiveRadius, bNeedsParabolic);

	UE_LOG(LogTemp, Log, TEXT("AshenChaosNavMeshCutter: Rubble obstacle created at (%s) radius %f, Parabolic Vault: %s"),
		*ImpactLocation.ToString(), EffectiveRadius, bNeedsParabolic ? TEXT("TRUE (+120uu)") : TEXT("FALSE"));
}

bool UAshenChaosNavMeshCutterComponent::IsLocationObstructed(const FVector& QueryLocation, float ClearanceRadius) const
{
	for (int32 i = 0; i < ActiveRubbleLocations.Num(); ++i)
	{
		const float DistSq = FVector::DistSquared2D(QueryLocation, ActiveRubbleLocations[i]);
		const float TotalRadius = ActiveRubbleRadii.IsValidIndex(i) ? (ActiveRubbleRadii[i] + ClearanceRadius) : (DefaultObstacleRadius + ClearanceRadius);
		if (DistSq <= FMath::Square(TotalRadius))
		{
			return true;
		}
	}
	return false;
}

bool UAshenChaosNavMeshCutterComponent::RequiresParabolicVault(const FVector& StartLoc, const FVector& TargetLoc) const
{
	const FVector Midpoint = (StartLoc + TargetLoc) * 0.5f;
	return IsLocationObstructed(Midpoint, 50.0f);
}
