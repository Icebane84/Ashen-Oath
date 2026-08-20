// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 477: Ashen Boss Phase HUD UMG Widget

#include "AshenUserWidget_BossPhaseHUD.h"

void UAshenUserWidget_BossPhaseHUD::UpdateBossPhaseHUDDisplay(int32 PhaseIndex, float HealthPercent)
{
	DisplayedPhaseIndex = PhaseIndex;
	DisplayedHealthPercent = HealthPercent;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_BossPhaseHUD: Boss Phase HUD updated — Phase %d (Health: %.1f%%)."),
		PhaseIndex, HealthPercent * 100.0f);
}
