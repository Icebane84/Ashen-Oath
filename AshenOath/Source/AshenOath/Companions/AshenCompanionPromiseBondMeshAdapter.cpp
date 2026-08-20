// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenCompanionPromiseBondMeshAdapter.h"

UAshenCompanionPromiseBondMeshAdapter::UAshenCompanionPromiseBondMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentWeight = 0.0f;
	DesiredWeight = 0.0f;
}

void UAshenCompanionPromiseBondMeshAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentWeight = FMath::FInterpTo(CurrentWeight, DesiredWeight, DeltaTime, 4.0f);
}

void UAshenCompanionPromiseBondMeshAdapter::SetVowBondWeight(float TargetWeight)
{
	DesiredWeight = FMath::Clamp(TargetWeight, 0.0f, 1.0f);
}
