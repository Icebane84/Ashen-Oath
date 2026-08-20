// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 379: Ashen Sanctuary Restoration Menu UMG Widget

#include "AshenUserWidget_SanctuaryRestorationMenu.h"

void UAshenUserWidget_SanctuaryRestorationMenu::UpdateSanctuaryRestorationDisplay(FName SanctuaryID, int32 ActiveSanctuaries)
{
	DisplayedSanctuaryID = SanctuaryID;
	TotalActiveSanctuariesCount = ActiveSanctuaries;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SanctuaryRestorationMenu: Sanctuary Restoration UI updated — '%s' (Total Active: %d)."),
		*SanctuaryID.ToString(), ActiveSanctuaries);
}
