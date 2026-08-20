// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenExecutionMasterBridge.h"

UAshenExecutionMasterBridge::UAshenExecutionMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenExecutionMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bExecutionBridgeActive = true;
}

void UAshenExecutionMasterBridge::BroadcastExecutionFlourishPulse(uint8 StanceEnum)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenExecutionMasterBridge: Execution flourish pulse for stance %d broadcasted across all domain adapters."), StanceEnum);
}
