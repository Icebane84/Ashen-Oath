// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 308: Ashen False Confidence HUD UMG Widget (UMB-SYS-005)

#include "AshenUserWidget_FalseConfidenceHUD.h"

void UAshenUserWidget_FalseConfidenceHUD::SetFalseConfidenceDeceptionState(bool bInDeceptionActive, float Intensity)
{
	bDeceptionOverlayActive = bInDeceptionActive;
	DeceptionOverlayIntensity = Intensity;

	if (bInDeceptionActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_FalseConfidenceHUD: FALSE CONFIDENCE DECEPTIVE HUD ACTIVE — Sharpened Viewport, Intensity: %.2f."), Intensity);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_FalseConfidenceHUD: False confidence deceptive HUD deactivated."));
	}
}
