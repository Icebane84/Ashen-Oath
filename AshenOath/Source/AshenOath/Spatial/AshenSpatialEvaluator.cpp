// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Spatial/AshenSpatialEvaluator.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"
#include "NavigationSystem.h"

float UAshenSpatialEvaluator::ComputeFlankDot(const FVector& EnemyLocation, const FVector& EnemyForward, const FVector& AllyLocation)
{
	const FVector EnemyToAlly = (AllyLocation - EnemyLocation).GetSafeNormal2D();
	const FVector TargetRear = -EnemyForward.GetSafeNormal2D();
	return FVector::DotProduct(EnemyToAlly, TargetRear);
}

FAshenSpatialPredicateResult UAshenSpatialEvaluator::EvaluateSpatialSynergy(
	const FAshenSpatialSynergyQuery& Query,
	FVector& OutMotionWarpLocation,
	FRotator& OutMotionWarpRotation)
{
	FAshenSpatialPredicateResult Result;

	if (!Query.SourcePlayer || !Query.CompanionAlly || !Query.TargetEnemy)
	{
		return Result;
	}

	const FVector PlayerLoc = Query.SourcePlayer->GetActorLocation();
	const FVector AllyLoc = Query.CompanionAlly->GetActorLocation();
	const FVector EnemyLoc = Query.TargetEnemy->GetActorLocation();
	const FVector EnemyForward = Query.TargetEnemy->GetActorForwardVector().GetSafeNormal2D();

	// 1. Distance Predicate (Strictly <= MaxSynergyDistanceUU)
	Result.ActualDistanceUU = FVector::Dist2D(PlayerLoc, AllyLoc);
	Result.bDistanceValid = (Result.ActualDistanceUU <= Query.MaxSynergyDistanceUU);

	// 2. Angular Flank Predicate
	Result.ComputedFlankDot = ComputeFlankDot(EnemyLoc, EnemyForward, AllyLoc);
	const float AngleCosThreshold = FMath::Cos(FMath::DegreesToRadians(Query.RequiredFlankHalfAngleDegrees));
	Result.bAngularFlankValid = (Result.ComputedFlankDot >= AngleCosThreshold);

	// Early out if basic geometric tests fail
	if (!Result.bDistanceValid || !Result.bAngularFlankValid)
	{
		Result.bOverallSynergyValid = false;
		return Result;
	}

	UWorld* World = Query.SourcePlayer->GetWorld();
	if (!World)
	{
		return Result;
	}

	// 3. Line-of-Sight Predicate
	FHitResult HitResult;
	FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(AshenSpatialLOS), false, Query.CompanionAlly);
	TraceParams.AddIgnoredActor(Query.SourcePlayer);
	TraceParams.AddIgnoredActor(Query.TargetEnemy);

	const FVector TraceStart = AllyLoc + FVector(0.0f, 0.0f, 50.0f);
	const FVector TraceEnd = EnemyLoc + FVector(0.0f, 0.0f, 50.0f);

	const bool bHitObstacle = World->LineTraceSingleByChannel(
		HitResult,
		TraceStart,
		TraceEnd,
		ECC_Visibility,
		TraceParams
	);
	Result.bLineOfSightValid = !bHitObstacle;

	// 4. Navigation Reachability Predicate
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);
	if (NavSys && NavSys->GetDefaultNavDataInstance())
	{
		const bool bPathExists = NavSys->TestPathSync(
			FPathFindingQuery(
				Query.CompanionAlly,
				*NavSys->GetDefaultNavDataInstance(),
				AllyLoc,
				EnemyLoc
			)
		);
		Result.bNavigationReachable = bPathExists;
	}
	else
	{
		Result.bNavigationReachable = true; // Fallback if Navigation System is uninitialized
	}

	Result.bOverallSynergyValid = Result.bDistanceValid &&
	                              Result.bAngularFlankValid &&
	                              Result.bLineOfSightValid &&
	                              Result.bNavigationReachable;

	if (Result.bOverallSynergyValid)
	{
		OutMotionWarpLocation = EnemyLoc - (EnemyForward * 130.0f);
		const FVector EnemyToAlly = (AllyLoc - EnemyLoc).GetSafeNormal2D();
		OutMotionWarpRotation = (-EnemyToAlly).Rotation();
	}

	return Result;
}
