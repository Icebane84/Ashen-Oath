// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 349: Ashen Geopolitical Faction Standing UMG Widget

#include "AshenUserWidget_GeopoliticalFactionStanding.h"

void UAshenUserWidget_GeopoliticalFactionStanding::UpdateFactionStandingDisplay(FName FactionID, float FactionStanding)
{
	DisplayedFactionID = FactionID;
	DisplayedStanding = FactionStanding;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_GeopoliticalFactionStanding: Faction Standing UI updated — '%s' (Standing: %.1f)."),
		*FactionID.ToString(), FactionStanding);
}
