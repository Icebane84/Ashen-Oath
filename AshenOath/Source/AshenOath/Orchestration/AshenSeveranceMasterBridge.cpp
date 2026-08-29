// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenSeveranceMasterBridge.h"

UAshenSeveranceMasterBridge::UAshenSeveranceMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSeveranceMasterBridge::BroadcastSeveranceExecution(
	const FSeveranceDismembermentResult& Result)
{
	OnSeveranceBroadcaster.Broadcast(Result);
}
