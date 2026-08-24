// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenPommelGazeTrackingEvaluator.h"

UAshenPommelGazeTrackingEvaluator::UAshenPommelGazeTrackingEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FRotator UAshenPommelGazeTrackingEvaluator::EvaluatePommelGazeRotation(
	const FVector& PommelLocation,
	const FVector& TargetLocation) const
{
	const FVector Dir = (TargetLocation - PommelLocation).GetSafeNormal();
	return Dir.Rotation();
}

float UAshenPommelGazeTrackingEvaluator::EvaluatePommelEmissiveGlow(float Corruption01) const
{
	return FMath::Clamp(0.10f + (0.90f * Corruption01), 0.10f, 1.0f);
}

bool UAshenPommelGazeTrackingEvaluator::IsWeepingBile(float Corruption01) const
{
	return Corruption01 >= 0.70f;
}
