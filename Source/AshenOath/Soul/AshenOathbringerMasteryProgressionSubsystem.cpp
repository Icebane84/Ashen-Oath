// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 786: Ashen Oathbringer Mastery Progression Subsystem

#include "AshenOathbringerMasteryProgressionSubsystem.h"

void UAshenOathbringerMasteryProgressionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentMasteryLevel = 1;
	UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerMasteryProgressionSubsystem: Initialized — Oathbringer Mastery Progression Subsystem ONLINE."));
}

void UAshenOathbringerMasteryProgressionSubsystem::UnlockMasteryNode(FName NodeTag)
{
	CurrentMasteryLevel++;
	OnMasteryUnlocked.Broadcast(NodeTag, CurrentMasteryLevel);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerMasteryProgressionSubsystem: MASTERY UNLOCKED -> Node: '%s' | New Mastery Level: %d."),
		*NodeTag.ToString(), CurrentMasteryLevel);
}
