// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 507: Ashen Peak Resonance HUD UMG Widget

#include "AshenUserWidget_PeakResonanceHUD.h"

void UAshenUserWidget_PeakResonanceHUD::UpdatePeakResonanceHUDDisplay(bool bPeakActive, float Multiplier)
{
	bDisplayedPeakActive = bPeakActive;
	DisplayedMultiplier = Multiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PeakResonanceHUD: Peak Resonance HUD updated — Active: %s (Multiplier: %.1fx)."),
		bPeakActive ? TEXT("YES") : TEXT("NO"), Multiplier);
}
