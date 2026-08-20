// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 646: Ashen Canonical Status Deprecation Protocol

#include "AshenCanonicalStatusDeprecationProtocol.h"

void UAshenCanonicalStatusDeprecationProtocol::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalDeprecatedNodesCount = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenCanonicalStatusDeprecationProtocol: Initialized — Canonical Status Deprecation Protocol ONLINE."));
}

void UAshenCanonicalStatusDeprecationProtocol::DeprecateNodeNonDestructively(FName DeprecatedNodeID, FName SupersedingNodeID)
{
	if (DeprecatedNodeID.IsNone()) return;

	TotalDeprecatedNodesCount++;
	const bool bShadowVersioned = true;
	OnNodeDeprecated.Broadcast(DeprecatedNodeID, SupersedingNodeID, bShadowVersioned);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCanonicalStatusDeprecationProtocol: NON-DESTRUCTIVE DEPRECATION -> Node '%s' DEPRECATED and SUPERSEDED BY '%s' (Total Deprecated: %d)."),
		*DeprecatedNodeID.ToString(), *SupersedingNodeID.ToString(), TotalDeprecatedNodesCount);
}
