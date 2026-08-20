// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenCanonicalPromiseMasterBridge.h"

UAshenCanonicalPromiseMasterBridge::UAshenCanonicalPromiseMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCanonicalPromiseMasterBridge::BroadcastPromiseRegistered(const FCanonicalPromiseRecord& Record)
{
	OnPromiseRegistered.Broadcast(Record);
}

void UAshenCanonicalPromiseMasterBridge::BroadcastPromiseCrisisReactivated(const FCanonicalPromiseRecord& Record)
{
	OnPromiseCrisisReactivated.Broadcast(Record);
}
