// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenCompanionSeatingPoseMeshAdapter.h"

UAshenCompanionSeatingPoseMeshAdapter::UAshenCompanionSeatingPoseMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentWeight = 0.0f;
	DesiredWeight = 0.0f;
}

void UAshenCompanionSeatingPoseMeshAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentWeight = FMath::FInterpTo(CurrentWeight, DesiredWeight, DeltaTime, 4.0f);
}

void UAshenCompanionSeatingPoseMeshAdapter::SetSeatingPoseWeight(float TargetWeight)
{
	DesiredWeight = FMath::Clamp(TargetWeight, 0.0f, 1.0f);
}
