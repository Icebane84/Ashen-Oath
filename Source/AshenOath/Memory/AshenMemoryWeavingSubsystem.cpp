// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 315: Ashen Memory Weaving Subsystem

#include "AshenMemoryWeavingSubsystem.h"

void UAshenMemoryWeavingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CollectedThreads.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryWeavingSubsystem: Initialized — Memory Weaving Tapestry ONLINE."));
}

bool UAshenMemoryWeavingSubsystem::WeaveMemoryThread(FName MemoryID)
{
	if (MemoryID.IsNone()) return false;

	CollectedThreads.Add(MemoryID);
	OnMemoryThreadWoven.Broadcast(MemoryID, CollectedThreads.Num());

	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryWeavingSubsystem: MEMORY THREAD WOVEN — '%s' (Total Threads: %d)."),
		*MemoryID.ToString(), CollectedThreads.Num());

	return true;
}
