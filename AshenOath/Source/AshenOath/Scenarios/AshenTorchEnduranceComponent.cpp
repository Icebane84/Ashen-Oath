// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenTorchEnduranceComponent.h"

UAshenTorchEnduranceComponent::UAshenTorchEnduranceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentFuel01 = 1.0f;
	TotalBurnDurationSeconds = 120.0f;
}

float UAshenTorchEnduranceComponent::ConsumeTorchFuel(float DeltaSeconds)
{
	const float BurnRate = (TotalBurnDurationSeconds > 0.0f) ? (1.0f / TotalBurnDurationSeconds) : 0.0083f;
	CurrentFuel01 = FMath::Clamp(CurrentFuel01 - (BurnRate * DeltaSeconds), 0.0f, 1.0f);
	return CurrentFuel01;
}

void UAshenTorchEnduranceComponent::RekindleTorch(float ResinFuelPercent)
{
	CurrentFuel01 = FMath::Clamp(CurrentFuel01 + ResinFuelPercent, 0.0f, 1.0f);
}
