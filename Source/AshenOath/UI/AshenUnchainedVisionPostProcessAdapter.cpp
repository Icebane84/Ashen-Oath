// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUnchainedVisionPostProcessAdapter.h"

UAshenUnchainedVisionPostProcessAdapter::UAshenUnchainedVisionPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	TunnelVisionIntensity = 0.0f;
}
void UAshenUnchainedVisionPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenUnchainedVisionPostProcessAdapter::ApplyUnchainedVisionFX(float CorruptionAmount)
{
	const float C = FMath::Clamp(CorruptionAmount, 0.0f, 1.0f);
	TunnelVisionIntensity = (C >= 0.70f) ? (C - 0.70f) / 0.30f : 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenUnchainedVisionPostProcessAdapter: Unchained Tunnel Vision Intensity: %.2f (Corruption: %.2f)"),
		TunnelVisionIntensity, C);
}
