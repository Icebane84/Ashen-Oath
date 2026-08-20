// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenMemoryBattleMasterBridge.h"

UAshenMemoryBattleMasterBridge::UAshenMemoryBattleMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMemoryBattleMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bMemoryBattleBridgeActive = true;
}

void UAshenMemoryBattleMasterBridge::BroadcastMemoryBattlePulse(FName EchoID, bool bVictory, float HarmonyReward)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryBattleMasterBridge: Memory Battle Pulse for Echo '%s' (Victory: %s, Harmony: +%.1f) broadcasted across domain subsystems."),
		*EchoID.ToString(), bVictory ? TEXT("YES") : TEXT("NO"), HarmonyReward);
}
