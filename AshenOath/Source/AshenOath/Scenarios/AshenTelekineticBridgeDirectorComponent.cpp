// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenTelekineticBridgeDirectorComponent.h"

UAshenTelekineticBridgeDirectorComponent::UAshenTelekineticBridgeDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentStability01 = 0.0f;
	TotalLifespanSeconds = 10.0f;
}

void UAshenTelekineticBridgeDirectorComponent::ManifestBridge(float DurationSeconds)
{
	TotalLifespanSeconds = FMath::Max(1.0f, DurationSeconds);
	CurrentStability01 = 1.0f;
}

float UAshenTelekineticBridgeDirectorComponent::DecayBridge(float DeltaSeconds)
{
	if (CurrentStability01 <= 0.0f)
	{
		return 0.0f;
	}

	const float DecayRate = 1.0f / TotalLifespanSeconds;
	CurrentStability01 = FMath::Clamp(CurrentStability01 - (DecayRate * DeltaSeconds), 0.0f, 1.0f);
	return CurrentStability01;
}
