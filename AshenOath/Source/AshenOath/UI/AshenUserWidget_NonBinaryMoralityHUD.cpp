// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 438: Ashen Non-Binary Morality HUD UMG Widget

#include "AshenUserWidget_NonBinaryMoralityHUD.h"

void UAshenUserWidget_NonBinaryMoralityHUD::UpdateMoralityHUDDisplay(EAshenMoralDisposition Disposition, float Magnitude)
{
	DisplayedDisposition = Disposition;
	DisplayedMagnitude = Magnitude;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_NonBinaryMoralityHUD: Morality HUD updated — Disposition %d (Magnitude: %.1f)."),
		(int32)Disposition, Magnitude);
}
