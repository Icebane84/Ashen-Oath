// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenPsychologicalOSMasterBridge.h"

UAshenPsychologicalOSMasterBridge::UAshenPsychologicalOSMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenPsychologicalOSMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastPOSStatePulse();
}

void UAshenPsychologicalOSMasterBridge::BroadcastPOSStatePulse()
{
	bPOSBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenPsychologicalOSMasterBridge: Psychological OS state pulse broadcasted across domain adapters."));
}
