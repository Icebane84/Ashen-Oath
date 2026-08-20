// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenTransferenceMasterBridge.h"

UAshenTransferenceMasterBridge::UAshenTransferenceMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTransferenceMasterBridge::BroadcastTransferenceAbsorbed(const FTransferenceBurdenSnapshot& Snapshot)
{
	OnTransferenceAbsorbed.Broadcast(Snapshot);
}

void UAshenTransferenceMasterBridge::BroadcastStaggerResolution(const FMercyExecutionEvaluationResult& Result)
{
	OnStaggerResolutionEvaluated.Broadcast(Result);
}
