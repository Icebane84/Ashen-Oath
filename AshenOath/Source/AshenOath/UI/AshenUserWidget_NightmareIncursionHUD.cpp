// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_NightmareIncursionHUD.h"

void UAshenUserWidget_NightmareIncursionHUD::UpdateIncursionDisplay(float InIntensity, float InStability)
{
	DisplayedIncursionIntensity = FMath::Clamp(InIntensity, 0.0f, 1.0f);
	RealityStabilityPercent = FMath::Clamp(InStability * 100.0f, 0.0f, 100.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_NightmareIncursionHUD: Incursion HUD -> Intensity: %.1f%%, Stability: %.1f%%"),
		DisplayedIncursionIntensity * 100.0f, RealityStabilityPercent);
}
