// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 201: Ashen Fast Travel Map Widget

#include "AshenFastTravelMapWidget.h"

void UAshenFastTravelMapWidget::PopulateSanctuaryNodes(const TArray<FName>& UnlockedSanctuaries)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenFastTravelMapWidget: Populated %d unlocked fast travel nodes."), UnlockedSanctuaries.Num());
}

void UAshenFastTravelMapWidget::SelectSanctuaryNode(FName SanctuaryID)
{
	SelectedSanctuaryID = SanctuaryID;
	OnNodeSelected.Broadcast(SelectedSanctuaryID);
	UE_LOG(LogTemp, Warning, TEXT("UAshenFastTravelMapWidget: Fast travel node '%s' SELECTED."), *SanctuaryID.ToString());
}
