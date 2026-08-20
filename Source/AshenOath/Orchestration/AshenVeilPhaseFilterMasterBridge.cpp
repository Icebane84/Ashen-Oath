// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenVeilPhaseFilterMasterBridge.h"

UAshenVeilPhaseFilterMasterBridge::UAshenVeilPhaseFilterMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenVeilPhaseFilterMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastVeilPhaseFilterStatePulse();
}

void UAshenVeilPhaseFilterMasterBridge::BroadcastVeilPhaseFilterStatePulse()
{
	bVeilFilterBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenVeilPhaseFilterMasterBridge: Veil phase filter state pulse broadcasted across domain adapters."));
}
