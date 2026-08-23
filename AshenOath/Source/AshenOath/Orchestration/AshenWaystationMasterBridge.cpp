// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenWaystationMasterBridge.h"

UAshenWaystationMasterBridge::UAshenWaystationMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWaystationMasterBridge::BroadcastVignetteCompleted(EWaystationRunMode RunMode, bool bZeroDowned)
{
	OnVignetteFinished.Broadcast(bZeroDowned);
}
