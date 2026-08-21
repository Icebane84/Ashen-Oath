// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_OakhavenEncounterHUD.h"

UAshenUserWidget_OakhavenEncounterHUD::UAshenUserWidget_OakhavenEncounterHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedBossHealth = 1.0f;
	DisplayedRitualProgress = 0.0f;
	DisplayedIntegrationDebt = 0.0f;
}

void UAshenUserWidget_OakhavenEncounterHUD::UpdateHUDState(
	float BossHealthPercent,
	float RitualProgressPercent,
	float CurrentDebt)
{
	DisplayedBossHealth = BossHealthPercent;
	DisplayedRitualProgress = RitualProgressPercent;
	DisplayedIntegrationDebt = CurrentDebt;
}
