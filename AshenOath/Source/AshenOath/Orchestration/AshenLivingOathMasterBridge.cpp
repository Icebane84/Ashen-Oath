// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenLivingOathMasterBridge.h"

UAshenLivingOathMasterBridge::UAshenLivingOathMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenLivingOathMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bLivingOathBridgeActive = true;
}

void UAshenLivingOathMasterBridge::BroadcastLivingOathPulse(EAshenLivingOathType OathType, EAshenOathState State)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingOathMasterBridge: Living Oath Pulse for Type %d (State %d) broadcasted across domain subsystems."),
		(int32)OathType, (int32)State);
}
