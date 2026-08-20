// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenCompanionFormationMeshAdapter.h"

UAshenCompanionFormationMeshAdapter::UAshenCompanionFormationMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentLean = 0.0f;
	TargetLean = 0.0f;
}

void UAshenCompanionFormationMeshAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentLean = FMath::FInterpTo(CurrentLean, TargetLean, DeltaTime, 6.0f);
}

void UAshenCompanionFormationMeshAdapter::SetFormationChargeActive(bool bInCharge, float LeanAngle)
{
	TargetLean = bInCharge ? FMath::Clamp(LeanAngle, -30.0f, 30.0f) : 0.0f;
}
