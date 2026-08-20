// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_MultiPhaseBossHUD.h"

void UAshenUserWidget_MultiPhaseBossHUD::UpdateBossHUD(const FBossEncounterPayload& InData)
{
	DisplayBossData = InData;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MultiPhaseBossHUD: Boss %s -> HP: %.1f/%.1f | Poise: %.1f/%.1f | Phase: %d"),
		*DisplayBossData.BossId.ToString(), DisplayBossData.CurrentHealth, DisplayBossData.MaxHealth,
		DisplayBossData.CurrentPoise, DisplayBossData.MaxPoise, static_cast<int32>(DisplayBossData.Phase));
}
