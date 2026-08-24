// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenJournalMasterBridge.h"

UAshenJournalMasterBridge::UAshenJournalMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenJournalMasterBridge::BroadcastEntrySelection(
	int32 ScenarioIndex,
	const FForensicJournalEntry& Entry)
{
	OnEntrySelectionBroadcaster.Broadcast(ScenarioIndex, Entry);
}
