// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 358: Ashen Remnant Chronicles Subsystem

#include "AshenRemnantChroniclesSubsystem.h"

void UAshenRemnantChroniclesSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UnlockedChronicles.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenRemnantChroniclesSubsystem: Initialized — Remnant Chronicles Archive ONLINE."));
}

bool UAshenRemnantChroniclesSubsystem::UnlockChronicleEntry(FName ChronicleID)
{
	if (ChronicleID.IsNone()) return false;

	UnlockedChronicles.Add(ChronicleID);
	OnChronicleEntryUnlocked.Broadcast(ChronicleID, UnlockedChronicles.Num());

	UE_LOG(LogTemp, Warning, TEXT("UAshenRemnantChroniclesSubsystem: REMNANT CHRONICLE UNLOCKED — '%s' (Total Archived: %d)."),
		*ChronicleID.ToString(), UnlockedChronicles.Num());

	return true;
}
