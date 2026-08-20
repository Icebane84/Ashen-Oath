// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 462: Ashen Diegetic Breathing HUD UMG Widget

#include "AshenUserWidget_DiegeticBreathingHUD.h"

void UAshenUserWidget_DiegeticBreathingHUD::UpdateBreathingHUDDisplay(float RateHz, float FatiguePercent, FName AudioBarkTag)
{
	DisplayedRateHz = RateHz;
	DisplayedFatiguePercent = FatiguePercent;
	DisplayedAudioBarkTag = AudioBarkTag;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DiegeticBreathingHUD: Diegetic Breathing HUD updated — Rate: %.2f Hz | Fatigue: %.1f%%."),
		RateHz, FatiguePercent * 100.0f);
}
