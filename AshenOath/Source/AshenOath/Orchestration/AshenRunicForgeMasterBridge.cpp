// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenRunicForgeMasterBridge.h"

UAshenRunicForgeMasterBridge::UAshenRunicForgeMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRunicForgeMasterBridge::BroadcastAscensionUpdate(
	EOathbringerAscensionTier Tier,
	const FOathbringerEvolutionState& State)
{
	OnAscensionBroadcaster.Broadcast(Tier, State);
}
