// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 386: Ashen Tactical Targeting HUD UMG Widget

#include "AshenUserWidget_TacticalTargetingHUD.h"

void UAshenUserWidget_TacticalTargetingHUD::UpdateTargetingDisplay(FName BoneName, float CritMultiplier)
{
	DisplayedBoneName = BoneName;
	DisplayedCritMultiplier = CritMultiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TacticalTargetingHUD: Tactical Targeting HUD updated — Bone '%s' (Crit: %.2fx)."),
		*BoneName.ToString(), CritMultiplier);
}
