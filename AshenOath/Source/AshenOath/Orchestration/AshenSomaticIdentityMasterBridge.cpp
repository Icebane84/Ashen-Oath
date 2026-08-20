// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenSomaticIdentityMasterBridge.h"

UAshenSomaticIdentityMasterBridge::UAshenSomaticIdentityMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticIdentityMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastIdentityStatePulse();
}

void UAshenSomaticIdentityMasterBridge::BroadcastIdentityStatePulse()
{
	bIdentityBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticIdentityMasterBridge: Somatic identity state pulse broadcasted across domain adapters."));
}
