// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_BrotherMalakorBossBar.h"

void UAshenUserWidget_BrotherMalakorBossBar::UpdateBossHealthHUD(float HealthPercent, int32 PhaseIndex)
{
	BossHealthRatio = FMath::Clamp(HealthPercent, 0.0f, 1.0f);
	ActivePhaseIndex = PhaseIndex;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_BrotherMalakorBossBar: Health: %.1f%% | Phase: %d"),
		BossHealthRatio * 100.0f, ActivePhaseIndex);
}
