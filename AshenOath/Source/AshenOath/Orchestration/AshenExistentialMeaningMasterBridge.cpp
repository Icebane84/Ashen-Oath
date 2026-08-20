// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenExistentialMeaningMasterBridge.h"

UAshenExistentialMeaningMasterBridge::UAshenExistentialMeaningMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenExistentialMeaningMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bMeaningBridgeActive = true;
}

void UAshenExistentialMeaningMasterBridge::BroadcastTrialOfWillResolved(ETrialOfWillChoice Choice)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenExistentialMeaningMasterBridge: Broadcasted Trial of Will Resolved with Choice %d!"),
		static_cast<int32>(Choice));
}

void UAshenExistentialMeaningMasterBridge::BroadcastKeystoneMemoryCompiled(FName MemoryID, EKeystoneInterpretiveLens Lens)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenExistentialMeaningMasterBridge: Broadcasted Keystone Memory [%s] Compiled with Lens %d!"),
		*MemoryID.ToString(), static_cast<int32>(Lens));
}
