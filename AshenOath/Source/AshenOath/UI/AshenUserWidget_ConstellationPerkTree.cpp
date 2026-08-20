// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 429: Ashen Constellation Perk Tree UMG Widget

#include "AshenUserWidget_ConstellationPerkTree.h"

void UAshenUserWidget_ConstellationPerkTree::UpdateConstellationTreeDisplay(FName NodeID, int32 TotalUnlockedNodes)
{
	DisplayedNodeID = NodeID;
	TotalActiveNodes = TotalUnlockedNodes;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ConstellationPerkTree: Constellation Perk Tree UI updated — '%s' (Total Active Nodes: %d)."),
		*NodeID.ToString(), TotalUnlockedNodes);
}
