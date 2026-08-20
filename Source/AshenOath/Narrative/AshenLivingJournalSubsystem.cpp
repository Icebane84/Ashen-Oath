// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenLivingJournalSubsystem.h"

void UAshenLivingJournalSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	JournalEntries.Empty();
	UnlockedFramePerks.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingJournalSubsystem: Living Journal Subsystem initialized."));
}
void UAshenLivingJournalSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenLivingJournalSubsystem::RecordSomaticResolutionBeat(FName MonsterID, EJournalPerspectiveType Perspective)
{
	FJournalResolutionEntry Entry;
	Entry.BestiaryEntryID = MonsterID;
	Entry.Perspective = Perspective;

	if (Perspective == EJournalPerspectiveType::TripartiteSynarchy)
	{
		Entry.KaelenEntryText = TEXT("The basalt broke when the cold touched it. I didn't swing alone.");
		Entry.GarrettMarginNote = TEXT("Wedge goes here. Keep the iron cold next time, Kaelen.");
		Entry.SerafinaMarginNote = TEXT("We carried the heat together. The Flame did not burn us.");

		// Unlock permanent frame perk
		FTacticalFramePerkData Perk;
		Perk.MonsterArchetype = MonsterID;
		Perk.CalloutTimeAdvance = 1.0f;
		Perk.SunPulseHitboxExpansion = 1.35f;
		Perk.bIsPerkUnlocked = true;
		UnlockedFramePerks.Add(MonsterID, Perk);

		UE_LOG(LogTemp, Warning, TEXT("UAshenLivingJournalSubsystem: Synarchy Resolution recorded for '%s'! Unlocked Tactical Frame Perks."), *MonsterID.ToString());
	}
	else
	{
		Entry.KaelenEntryText = TEXT("I severed the brute. My hands are shaking. The stain is creeping past the elbow again.");
		Entry.GarrettMarginNote = TEXT("");
		Entry.SerafinaMarginNote = TEXT("[Dried tear water stain]");

		UE_LOG(LogTemp, Warning, TEXT("UAshenLivingJournalSubsystem: Solitary Martyrdom Resolution recorded for '%s'."), *MonsterID.ToString());
	}

	JournalEntries.Add(MonsterID, Entry);
}

bool UAshenLivingJournalSubsystem::HasTacticalFramePerk(FName MonsterArchetype) const
{
	const FTacticalFramePerkData* Perk = UnlockedFramePerks.Find(MonsterArchetype);
	return Perk && Perk->bIsPerkUnlocked;
}
