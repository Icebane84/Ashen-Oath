// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenLivingCodexSubsystem.h"

void UAshenLivingCodexSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CodexEntries.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingCodexSubsystem: Living Codex Subsystem initialized."));
}
void UAshenLivingCodexSubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenLivingCodexSubsystem::RegisterCodexEntry(const FCodexEntryData& Entry)
{
	if (Entry.EntryID.IsNone() || CodexEntries.Contains(Entry.EntryID)) return false;
	CodexEntries.Add(Entry.EntryID, Entry);
	return true;
}

bool UAshenLivingCodexSubsystem::UnlockCodexEntry(FName EntryID)
{
	FCodexEntryData* Found = CodexEntries.Find(EntryID);
	if (!Found || Found->bIsUnlocked) return false;

	Found->bIsUnlocked = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenLivingCodexSubsystem: UNLOCKED CODEX ENTRY '%s' (%s)!"),
		*EntryID.ToString(), *Found->Title);
	return true;
}

bool UAshenLivingCodexSubsystem::MarkEntryAsRead(FName EntryID)
{
	FCodexEntryData* Found = CodexEntries.Find(EntryID);
	if (!Found || !Found->bIsUnlocked) return false;

	Found->bHasBeenRead = true;
	return true;
}

int32 UAshenLivingCodexSubsystem::GetUnlockedCountForFaction(ECodexFaction Faction) const
{
	int32 Count = 0;
	for (const auto& Pair : CodexEntries)
	{
		if (Pair.Value.Faction == Faction && Pair.Value.bIsUnlocked)
		{
			Count++;
		}
	}
	return Count;
}

float UAshenLivingCodexSubsystem::CalculateCodexSanityReward() const
{
	// Grants +5.0 Max Sanity per unlocked faction category with at least 1 unlocked entry
	TSet<ECodexFaction> UnlockedFactions;
	for (const auto& Pair : CodexEntries)
	{
		if (Pair.Value.bIsUnlocked)
		{
			UnlockedFactions.Add(Pair.Value.Faction);
		}
	}
	const float Bonus = static_cast<float>(UnlockedFactions.Num()) * 5.0f;
	return Bonus;
}
