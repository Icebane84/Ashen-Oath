// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 403: Ashen Memory Thread Sanctuary Subsystem

#include "AshenMemoryThreadSanctuarySubsystem.h"

void UAshenMemoryThreadSanctuarySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CollectedThreads.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryThreadSanctuarySubsystem: Initialized — Memory Thread Sanctuary Archive ONLINE."));
}

bool UAshenMemoryThreadSanctuarySubsystem::CollectMemoryThread(FName ThreadID)
{
	if (ThreadID.IsNone()) return false;

	CollectedThreads.Add(ThreadID);
	OnMemoryThreadCollected.Broadcast(ThreadID, CollectedThreads.Num());

	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryThreadSanctuarySubsystem: MEMORY THREAD COLLECTED — '%s' (Total Archived: %d)."),
		*ThreadID.ToString(), CollectedThreads.Num());

	return true;
}
