// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenWayfarerJournalSubsystem.h"

void UAshenWayfarerJournalSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenWayfarerJournalSubsystem: Wayfarer's Journal Subsystem initialized."));
}

void UAshenWayfarerJournalSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenWayfarerJournalSubsystem::RecordCampJournalEntry(FName EntryID, FText Location, FText KaelenText, FText GarrettNotes, FText SerafinaNotes, float GarrettTrust, float SerafinaTrust, float KaelenDebt)
{
	FAshenJournalEntry NewEntry;
	NewEntry.EntryID = EntryID;
	NewEntry.LocationHeader = Location;
	NewEntry.KaelenLedgerText = KaelenText;
	NewEntry.GarrettMarginaliaText = GarrettNotes;
	NewEntry.SerafinaMarginaliaText = SerafinaNotes;
	NewEntry.bGarrettHasStrikethrough = (GarrettTrust <= 0.35f);
	NewEntry.PageInkBleedIntensity = FMath::Clamp(KaelenDebt, 0.0f, 1.0f);

	DiscoveredEntries.Add(NewEntry);

	if (OnJournalEntryAdded.IsBound())
	{
		OnJournalEntryAdded.Broadcast(NewEntry);
	}

	const bool bGuardedFriction = (GarrettTrust <= 0.35f || SerafinaTrust <= 0.35f);
	if (OnJournalLayoutDistorted.IsBound())
	{
		OnJournalLayoutDistorted.Broadcast(bGuardedFriction);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenWayfarerJournalSubsystem: Journal Entry recorded: %s (Guarded Friction: %s, Ink Bleed: %.2f)"),
		*EntryID.ToString(), bGuardedFriction ? TEXT("TRUE") : TEXT("FALSE"), NewEntry.PageInkBleedIntensity);
}

FAshenJournalEntry UAshenWayfarerJournalSubsystem::GetLatestJournalEntry() const
{
	if (DiscoveredEntries.Num() > 0)
	{
		return DiscoveredEntries.Last();
	}
	return FAshenJournalEntry();
}
