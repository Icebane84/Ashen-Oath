// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Archive/AshenCodexArchiveSubsystem.h"

UAshenCodexArchiveSubsystem::UAshenCodexArchiveSubsystem()
{
}

bool UAshenCodexArchiveSubsystem::UnlockCodexEntry(
	const FName& EntryId,
	ECodexCategory Category,
	const FText& Title,
	const FText& LoreText)
{
	if (EntryId.IsNone())
	{
		return false;
	}

	if (UnlockedEntries.Contains(EntryId))
	{
		return false; // Already unlocked
	}

	FCodexEntry NewEntry;
	NewEntry.EntryId = EntryId;
	NewEntry.Category = Category;
	NewEntry.Title = Title;
	NewEntry.LoreText = LoreText;
	NewEntry.bIsUnlocked = true;
	NewEntry.DiscoveryTimestamp = 0.0f;

	UnlockedEntries.Add(EntryId, NewEntry);
	OnCodexEntryUnlocked.Broadcast(EntryId, Category);
	return true;
}

bool UAshenCodexArchiveSubsystem::IsEntryUnlocked(const FName& EntryId) const
{
	return UnlockedEntries.Contains(EntryId);
}
