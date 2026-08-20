// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 409: Ashen Regional Corruption Map UMG Widget

#include "AshenUserWidget_RegionalCorruptionMap.h"

void UAshenUserWidget_RegionalCorruptionMap::UpdateCorruptionMapDisplay(FName ZoneID, float CorruptionPercentage)
{
	DisplayedZoneID = ZoneID;
	DisplayedCorruptionPercentage = CorruptionPercentage;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_RegionalCorruptionMap: Regional Corruption Map UI updated — Zone '%s' (Corruption: %.1f%%)."),
		*ZoneID.ToString(), CorruptionPercentage);
}
