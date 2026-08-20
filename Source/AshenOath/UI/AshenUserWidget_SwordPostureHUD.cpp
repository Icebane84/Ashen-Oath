// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 492: Ashen Sword Posture HUD UMG Widget

#include "AshenUserWidget_SwordPostureHUD.h"

void UAshenUserWidget_SwordPostureHUD::UpdateSwordPostureHUDDisplay(FName StanceTag, float ParryMultiplier)
{
	DisplayedStanceTag = StanceTag;
	DisplayedParryMultiplier = ParryMultiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SwordPostureHUD: Sword Posture HUD updated — Stance '%s' (Parry Multiplier: %.2fx)."),
		*StanceTag.ToString(), ParryMultiplier);
}
