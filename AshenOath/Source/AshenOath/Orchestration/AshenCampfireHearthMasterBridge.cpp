// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenCampfireHearthMasterBridge.h"

UAshenCampfireHearthMasterBridge::UAshenCampfireHearthMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCampfireHearthMasterBridge::BroadcastRestStarted(const FCampfireIntegrationSnapshot& Snapshot)
{
	OnCampfireRestStarted.Broadcast(Snapshot);
}

void UAshenCampfireHearthMasterBridge::BroadcastTraumaTransmuted(const FString& TraitId, float BonusValue)
{
	OnTraumaTransmuted.Broadcast(TraitId, BonusValue);
}
