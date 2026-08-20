// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenCompanionFatigueMeshAdapter.h"

UAshenCompanionFatigueMeshAdapter::UAshenCompanionFatigueMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentFatigue = 0.0f;
	DesiredFatigue = 0.0f;
}

void UAshenCompanionFatigueMeshAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentFatigue = FMath::FInterpTo(CurrentFatigue, DesiredFatigue, DeltaTime, 4.0f);
}

void UAshenCompanionFatigueMeshAdapter::SetTargetFatigueWeight(float TargetWeight)
{
	DesiredFatigue = FMath::Clamp(TargetWeight, 0.0f, 1.0f);
}
