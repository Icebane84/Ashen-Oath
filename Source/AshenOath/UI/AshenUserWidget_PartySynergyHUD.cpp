// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 459: Ashen Party Synergy HUD UMG Widget

#include "AshenUserWidget_PartySynergyHUD.h"

void UAshenUserWidget_PartySynergyHUD::UpdatePartySynergyHUDDisplay(float SynergyMultiplier, int32 CompanionsInProximity)
{
	DisplayedSynergyMultiplier = SynergyMultiplier;
	DisplayedCompanionCount = CompanionsInProximity;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PartySynergyHUD: Party Synergy HUD updated — Multiplier: %.2fx (%d Companions Nearby)."),
		SynergyMultiplier, CompanionsInProximity);
}
