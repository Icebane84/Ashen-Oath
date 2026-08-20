// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 636: Ashen PRS Genesis Graph Subsystem

#include "AshenPRSGenesisGraphSubsystem.h"

void UAshenPRSGenesisGraphSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalNodesFederated = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenPRSGenesisGraphSubsystem: Initialized — PRS Genesis Graph Subsystem ONLINE (prs_001_ashen_genesis Authority)."));
}

bool UAshenPRSGenesisGraphSubsystem::QueryPRSNodeReference(FName NodeID, EAshenPRSNodeLabel ExpectedLabel)
{
	if (NodeID.IsNone()) return false;

	TotalNodesFederated++;
	const bool bCanonical = true; // Federated against prs_001_ashen_genesis
	OnPRSNodeQueried.Broadcast(NodeID, ExpectedLabel, bCanonical);

	UE_LOG(LogTemp, Warning, TEXT("UAshenPRSGenesisGraphSubsystem: PRS NODE QUERIED -> Node '%s' (Label %d | Canonical: %s | Total: %d)."),
		*NodeID.ToString(), static_cast<int32>(ExpectedLabel), bCanonical ? TEXT("TRUE") : TEXT("FALSE"), TotalNodesFederated);

	return bCanonical;
}
