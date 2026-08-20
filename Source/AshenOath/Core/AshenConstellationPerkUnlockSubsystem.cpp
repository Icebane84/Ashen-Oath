// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 428: Ashen Constellation Perk Unlock Subsystem

#include "AshenConstellationPerkUnlockSubsystem.h"

void UAshenConstellationPerkUnlockSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UnlockedNodes.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenConstellationPerkUnlockSubsystem: Initialized — Constellation Perk Unlock Subsystem ONLINE."));
}

bool UAshenConstellationPerkUnlockSubsystem::UnlockConstellationPerkNode(FName NodeID)
{
	if (NodeID.IsNone()) return false;

	UnlockedNodes.Add(NodeID);
	OnPerkUnlocked.Broadcast(NodeID, UnlockedNodes.Num());

	UE_LOG(LogTemp, Warning, TEXT("UAshenConstellationPerkUnlockSubsystem: CONSTELLATION PERK UNLOCKED — '%s' (Total Nodes: %d)."),
		*NodeID.ToString(), UnlockedNodes.Num());

	return true;
}
