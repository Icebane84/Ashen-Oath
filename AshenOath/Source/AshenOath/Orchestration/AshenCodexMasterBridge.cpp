// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenCodexMasterBridge.h"

UAshenCodexMasterBridge::UAshenCodexMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCodexMasterBridge::BroadcastCodexVisibility(bool bIsVisible)
{
	OnCodexRepositoryVisibilityChanged.Broadcast(bIsVisible);
}
