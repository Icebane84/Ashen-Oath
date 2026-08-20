// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenNightmareMasterBridge.h"

UAshenNightmareMasterBridge::UAshenNightmareMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenNightmareMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bNightmareBridgeActive = true;
}

void UAshenNightmareMasterBridge::BroadcastIncursionState(bool bActive, float Intensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNightmareMasterBridge: Broadcasted Incursion State (Active: %s, Intensity: %.2f)."),
		bActive ? TEXT("TRUE") : TEXT("FALSE"), Intensity);
}

void UAshenNightmareMasterBridge::BroadcastRiftSealed(FName RiftID)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNightmareMasterBridge: Broadcasted Rift Sealed (Rift: '%s')."), *RiftID.ToString());
}
