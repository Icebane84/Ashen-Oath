// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenDualSenseMasterBridge.h"

UAshenDualSenseMasterBridge::UAshenDualSenseMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDualSenseMasterBridge::BroadcastTriggerLockout(bool bEngaged)
{
	OnTriggerLockoutEngaged.Broadcast(bEngaged);
}
