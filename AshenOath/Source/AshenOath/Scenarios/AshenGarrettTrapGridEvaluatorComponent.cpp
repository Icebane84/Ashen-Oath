// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenGarrettTrapGridEvaluatorComponent.h"

UAshenGarrettTrapGridEvaluatorComponent::UAshenGarrettTrapGridEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenGarrettTrapGridEvaluatorComponent::EvaluateTrapTrigger(
	const FVector& EnemyLocation,
	const FVector& TrapLocation,
	float DetonationRadiusCentimeters) const
{
	const float DistSq = FVector::DistSquared(EnemyLocation, TrapLocation);
	return DistSq <= FMath::Square(DetonationRadiusCentimeters);
}
