// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenForensicJournalSubsystem.h"

UAshenForensicJournalSubsystem::UAshenForensicJournalSubsystem()
{
}

void UAshenForensicJournalSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	JournalEntries.Empty();
}

void UAshenForensicJournalSubsystem::RecordScenarioEntry(
	int32 ScenarioIndex,
	const FString& Title,
	const FText& Summary,
	const FText& KaelenNote,
	const FText& GarrettNote,
	const FText& SerafinaNote,
	float Debt01,
	float SootMicrons)
{
	FForensicJournalEntry NewEntry;
	NewEntry.ScenarioIndex = ScenarioIndex;
	NewEntry.ScenarioTitle = Title;
	NewEntry.CanonicalSummary = Summary;
	NewEntry.KaelenMarginalia = KaelenNote;
	NewEntry.GarrettMarginalia = GarrettNote;
	NewEntry.SerafinaMarginalia = SerafinaNote;
	NewEntry.RecordedDebt01 = Debt01;
	NewEntry.RecordedSootMicrons = SootMicrons;
	NewEntry.bUnlocked = true;

	JournalEntries.Add(ScenarioIndex, NewEntry);
	OnJournalEntrySelected.Broadcast(ScenarioIndex, NewEntry);
}

bool UAshenForensicJournalSubsystem::GetJournalEntry(int32 ScenarioIndex, FForensicJournalEntry& OutEntry) const
{
	if (const FForensicJournalEntry* Found = JournalEntries.Find(ScenarioIndex))
	{
		OutEntry = *Found;
		return true;
	}
	return false;
}

int32 UAshenForensicJournalSubsystem::GetUnlockedEntriesCount() const
{
	int32 Count = 0;
	for (const auto& Pair : JournalEntries)
	{
		if (Pair.Value.bUnlocked)
		{
			Count++;
		}
	}
	return Count;
}
