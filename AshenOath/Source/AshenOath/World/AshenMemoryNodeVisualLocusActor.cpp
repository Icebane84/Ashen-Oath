// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 752: Ashen Memory Node Visual Locus Actor

#include "AshenMemoryNodeVisualLocusActor.h"

AAshenMemoryNodeVisualLocusActor::AAshenMemoryNodeVisualLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsNodeStabilized = false;
}

void AAshenMemoryNodeVisualLocusActor::SetMemoryNodeState(FName NodeID, bool bStabilized)
{
	ActiveBoundNodeID = NodeID;
	bIsNodeStabilized = bStabilized;
	OnMemoryNodeLocusUpdated.Broadcast(ActiveBoundNodeID, bIsNodeStabilized);

	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryNodeVisualLocusActor: MEMORY NODE LOCUS STATE UPDATED -> Node ID: '%s' | Stabilized: %s."),
		*ActiveBoundNodeID.ToString(), bIsNodeStabilized ? TEXT("TRUE") : TEXT("FALSE"));
}
