// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenActiveMemoryWeavingMasterBridge.h"

UAshenActiveMemoryWeavingMasterBridge::UAshenActiveMemoryWeavingMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenActiveMemoryWeavingMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bWeavingBridgeActive = true;
}

void UAshenActiveMemoryWeavingMasterBridge::BroadcastPatternWeaved(EWeavingPatternType Pattern)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenActiveMemoryWeavingMasterBridge: Broadcasted Weaved Pattern -> %d"),
		static_cast<int32>(Pattern));
}
