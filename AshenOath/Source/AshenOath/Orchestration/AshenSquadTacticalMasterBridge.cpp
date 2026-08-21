// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenSquadTacticalMasterBridge.h"

UAshenSquadTacticalMasterBridge::UAshenSquadTacticalMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSquadTacticalMasterBridge::BroadcastCoOpCombo(const FTemporalComboExecutionState& ComboState)
{
	OnCoOpComboTriggered.Broadcast(ComboState);
}
