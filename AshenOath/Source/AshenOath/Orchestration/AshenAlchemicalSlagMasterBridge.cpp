// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenAlchemicalSlagMasterBridge.h"

UAshenAlchemicalSlagMasterBridge::UAshenAlchemicalSlagMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenAlchemicalSlagMasterBridge::BroadcastSootUpdate(
	float SootLevel,
	EOathbringerBladeSurfaceState SurfaceState)
{
	OnSootBroadcaster.Broadcast(SootLevel, SurfaceState);
}
