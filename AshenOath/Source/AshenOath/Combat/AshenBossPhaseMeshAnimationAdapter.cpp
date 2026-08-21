// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenBossPhaseMeshAnimationAdapter.h"

UAshenBossPhaseMeshAnimationAdapter::UAshenBossPhaseMeshAnimationAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentWeight = 0.0f;
	DesiredWeight = 0.0f;
}

void UAshenBossPhaseMeshAnimationAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentWeight = FMath::FInterpTo(CurrentWeight, DesiredWeight, DeltaTime, 3.5f);
}

void UAshenBossPhaseMeshAnimationAdapter::SetPhaseCorruptionWeight(float TargetWeight)
{
	DesiredWeight = FMath::Clamp(TargetWeight, 0.0f, 1.0f);
}
