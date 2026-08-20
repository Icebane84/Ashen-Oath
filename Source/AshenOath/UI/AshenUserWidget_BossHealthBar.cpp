// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenUserWidget_BossHealthBar.h"

void UAshenUserWidget_BossHealthBar::UpdateBossHealth(float CurrentHealth, float MaxHealth, int32 CurrentPhase)
{
	if (MaxHealth <= 0.0f) return;

	CurrentHealthPercent = FMath::Clamp(CurrentHealth / MaxHealth, 0.0f, 1.0f);
	CurrentBossPhase = CurrentPhase;

	OnBossHealthUpdated.Broadcast(CurrentHealthPercent, CurrentBossPhase);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_BossHealthBar: Boss health updated to %.1f pct (Phase %d)."),
		CurrentHealthPercent * 100.0f, CurrentBossPhase);
}

void UAshenUserWidget_BossHealthBar::DisplayBossName(const FText& BossName)
{
	CurrentBossName = BossName;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_BossHealthBar: Boss name set to '%s'."), *BossName.ToString());
}

void UAshenUserWidget_BossHealthBar::ShowPhaseTransitionBanner(int32 NewPhase)
{
	CurrentBossPhase = NewPhase;
	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_BossHealthBar: PHASE TRANSITION BANNER shown for Phase %d!"), NewPhase);
}
