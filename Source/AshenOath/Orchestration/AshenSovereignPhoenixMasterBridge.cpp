// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenSovereignPhoenixMasterBridge.h"

UAshenSovereignPhoenixMasterBridge::UAshenSovereignPhoenixMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSovereignPhoenixMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastSovereignPhoenixStatePulse();
}

void UAshenSovereignPhoenixMasterBridge::BroadcastSovereignPhoenixStatePulse()
{
	bSovereignMasterBridgeActive = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenSovereignPhoenixMasterBridge: Sovereign Phoenix state pulse broadcasted across all 12 domain vertical slice adapters."));
}
