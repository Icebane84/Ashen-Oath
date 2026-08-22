// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenScenario5MasterBridge.h"

UAshenScenario5MasterBridge::UAshenScenario5MasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario5MasterBridge::BroadcastWeepingMireCleared(bool bZeroCompanionDowned)
{
	OnWeepingMireCleared.Broadcast(bZeroCompanionDowned);
}
