// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenShroudKnightMasterBridge.h"

UAshenShroudKnightMasterBridge::UAshenShroudKnightMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenShroudKnightMasterBridge::BroadcastBossState(const FShroudKnightBossVector& NewState)
{
	OnParanoiaBroadcaster.Broadcast(NewState.ParanoiaInfection01, NewState.ParanoiaTier);
}
