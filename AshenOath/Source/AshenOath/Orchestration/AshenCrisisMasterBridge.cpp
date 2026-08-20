// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenCrisisMasterBridge.h"

UAshenCrisisMasterBridge::UAshenCrisisMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCrisisMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastCrisisStatePulse();
}

void UAshenCrisisMasterBridge::BroadcastCrisisStatePulse()
{
	bCrisisBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenCrisisMasterBridge: Crisis state pulse broadcasted across domain adapters."));
}
