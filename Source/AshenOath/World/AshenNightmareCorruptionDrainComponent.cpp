// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenNightmareCorruptionDrainComponent.h"

UAshenNightmareCorruptionDrainComponent::UAshenNightmareCorruptionDrainComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	DrainRatePerSecond = 0.08f;
}
void UAshenNightmareCorruptionDrainComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenNightmareCorruptionDrainComponent::SiphonCorruption(float DeltaSeconds, float CurrentIntensity) const
{
	const float Siphoned = DrainRatePerSecond * DeltaSeconds;
	const float NewIntensity = FMath::Max(0.0f, CurrentIntensity - Siphoned);
	UE_LOG(LogTemp, Log, TEXT("UAshenNightmareCorruptionDrainComponent: Siphoned %.3f corruption -> New Intensity: %.2f"),
		Siphoned, NewIntensity);
	return NewIntensity;
}
