// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenUserWidget_ConstellationNode.h"

bool UAshenUserWidget_ConstellationNode::AttemptUnlock(float AvailableEmbers)
{
	if (bIsUnlocked || !bCanUnlock || AvailableEmbers < EmberCost)
	{
		return false;
	}

	bIsUnlocked = true;
	bCanUnlock = false;

	OnNodeStateUpdated(bIsUnlocked, bCanUnlock);
	OnNodeUnlocked.Broadcast(NodeId);

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_ConstellationNode: Node '%s' unlocked for %.0f Embers!"), *NodeId.ToString(), EmberCost);
	return true;
}
