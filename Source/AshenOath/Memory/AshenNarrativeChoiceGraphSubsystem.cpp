// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 446: Ashen Narrative Choice Graph Subsystem

#include "AshenNarrativeChoiceGraphSubsystem.h"

void UAshenNarrativeChoiceGraphSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ChoiceHistory.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenNarrativeChoiceGraphSubsystem: Initialized — Narrative Choice Graph ONLINE."));
}

bool UAshenNarrativeChoiceGraphSubsystem::CommitNarrativeChoice(FName NodeID, int32 ChoiceIndex)
{
	if (NodeID.IsNone()) return false;

	ChoiceHistory.Add(NodeID, ChoiceIndex);
	OnChoiceCommitted.Broadcast(NodeID, ChoiceIndex);

	UE_LOG(LogTemp, Warning, TEXT("UAshenNarrativeChoiceGraphSubsystem: NARRATIVE CHOICE COMMITTED — Node '%s' -> Option [%d]."),
		*NodeID.ToString(), ChoiceIndex);

	return true;
}
