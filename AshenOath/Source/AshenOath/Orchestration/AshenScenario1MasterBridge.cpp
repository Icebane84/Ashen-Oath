// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenScenario1MasterBridge.h"

UAshenScenario1MasterBridge::UAshenScenario1MasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario1MasterBridge::BroadcastChapelCleared(bool bRitualSuccessful)
{
	OnOakhavenChapelCleared.Broadcast(bRitualSuccessful);
}
