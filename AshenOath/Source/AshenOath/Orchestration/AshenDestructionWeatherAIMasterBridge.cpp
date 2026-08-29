// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenDestructionWeatherAIMasterBridge.h"

UAshenDestructionWeatherAIMasterBridge::UAshenDestructionWeatherAIMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDestructionWeatherAIMasterBridge::BroadcastTacticalUpdate(
	EAtmosphericVisibilityTier Tier,
	float LockOnRange)
{
	OnTacticalBroadcaster.Broadcast(Tier, LockOnRange);
}
