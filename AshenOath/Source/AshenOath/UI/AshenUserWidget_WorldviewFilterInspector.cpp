// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_WorldviewFilterInspector.h"

void UAshenUserWidget_WorldviewFilterInspector::DisplayNodeWorldviewFilter(FName NodeID, FText KaelenLog, FText GarrettNote, FText SerafinaNote)
{
	InspectedNodeID = NodeID;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_WorldviewFilterInspector: Displayed multi-perspective worldview filter for node %s"), *InspectedNodeID.ToString());
}
