// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 454: Ashen Poise Break HUD UMG Widget

#include "AshenUserWidget_PoiseBreakHUD.h"

void UAshenUserWidget_PoiseBreakHUD::UpdatePoiseHUDDisplay(float CurrentPoise, float MaxPoise, bool bBroken)
{
	DisplayedPoisePercent = MaxPoise > 0.0f ? (CurrentPoise / MaxPoise) : 0.0f;
	bDisplayedIsBroken = bBroken;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PoiseBreakHUD: Poise HUD updated — Percent: %.1f%% (Broken: %s)."),
		DisplayedPoisePercent * 100.0f, bBroken ? TEXT("YES") : TEXT("NO"));
}
