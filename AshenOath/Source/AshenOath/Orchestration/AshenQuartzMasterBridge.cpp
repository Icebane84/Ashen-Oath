// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenQuartzMasterBridge.h"

UAshenQuartzMasterBridge::UAshenQuartzMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenQuartzMasterBridge::BroadcastQuartzMatrix(const FQuartzStemMatrixState& NewState)
{
	OnStemMatrixBroadcaster.Broadcast(NewState);
}
