// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Spatial/AshenSpatialEvaluator.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"

float URelationalSpatialEvaluator::ComputeFlankDot(
	const FVector& AllyLocation,
	const FVector& EnemyLocation,
	const FVector& EnemyForward)
{
	// Vector pointing from Enemy -> Ally
	const FVector EnemyToAlly = (AllyLocation - EnemyLocation).GetSafeNormal2D();
	const FVector NormEnemyForward = EnemyForward.GetSafeNormal2D();

	// True rear flank: Dot product of EnemyToAlly with negative EnemyForward
	return FVector::DotProduct(EnemyToAlly, -NormEnemyForward);
}

FAshenSpatialTelemetry URelationalSpatialEvaluator::EvaluateSynergy(
	const AActor* Ally,
	const AActor* Enemy,
	const FVector& WarpTarget,
	EAshenCompanionState AllyState) const
{
	FAshenSpatialTelemetry Telemetry;

	if (!Ally || !Enemy)
	{
		return Telemetry;
	}

	// 1. Companion state check
	Telemetry.bStateValid = (AllyState == EAshenCompanionState::Normal);

	// 2. Distance check
	const FVector AllyLoc = Ally->GetActorLocation();
	const FVector EnemyLoc = Enemy->GetActorLocation();
	Telemetry.DistanceUU = FVector::Dist(AllyLoc, EnemyLoc);
	Telemetry.bDistanceValid = (Telemetry.DistanceUU <= MaxSynergyDistanceUU);

	// 3. Flank angle check
	Telemetry.FlankDot = ComputeFlankDot(AllyLoc, EnemyLoc, Enemy->GetActorForwardVector());
	const float AngleCosThreshold = FMath::Cos(FMath::DegreesToRadians(FlankHalfAngleDegrees));
	Telemetry.bFlankValid = (Telemetry.FlankDot >= AngleCosThreshold);

	// 4. Line of Sight
	Telemetry.bLineOfSightValid = CheckLineOfSight(Ally, Enemy);

	// 5. Navigation
	Telemetry.bNavigationValid = CheckNavigation(Ally, WarpTarget);

	return Telemetry;
}

bool URelationalSpatialEvaluator::CheckLineOfSight(const AActor* Ally, const AActor* Enemy) const
{
	if (!Ally || !Enemy) return false;

	const UWorld* World = Ally->GetWorld();
	if (!World) return false;

	FHitResult HitResult;
	FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(AshenRelationalLOS), false, Ally);
	TraceParams.AddIgnoredActor(Enemy);

	const bool bHitObstacle = World->LineTraceSingleByChannel(
		HitResult,
		Ally->GetActorLocation() + FVector(0.0f, 0.0f, 50.0f),
		Enemy->GetActorLocation() + FVector(0.0f, 0.0f, 50.0f),
		ECC_Visibility,
		TraceParams
	);

	return !bHitObstacle;
}

bool URelationalSpatialEvaluator::CheckNavigation(const AActor* Ally, const FVector& WarpTarget) const
{
	// Non-zero warp target implies valid geometric location
	return !WarpTarget.IsNearlyZero();
}

bool UAshenSpatialEvaluator::EvaluateFlankConvexHull(
	const FAshenSpatialConvexHullQuery& Query,
	FVector& OutWarpLocation,
	FRotator& OutWarpRotation)
{
	if (!Query.SourcePlayer || !Query.CompanionAlly || !Query.TargetEnemy)
	{
		return false;
	}

	const FVector PlayerLoc = Query.SourcePlayer->GetActorLocation();
	const FVector AllyLoc = Query.CompanionAlly->GetActorLocation();
	const FVector EnemyLoc = Query.TargetEnemy->GetActorLocation();

	// 1. Distance envelope check
	const float DistSq = FVector::DistSquared(PlayerLoc, AllyLoc);
	if (DistSq > FMath::Square(Query.MaxDistanceEnvelope))
	{
		return false;
	}

	// 2. Directional Flank Vector Check
	const float FlankDot = URelationalSpatialEvaluator::ComputeFlankDot(AllyLoc, EnemyLoc, Query.TargetEnemy->GetActorForwardVector());
	const float AngleCosThreshold = FMath::Cos(FMath::DegreesToRadians(Query.RequiredFlankAngleDegrees));

	if (FlankDot < AngleCosThreshold)
	{
		return false;
	}

	// 3. Line of Sight Raycast
	const UWorld* World = Query.SourcePlayer->GetWorld();
	if (World)
	{
		FHitResult HitResult;
		FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(AshenSpatialLOS), false, Query.CompanionAlly);
		TraceParams.AddIgnoredActor(Query.SourcePlayer);
		TraceParams.AddIgnoredActor(Query.TargetEnemy);

		const bool bHitObstacle = World->LineTraceSingleByChannel(
			HitResult,
			AllyLoc + FVector(0.0f, 0.0f, 50.0f),
			EnemyLoc + FVector(0.0f, 0.0f, 50.0f),
			ECC_Visibility,
			TraceParams
		);

		if (bHitObstacle)
		{
			return false;
		}
	}

	// Compute final motion-warp landing point
	const FVector EnemyForward = Query.TargetEnemy->GetActorForwardVector().GetSafeNormal2D();
	const FVector EnemyToAlly = (AllyLoc - EnemyLoc).GetSafeNormal2D();
	OutWarpLocation = EnemyLoc - (EnemyForward * 130.0f);
	OutWarpRotation = (-EnemyToAlly).Rotation();
	return true;
}
