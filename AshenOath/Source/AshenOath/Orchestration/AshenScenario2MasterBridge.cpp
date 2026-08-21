// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenScenario2MasterBridge.h"

UAshenScenario2MasterBridge::UAshenScenario2MasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario2MasterBridge::BroadcastGambitCompleted(bool bSilentEscape)
{
	OnSentinelsGambitCompleted.Broadcast(bSilentEscape);
}
