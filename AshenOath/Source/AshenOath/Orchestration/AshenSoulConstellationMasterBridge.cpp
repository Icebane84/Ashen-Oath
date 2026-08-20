// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenSoulConstellationMasterBridge.h"

UAshenSoulConstellationMasterBridge::UAshenSoulConstellationMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSoulConstellationMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastKernelSynchronisationPulse();
}

void UAshenSoulConstellationMasterBridge::BroadcastKernelSynchronisationPulse()
{
	bKernelBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationMasterBridge: Soul Constellation Kernel synchronisation pulse broadcasted across all domain adapters."));
}
