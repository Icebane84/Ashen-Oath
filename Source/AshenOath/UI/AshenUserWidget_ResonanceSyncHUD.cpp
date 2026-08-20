// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ResonanceSyncHUD.h"

void UAshenUserWidget_ResonanceSyncHUD::DisplayResonanceSync(bool bActive, float InDuration)
{
	bIsResonanceSyncActive = bActive;
	DurationRemaining = InDuration;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ResonanceSyncHUD: Resonance Sync HUD %s (Duration: %.1fs)."),
		bIsResonanceSyncActive ? TEXT("ACTIVE") : TEXT("OFF"), DurationRemaining);
}
