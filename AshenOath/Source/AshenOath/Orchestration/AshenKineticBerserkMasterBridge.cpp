// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenKineticBerserkMasterBridge.h"

UAshenKineticBerserkMasterBridge::UAshenKineticBerserkMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenKineticBerserkMasterBridge::BroadcastRiposteCompleted(EAshenCounterAttackZone Zone, float KineticJoules)
{
	OnRiposteSequenceFinished.Broadcast(Zone, KineticJoules);
}
