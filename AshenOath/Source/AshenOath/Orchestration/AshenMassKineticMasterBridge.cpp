// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenMassKineticMasterBridge.h"

UAshenMassKineticMasterBridge::UAshenMassKineticMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMassKineticMasterBridge::BroadcastKineticSwing(const FKineticSwingSnapshot& Snapshot)
{
	OnKineticSwingCalculated.Broadcast(Snapshot);
}

void UAshenMassKineticMasterBridge::BroadcastVolumeDrag(const FVolumeDragResult& Result)
{
	OnVolumeDragUpdated.Broadcast(Result);
}
