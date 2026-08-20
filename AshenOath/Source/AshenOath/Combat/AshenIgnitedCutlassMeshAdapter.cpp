// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenIgnitedCutlassMeshAdapter.h"

UAshenIgnitedCutlassMeshAdapter::UAshenIgnitedCutlassMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	FlameEmissiveGlow = 0.0f;
}
void UAshenIgnitedCutlassMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenIgnitedCutlassMeshAdapter::SetCutlassIgnitionState(bool bIgnited)
{
	FlameEmissiveGlow = bIgnited ? 3.0f : 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenIgnitedCutlassMeshAdapter: Cutlass Flame Ignition Emissive: %.1f"),
		FlameEmissiveGlow);
}
