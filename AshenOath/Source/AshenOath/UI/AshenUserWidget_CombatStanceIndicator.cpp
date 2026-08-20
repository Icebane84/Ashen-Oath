// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 317: Ashen Combat Stance Indicator UMG Widget

#include "AshenUserWidget_CombatStanceIndicator.h"

void UAshenUserWidget_CombatStanceIndicator::UpdateStanceDisplay(EAshenCombatStance NewStance, float FrameSpeedMultiplier)
{
	ActiveStance = NewStance;
	ActiveFrameSpeedMultiplier = FrameSpeedMultiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CombatStanceIndicator: Combat stance HUD updated -> Stance %d (Speed: %.2fx)."),
		(int32)NewStance, FrameSpeedMultiplier);
}
