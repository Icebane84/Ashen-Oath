// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenScenario4MasterBridge.h"

UAshenScenario4MasterBridge::UAshenScenario4MasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario4MasterBridge::BroadcastWhisperwoodCleared(bool bSanityMaintained)
{
	OnWhisperwoodCleared.Broadcast(bSanityMaintained);
}
