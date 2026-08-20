// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_WayfarersJournal.h"

void UAshenUserWidget_WayfarersJournal::DisplayJournalEntry(const FAshenJournalEntry& Entry, bool bGuardedFriction)
{
	ActiveDisplayedEntry = Entry;
	bIsGuardedFrictionActive = bGuardedFriction;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_WayfarersJournal: Displaying Entry '%s' | Guarded Friction: %s"),
		*ActiveDisplayedEntry.EntryID.ToString(), bIsGuardedFrictionActive ? TEXT("YES") : TEXT("NO"));
}

void UAshenUserWidget_WayfarersJournal::FlipPageNext()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_WayfarersJournal: Page flipped forward."));
}

void UAshenUserWidget_WayfarersJournal::FlipPagePrevious()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_WayfarersJournal: Page flipped backward."));
}
