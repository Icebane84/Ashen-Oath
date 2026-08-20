// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Narrative/AshenDiegeticJournalSubsystem.h"

void UAshenDiegeticJournalSubsystem::DispatchJournalEvent(const FJournalEvent& Event)
{
	JournalEventHistory.Add(Event);

	if (OnJournalEventDispatched.IsBound())
	{
		OnJournalEventDispatched.Broadcast(Event);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticJournalSubsystem: Dispatched journal event for node %s (%d perspectives)."), *Event.MemoryNodeID.ToString(), Event.Perspectives.Num());
}

void UAshenDiegeticJournalSubsystem::AppendJournalEntry(FName EntryTag, const FString& EntryContent)
{
	PermanentEntryTags.AddUnique(EntryTag);

	FJournalEvent Event;
	Event.MemoryNodeID = EntryTag;
	Event.CanonicalFactText = FText::FromString(EntryContent);
	DispatchJournalEvent(Event);
}

TArray<FJournalEvent> UAshenDiegeticJournalSubsystem::GetJournalHistoryForNode(FName MemoryNodeID) const
{
	TArray<FJournalEvent> MatchingEvents;
	for (const FJournalEvent& Event : JournalEventHistory)
	{
		if (Event.MemoryNodeID == MemoryNodeID)
		{
			MatchingEvents.Add(Event);
		}
	}
	return MatchingEvents;
}
