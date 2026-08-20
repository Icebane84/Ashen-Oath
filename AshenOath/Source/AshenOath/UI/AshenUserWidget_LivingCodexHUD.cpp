// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_LivingCodexHUD.h"

void UAshenUserWidget_LivingCodexHUD::SwitchFactionTab(ECodexFaction NewFaction, int32 UnlockedCount)
{
	ActiveFactionTab = NewFaction;
	DisplayedUnlockedCount = UnlockedCount;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_LivingCodexHUD: Switched Faction Tab -> %d (Unlocked Count: %d)"),
		static_cast<int32>(ActiveFactionTab), DisplayedUnlockedCount);
}
