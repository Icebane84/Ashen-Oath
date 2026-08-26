// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenRubblePhysicsMasterBridge.h"

UAshenRubblePhysicsMasterBridge::UAshenRubblePhysicsMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRubblePhysicsMasterBridge::BroadcastHazardState(const FMasonryHazardVector& HazardState)
{
	OnHazardBroadcaster.Broadcast(HazardState);
}
