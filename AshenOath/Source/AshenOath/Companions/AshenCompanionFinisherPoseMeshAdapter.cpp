// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenCompanionFinisherPoseMeshAdapter.h"

UAshenCompanionFinisherPoseMeshAdapter::UAshenCompanionFinisherPoseMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentWeight = 0.0f;
	DesiredWeight = 0.0f;
}

void UAshenCompanionFinisherPoseMeshAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentWeight = FMath::FInterpTo(CurrentWeight, DesiredWeight, DeltaTime, 5.0f);
}

void UAshenCompanionFinisherPoseMeshAdapter::SetFinisherPoseWeight(float TargetWeight)
{
	DesiredWeight = FMath::Clamp(TargetWeight, 0.0f, 1.0f);
}
