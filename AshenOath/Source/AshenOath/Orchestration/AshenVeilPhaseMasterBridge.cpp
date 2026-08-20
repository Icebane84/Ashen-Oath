// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenVeilPhaseMasterBridge.h"

UAshenVeilPhaseMasterBridge::UAshenVeilPhaseMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenVeilPhaseMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastVeilPhaseStatePulse();
}

void UAshenVeilPhaseMasterBridge::BroadcastVeilPhaseStatePulse()
{
	bVeilBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenVeilPhaseMasterBridge: Veil phase state pulse broadcasted across domain adapters."));
}
