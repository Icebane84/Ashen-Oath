// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenScenario8MasterBridge.h"

UAshenScenario8MasterBridge::UAshenScenario8MasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario8MasterBridge::BroadcastTorchUpdate(
	float Fuel01,
	float LightRadiusUU)
{
	OnTorchBroadcaster.Broadcast(Fuel01, LightRadiusUU);
}
