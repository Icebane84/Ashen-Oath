// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 406: Ashen Memory Thread Journal UMG Widget

#include "AshenUserWidget_MemoryThreadJournal.h"

void UAshenUserWidget_MemoryThreadJournal::UpdateJournalDisplay(FName ThreadID, int32 TotalCollectedThreads)
{
	DisplayedThreadID = ThreadID;
	TotalCollected = TotalCollectedThreads;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MemoryThreadJournal: Memory Thread Journal UI updated — '%s' (Total Collected: %d)."),
		*ThreadID.ToString(), TotalCollectedThreads);
}
