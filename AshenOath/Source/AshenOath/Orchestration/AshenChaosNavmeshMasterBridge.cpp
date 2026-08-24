// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenChaosNavmeshMasterBridge.h"

UAshenChaosNavmeshMasterBridge::UAshenChaosNavmeshMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenChaosNavmeshMasterBridge::BroadcastDemolitionEvent(
	const FVector& Location,
	ENavmeshObstructionState Obstruction)
{
	OnObstructionBroadcaster.Broadcast(Location, Obstruction);
}
