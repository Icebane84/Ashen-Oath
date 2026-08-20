// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenUnreliableNarratorMasterBridge.h"

UAshenUnreliableNarratorMasterBridge::UAshenUnreliableNarratorMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenUnreliableNarratorMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bNarratorBridgeActive = true;
}

void UAshenUnreliableNarratorMasterBridge::BroadcastHallucinationPulse(uint8 StateEnum)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNarratorMasterBridge: Hallucination pulse for state %d broadcasted across all domain adapters."), StateEnum);
}
