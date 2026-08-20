// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenMemoryPalaceGraphSubsystem.h"

void UAshenMemoryPalaceGraphSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	NodeGraph.Empty();

	// Initialize Default Core Sanctuary Node
	FMemoryGraphNode CoreNode;
	CoreNode.NodeID = FName(TEXT("Node.Sanctuary.Core"));
	CoreNode.NodeType = EMemoryNodeType::CoreSanctuary;
	CoreNode.TraumaLevel = EMemoryTraumaLevel::Dormant;
	CoreNode.bIsUnsealed = true;
	CoreNode.bIsReconstructed = true;
	CoreNode.WorldPosition = FVector::ZeroVector;
	NodeGraph.Add(CoreNode.NodeID, CoreNode);

	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryPalaceGraphSubsystem: Memory Palace Graph Subsystem initialized with Core Sanctuary."));
}
void UAshenMemoryPalaceGraphSubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenMemoryPalaceGraphSubsystem::RegisterNode(const FMemoryGraphNode& InNode)
{
	if (InNode.NodeID.IsNone()) return false;
	NodeGraph.Add(InNode.NodeID, InNode);
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryPalaceGraphSubsystem: Registered Memory Node '%s' (Type: %d)."),
		*InNode.NodeID.ToString(), static_cast<int32>(InNode.NodeType));
	return true;
}

bool UAshenMemoryPalaceGraphSubsystem::UnsealNode(FName NodeID)
{
	FMemoryGraphNode* FoundNode = NodeGraph.Find(NodeID);
	if (!FoundNode) return false;

	FoundNode->bIsUnsealed = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryPalaceGraphSubsystem: Unsealed Memory Node '%s'!"), *NodeID.ToString());
	return true;
}

bool UAshenMemoryPalaceGraphSubsystem::ConnectNodes(FName SourceNodeID, FName TargetNodeID)
{
	FMemoryGraphNode* Source = NodeGraph.Find(SourceNodeID);
	FMemoryGraphNode* Target = NodeGraph.Find(TargetNodeID);
	if (!Source || !Target) return false;

	Source->ConnectedNodeIDs.AddUnique(TargetNodeID);
	Target->ConnectedNodeIDs.AddUnique(SourceNodeID);
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryPalaceGraphSubsystem: Connected Memory Nodes '%s' <-> '%s'."),
		*SourceNodeID.ToString(), *TargetNodeID.ToString());
	return true;
}

bool UAshenMemoryPalaceGraphSubsystem::GetNode(FName NodeID, FMemoryGraphNode& OutNode) const
{
	const FMemoryGraphNode* FoundNode = NodeGraph.Find(NodeID);
	if (!FoundNode) return false;
	OutNode = *FoundNode;
	return true;
}

int32 UAshenMemoryPalaceGraphSubsystem::GetUnsealedNodeCount() const
{
	int32 Count = 0;
	for (const auto& Pair : NodeGraph)
	{
		if (Pair.Value.bIsUnsealed) Count++;
	}
	return Count;
}
