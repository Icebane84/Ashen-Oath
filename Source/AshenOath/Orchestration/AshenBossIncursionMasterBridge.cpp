// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenBossIncursionMasterBridge.h"

UAshenBossIncursionMasterBridge::UAshenBossIncursionMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenBossIncursionMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bBossBridgeActive = true;
}

void UAshenBossIncursionMasterBridge::BroadcastBossPhaseTransition(EBossPhaseState NewPhase)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenBossIncursionMasterBridge: Broadcasted Boss Phase Transition -> %d"),
		static_cast<int32>(NewPhase));
}
