// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 746: Ashen Memory Node Anchor Registry Subsystem

#include "AshenMemoryNodeAnchorRegistrySubsystem.h"

void UAshenMemoryNodeAnchorRegistrySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalRegisteredAnchors = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryNodeAnchorRegistrySubsystem: Initialized — Memory Node Anchor Registry Subsystem ONLINE."));
}

bool UAshenMemoryNodeAnchorRegistrySubsystem::RegisterMemoryAnchorNode(FName NodeID, FName LabelCategory)
{
	TotalRegisteredAnchors++;
	OnMemoryAnchorRegistered.Broadcast(NodeID, LabelCategory);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryNodeAnchorRegistrySubsystem: MEMORY ANCHOR REGISTERED -> Node ID: '%s' | Label: '%s' (Total Anchors: %d)."),
		*NodeID.ToString(), *LabelCategory.ToString(), TotalRegisteredAnchors);

	return true;
}
