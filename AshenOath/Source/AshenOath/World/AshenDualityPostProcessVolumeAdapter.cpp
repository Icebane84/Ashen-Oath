// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenDualityPostProcessVolumeAdapter.h"

UAshenDualityPostProcessVolumeAdapter::UAshenDualityPostProcessVolumeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDualityPostProcessVolumeAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenDualityPostProcessVolumeAdapter::AdjustPostProcessForRealmShift(float RealmShiftBlend)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDualityPostProcessVolumeAdapter: Post-process settings adjusted for realm shift blend %.2f"), RealmShiftBlend);
}
