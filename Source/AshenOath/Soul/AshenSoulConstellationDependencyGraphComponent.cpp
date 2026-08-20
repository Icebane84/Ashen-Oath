// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 513: Ashen Soul Constellation Dependency Graph Component

#include "AshenSoulConstellationDependencyGraphComponent.h"

UAshenSoulConstellationDependencyGraphComponent::UAshenSoulConstellationDependencyGraphComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalActiveGraphNodes = 12;
}

float UAshenSoulConstellationDependencyGraphComponent::EvaluateNodeDependencyWeight(FName NodeID, FName InterpretiveLensTag)
{
	if (NodeID.IsNone()) return 1.0f;

	const float Weight = (InterpretiveLensTag == FName(TEXT("Lens.Grace"))) ? 1.5f : 1.0f;
	OnNodeEvaluated.Broadcast(NodeID, Weight);

	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationDependencyGraphComponent: CONSTELLATION GRAPH EVALUATED -> Node '%s' Lens '%s' (Weight: %.2f)."),
		*NodeID.ToString(), *InterpretiveLensTag.ToString(), Weight);

	return Weight;
}
