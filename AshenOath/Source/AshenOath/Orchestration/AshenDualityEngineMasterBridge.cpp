// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenDualityEngineMasterBridge.h"

UAshenDualityEngineMasterBridge::UAshenDualityEngineMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDualityEngineMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastDualityStatePulse();
}

void UAshenDualityEngineMasterBridge::BroadcastDualityStatePulse()
{
	bDualityBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenDualityEngineMasterBridge: Duality Engine state pulse broadcasted across domain adapters."));
}
