// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenBossEncounterMasterBridge.h"

UAshenBossEncounterMasterBridge::UAshenBossEncounterMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenBossEncounterMasterBridge::BroadcastPhaseShifted(EBossEncounterPhase NewPhase)
{
	OnBossPhaseShifted.Broadcast(NewPhase);
}

void UAshenBossEncounterMasterBridge::BroadcastCrisisTriggered(const FCompanionCrisisContext& Context)
{
	OnCompanionCrisisTriggered.Broadcast(Context);
}
