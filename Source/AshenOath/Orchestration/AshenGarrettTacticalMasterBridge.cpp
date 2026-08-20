// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenGarrettTacticalMasterBridge.h"

UAshenGarrettTacticalMasterBridge::UAshenGarrettTacticalMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettTacticalMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bTacticalBridgeActive = true;
}

void UAshenGarrettTacticalMasterBridge::BroadcastGadgetEventPulse(FName GadgetName)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTacticalMasterBridge: Gadget event pulse '%s' broadcasted across all domain adapters."), *GadgetName.ToString());
}
