// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 424: Ashen Sanctuary Blessing Menu UMG Widget

#include "AshenUserWidget_SanctuaryBlessingMenu.h"

void UAshenUserWidget_SanctuaryBlessingMenu::UpdateBlessingMenuDisplay(FName BlessingID, float BuffMultiplier)
{
	DisplayedBlessingID = BlessingID;
	DisplayedBuffMultiplier = BuffMultiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SanctuaryBlessingMenu: Sanctuary Blessing Menu UI updated — '%s' (Buff: %.2fx)."),
		*BlessingID.ToString(), BuffMultiplier);
}
