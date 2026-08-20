// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 522: Ashen Armor Scuff Debug HUD UMG Widget

#include "AshenUserWidget_ArmorScuffDebugHUD.h"

void UAshenUserWidget_ArmorScuffDebugHUD::UpdateArmorScuffHUDDisplay(float SeverityPercent)
{
	DisplayedSeverityPercent = SeverityPercent;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ArmorScuffDebugHUD: Armor Scuff HUD updated — Severity: %.1f%%."), SeverityPercent);
}
