// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenRelationalPostProcessAdapter.h"

UAshenRelationalPostProcessAdapter::UAshenRelationalPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	WarmTemperatureK = 6500.0f;
	ColdTemperatureK = 4500.0f;
	CurrentTemperature = 6500.0f;
	TargetTemperature = 6500.0f;
	CurrentSaturation = 1.0f;
	TargetSaturation = 1.0f;
}

void UAshenRelationalPostProcessAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentTemperature = FMath::FInterpTo(CurrentTemperature, TargetTemperature, DeltaTime, 4.0f);
	CurrentSaturation = FMath::FInterpTo(CurrentSaturation, TargetSaturation, DeltaTime, 4.0f);
}

void UAshenRelationalPostProcessAdapter::UpdateFellowshipGrading(
	float TrioResonance,
	ERelationalRuptureState RuptureState)
{
	const float ClampedResonance = FMath::Clamp(TrioResonance, 0.0f, 1.0f);
	TargetTemperature = FMath::Lerp(ColdTemperatureK, WarmTemperatureK, ClampedResonance);

	if (RuptureState == ERelationalRuptureState::ActiveRupture || RuptureState == ERelationalRuptureState::DeepEstrangement)
	{
		TargetSaturation = 0.65f;
	}
	else
	{
		TargetSaturation = FMath::Lerp(0.80f, 1.10f, ClampedResonance);
	}
}
