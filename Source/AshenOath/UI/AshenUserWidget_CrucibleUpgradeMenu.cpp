// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 451: Ashen Crucible Upgrade Menu UMG Widget

#include "AshenUserWidget_CrucibleUpgradeMenu.h"

void UAshenUserWidget_CrucibleUpgradeMenu::UpdateCrucibleMenuDisplay(int32 CurrentTier, float GlobalMultiplier)
{
	DisplayedTier = CurrentTier;
	DisplayedGlobalMultiplier = GlobalMultiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CrucibleUpgradeMenu: Crucible Upgrade Menu UI updated — Tier %d (Multiplier: %.2fx)."),
		CurrentTier, GlobalMultiplier);
}
