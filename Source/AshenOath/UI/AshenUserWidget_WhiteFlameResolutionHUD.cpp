// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_WhiteFlameResolutionHUD.h"

void UAshenUserWidget_WhiteFlameResolutionHUD::UpdateWhiteFlameDisplay(const FWhiteFlameResolutionPayload& InPayload)
{
	DisplayPayload = InPayload;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_WhiteFlameResolutionHUD: White Flame Duration: %.1fs | Eradicated Debt: %.1f"),
		DisplayPayload.DurationRemainingSeconds, DisplayPayload.EradicatedDebtAmount);
}
