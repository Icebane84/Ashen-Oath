// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenInnerWorldMasterBridge.h"

UAshenInnerWorldMasterBridge::UAshenInnerWorldMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenInnerWorldMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastInnerWorldStatePulse();
}

void UAshenInnerWorldMasterBridge::BroadcastInnerWorldStatePulse()
{
	bInnerWorldBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenInnerWorldMasterBridge: Inner World state pulse broadcasted across domain adapters."));
}
