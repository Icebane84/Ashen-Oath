// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Spatial/AshenSpatialEvaluator.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"

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
	const FVector EnemyToAlly = (AllyLoc - EnemyLoc).GetSafeNormal2D();
	const FVector EnemyForward = Query.TargetEnemy->GetActorForwardVector().GetSafeNormal2D();

	// Ally must be in rear arc of enemy (Dot product relative to negative enemy forward)
	const float RearAlignment = FVector::DotProduct(EnemyToAlly, -EnemyForward);
	const float AngleCosThreshold = FMath::Cos(FMath::DegreesToRadians(Query.RequiredFlankAngleDegrees));

	if (RearAlignment < AngleCosThreshold)
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
	OutWarpLocation = EnemyLoc - (EnemyForward * 130.0f);
	OutWarpRotation = (-EnemyToAlly).Rotation();
	return true;
}
