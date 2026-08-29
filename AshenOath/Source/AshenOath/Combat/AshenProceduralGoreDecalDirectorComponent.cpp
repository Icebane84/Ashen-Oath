// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenProceduralGoreDecalDirectorComponent.h"

UAshenProceduralGoreDecalDirectorComponent::UAshenProceduralGoreDecalDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FTransform UAshenProceduralGoreDecalDirectorComponent::EvaluateDecalTransform(
	const FVector& Origin,
	const FVector& Normal,
	float SplatterVolume) const
{
	const FRotator Rotation = Normal.Rotation();
	const FVector Scale = FVector(1.0f, SplatterVolume * 120.0f, SplatterVolume * 120.0f);
	return FTransform(Rotation, Origin, Scale);
}
