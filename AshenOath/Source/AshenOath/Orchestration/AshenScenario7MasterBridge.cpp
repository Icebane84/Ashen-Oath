// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenScenario7MasterBridge.h"

UAshenScenario7MasterBridge::UAshenScenario7MasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario7MasterBridge::BroadcastCalderaUpdate(
	float TempC,
	float HeatExhaustion)
{
	OnCalderaBroadcaster.Broadcast(TempC, HeatExhaustion);
}
