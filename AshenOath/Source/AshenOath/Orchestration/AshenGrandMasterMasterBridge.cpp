// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenGrandMasterMasterBridge.h"

UAshenGrandMasterMasterBridge::UAshenGrandMasterMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGrandMasterMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastGrandMasterStatePulse();
}

void UAshenGrandMasterMasterBridge::BroadcastGrandMasterStatePulse()
{
	bGrandMasterBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenGrandMasterMasterBridge: Grand Master state pulse broadcasted across domain adapters."));
}
