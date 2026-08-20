// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenBossInquisitionMasterBridge.h"

UAshenBossInquisitionMasterBridge::UAshenBossInquisitionMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenBossInquisitionMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bBossBridgeActive = true;
}

void UAshenBossInquisitionMasterBridge::BroadcastBossEventPulse(FName BossID, uint8 PhaseIndex)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBossInquisitionMasterBridge: Boss Event for %s (Phase %d) broadcasted across domain adapters."),
		*BossID.ToString(), PhaseIndex);
}
