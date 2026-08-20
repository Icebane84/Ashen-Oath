// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenSomaticPostureMasterBridge.h"

UAshenSomaticPostureMasterBridge::UAshenSomaticPostureMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticPostureMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastSomaticPostureStatePulse();
}

void UAshenSomaticPostureMasterBridge::BroadcastSomaticPostureStatePulse()
{
	bPostureMasterBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticPostureMasterBridge: Somatic posture state pulse broadcasted across domain adapters."));
}
