// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenTripartiteResonanceMasterBridge.h"

UAshenTripartiteResonanceMasterBridge::UAshenTripartiteResonanceMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTripartiteResonanceMasterBridge::BroadcastComboPhaseChanged(const FTripartiteComboState& State)
{
	OnTripartiteComboPhaseChanged.Broadcast(State);
}

void UAshenTripartiteResonanceMasterBridge::BroadcastFinisherExecuted(EHarmonizedFinisherTier Tier, float TotalDamage)
{
	OnHarmonizedFinisherExecuted.Broadcast(Tier, TotalDamage);
}
