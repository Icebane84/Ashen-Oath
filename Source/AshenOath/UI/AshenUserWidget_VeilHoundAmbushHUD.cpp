// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 487: Ashen Veil Hound Ambush HUD UMG Widget

#include "AshenUserWidget_VeilHoundAmbushHUD.h"

void UAshenUserWidget_VeilHoundAmbushHUD::UpdateVeilHoundHUDDisplay(bool bStealthed, float PounceMultiplier)
{
	bDisplayedIsStealthed = bStealthed;
	DisplayedPounceMultiplier = PounceMultiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_VeilHoundAmbushHUD: Veil Hound Ambush HUD updated — Stealthed: %s (Multiplier: %.1fx)."),
		bStealthed ? TEXT("YES") : TEXT("NO"), PounceMultiplier);
}
