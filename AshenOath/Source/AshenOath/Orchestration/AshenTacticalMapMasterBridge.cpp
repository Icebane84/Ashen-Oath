// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenTacticalMapMasterBridge.h"

UAshenTacticalMapMasterBridge::UAshenTacticalMapMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTacticalMapMasterBridge::BroadcastWaypointState(
	const FString& WaypointId,
	EWaypointBeaconState NewState)
{
	OnWaypointBroadcaster.Broadcast(WaypointId, NewState);
}
