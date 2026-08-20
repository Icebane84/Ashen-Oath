// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_MemoryPalaceMapHUD.h"

void UAshenUserWidget_MemoryPalaceMapHUD::RefreshMapDisplay(int32 InNodes, int32 InBridges)
{
	TotalNodesDiscovered = InNodes;
	TotalBridgesRebuilt = InBridges;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MemoryPalaceMapHUD: Refreshed Constellation Map -> Nodes: %d, Bridges: %d"),
		TotalNodesDiscovered, TotalBridgesRebuilt);
}
