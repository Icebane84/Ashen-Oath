// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenTripartiteEQSSpatialDirector.h"

UAshenTripartiteEQSSpatialDirector::UAshenTripartiteEQSSpatialDirector()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FVector UAshenTripartiteEQSSpatialDirector::ComputeGarrettTargetLocation(
	const FVector& KaelenLocation,
	const FVector& KaelenForward,
	float FlankAngleDeg,
	float DistanceUU) const
{
	const FRotator Rotation(0.0f, FlankAngleDeg, 0.0f);
	const FVector OffsetDirection = Rotation.RotateVector(KaelenForward);
	return KaelenLocation + (OffsetDirection * DistanceUU);
}

FVector UAshenTripartiteEQSSpatialDirector::ComputeSerafinaTargetLocation(
	const FVector& KaelenLocation,
	const FVector& KaelenForward,
	float DistanceUU) const
{
	// Serafina stays in rear-flank quadrant (-135 degrees)
	const FRotator Rotation(0.0f, -135.0f, 0.0f);
	const FVector OffsetDirection = Rotation.RotateVector(KaelenForward);
	return KaelenLocation + (OffsetDirection * DistanceUU);
}
