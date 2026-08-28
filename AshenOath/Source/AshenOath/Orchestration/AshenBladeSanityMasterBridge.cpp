// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenBladeSanityMasterBridge.h"

UAshenBladeSanityMasterBridge::UAshenBladeSanityMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenBladeSanityMasterBridge::BroadcastConvergenceState(
	float BladeHunger01,
	float CurrentSanity)
{
	OnConvergenceBroadcaster.Broadcast(BladeHunger01, CurrentSanity);
}
