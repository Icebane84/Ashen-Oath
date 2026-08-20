// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_DiegeticFieldJournal.h"

void UAshenUserWidget_DiegeticFieldJournal::RenderJournalEvent(const FJournalEvent& Event)
{
	DisplayedJournalEvent = Event;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DiegeticFieldJournal: Rendered journal event %s (%d perspectives)."), *Event.MemoryNodeID.ToString(), Event.Perspectives.Num());
}
