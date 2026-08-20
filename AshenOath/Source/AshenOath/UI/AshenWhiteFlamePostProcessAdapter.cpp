// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenWhiteFlamePostProcessAdapter.h"

UAshenWhiteFlamePostProcessAdapter::UAshenWhiteFlamePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	RadiantBloomIntensity = 0.0f;
}
void UAshenWhiteFlamePostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenWhiteFlamePostProcessAdapter::ApplyWhiteFlamePostProcess(bool bWhiteFlameActive)
{
	RadiantBloomIntensity = bWhiteFlameActive ? 1.0f : 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenWhiteFlamePostProcessAdapter: Radiant Bloom Intensity: %.2f (High-Key Exposure Active)"),
		RadiantBloomIntensity);
}
