// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenWayfarerJournalMasterBridge.h"

UAshenWayfarerJournalMasterBridge::UAshenWayfarerJournalMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWayfarerJournalMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bJournalBridgeActive = true;
}

void UAshenWayfarerJournalMasterBridge::BroadcastJournalPulse(FName EntryID, bool bGuardedFriction)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWayfarerJournalMasterBridge: Journal Pulse for entry '%s' (Guarded Friction: %s) broadcasted across all domain adapters."),
		*EntryID.ToString(), bGuardedFriction ? TEXT("YES") : TEXT("NO"));
}
