// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 601: Ashen User Widget Memory Constellation Graph

#include "AshenUserWidget_MemoryConstellationGraph.h"

void UAshenUserWidget_MemoryConstellationGraph::InspectMemoryStar(FName MemoryNodeID, EAshenMemoryStarType StarType, FString CompanionPerspective)
{
	ActiveSelectedMemoryNodeID = MemoryNodeID;
	ActiveStarType = StarType;
	ActiveCompanionPerspectiveText = CompanionPerspective;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_MemoryConstellationGraph: MEMORY STAR INSPECTED -> '%s' (Type: %d | Companion Note: '%s')."),
		*MemoryNodeID.ToString(), static_cast<int32>(StarType), *ActiveCompanionPerspectiveText);
}
