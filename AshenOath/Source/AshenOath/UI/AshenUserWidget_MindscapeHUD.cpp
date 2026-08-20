// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 472: Ashen Mindscape HUD UMG Widget

#include "AshenUserWidget_MindscapeHUD.h"

void UAshenUserWidget_MindscapeHUD::UpdateMindscapeHUDDisplay(FName MindscapeID, float DistortionIntensity)
{
	DisplayedMindscapeID = MindscapeID;
	DisplayedDistortionIntensity = DistortionIntensity;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MindscapeHUD: Mindscape HUD updated — Mindscape '%s' (Distortion: %.1f%%)."),
		*MindscapeID.ToString(), DistortionIntensity);
}
