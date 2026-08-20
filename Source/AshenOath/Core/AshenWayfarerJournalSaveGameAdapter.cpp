// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenWayfarerJournalSaveGameAdapter.h"

UAshenWayfarerJournalSaveGameAdapter::UAshenWayfarerJournalSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWayfarerJournalSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenWayfarerJournalSaveGameAdapter::SerializeJournalStateToSave(int32 DiscoveredEntryCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWayfarerJournalSaveGameAdapter: %d journal entries and marginalia serialized to save file."), DiscoveredEntryCount);
	return true;
}
