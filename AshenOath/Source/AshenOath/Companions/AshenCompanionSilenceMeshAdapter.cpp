// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenCompanionSilenceMeshAdapter.h"

UAshenCompanionSilenceMeshAdapter::UAshenCompanionSilenceMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentGazeWeight = 0.0f;
	DesiredGazeWeight = 0.0f;
}

void UAshenCompanionSilenceMeshAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentGazeWeight = FMath::FInterpTo(CurrentGazeWeight, DesiredGazeWeight, DeltaTime, 3.0f);
}

void UAshenCompanionSilenceMeshAdapter::SetSilenceGazeWeight(float TargetWeight)
{
	DesiredGazeWeight = FMath::Clamp(TargetWeight, 0.0f, 1.0f);
}
