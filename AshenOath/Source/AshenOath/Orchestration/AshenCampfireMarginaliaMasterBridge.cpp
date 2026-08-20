// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenCampfireMarginaliaMasterBridge.h"

UAshenCampfireMarginaliaMasterBridge::UAshenCampfireMarginaliaMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCampfireMarginaliaMasterBridge::BroadcastMarginaliaBatch(const TArray<FMarginaliaEntry>& GeneratedEntries)
{
	OnMarginaliaBatchGenerated.Broadcast(GeneratedEntries);
}

void UAshenCampfireMarginaliaMasterBridge::BroadcastCrossoutApplied(const FString& TargetEntryId, const FString& ScratchOutText)
{
	OnMarginaliaCrossoutApplied.Broadcast(TargetEntryId, ScratchOutText);
}
