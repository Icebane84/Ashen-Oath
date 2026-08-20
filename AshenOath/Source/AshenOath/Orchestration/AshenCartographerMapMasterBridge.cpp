// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenCartographerMapMasterBridge.h"

UAshenCartographerMapMasterBridge::UAshenCartographerMapMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCartographerMapMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastMapStateVectorPulse();
}

void UAshenCartographerMapMasterBridge::BroadcastMapStateVectorPulse()
{
	bMapMasterBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenCartographerMapMasterBridge: Cartographer Map state vector pulse broadcasted across domain adapters."));
}
