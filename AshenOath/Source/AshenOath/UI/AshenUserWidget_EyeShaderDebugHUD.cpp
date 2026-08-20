// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 497: Ashen Eye Shader Debug HUD UMG Widget

#include "AshenUserWidget_EyeShaderDebugHUD.h"

void UAshenUserWidget_EyeShaderDebugHUD::UpdateEyeShaderHUDDisplay(float Intensity, FLinearColor Color)
{
	DisplayedEmissiveIntensity = Intensity;
	DisplayedEyeGlowColor = Color;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_EyeShaderDebugHUD: Eye Shader HUD updated — Emissive Intensity: %.1f."), Intensity);
}
