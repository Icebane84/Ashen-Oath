// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenScenario9MasterBridge.h"

UAshenScenario9MasterBridge::UAshenScenario9MasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario9MasterBridge::BroadcastCitadelUpdate(
	EVoidGravityZoneTier Tier,
	float GravityScale)
{
	OnGravityBroadcaster.Broadcast(Tier, GravityScale);
}
