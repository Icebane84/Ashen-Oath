// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 749: Ashen Memory Palace Traversal Priority Director

#include "AshenMemoryPalaceTraversalPriorityDirector.h"

FVector UAshenMemoryPalaceTraversalPriorityDirector::SelectNextConstellationNode(TArray<FVector> ConstellationNodes, FVector CurrentLocation)
{
	if (ConstellationNodes.Num() == 0) return CurrentLocation;

	const FVector NextNode = ConstellationNodes[0];
	const float SpeedMult = 1.25f; // 25% speed boost along constellation paths

	OnTraversalEvaluated.Broadcast(NextNode, SpeedMult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryPalaceTraversalPriorityDirector: CONSTELLATION TRAVERSAL SELECTED -> Next Node: (%s) | Speed Multiplier: %.2fx."),
		*NextNode.ToString(), SpeedMult);

	return NextNode;
}
