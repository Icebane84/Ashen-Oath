// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 651: Ashen PRS Node Visualizer Anchor Actor

#include "AshenPRSNodeVisualizerAnchorActor.h"

AAshenPRSNodeVisualizerAnchorActor::AAshenPRSNodeVisualizerAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsVisualizing = false;
	TargetedPRSNodeID = FName(TEXT("char-kaelen"));
}

void AAshenPRSNodeVisualizerAnchorActor::RenderNodeConnections(FName NodeID, int32 ConnectedEdgeCount)
{
	TargetedPRSNodeID = NodeID;
	bIsVisualizing = true;
	OnNodeVisualized.Broadcast(TargetedPRSNodeID, ConnectedEdgeCount);

	UE_LOG(LogTemp, Warning, TEXT("AAshenPRSNodeVisualizerAnchorActor: NODE CONNECTIONS RENDERED -> Target Node '%s' | Edges: %d."),
		*TargetedPRSNodeID.ToString(), ConnectedEdgeCount);
}
