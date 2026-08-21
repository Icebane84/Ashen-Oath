// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_BossEncounterDynamicHUD.h"

UAshenUserWidget_BossEncounterDynamicHUD::UAshenUserWidget_BossEncounterDynamicHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedPhase = EBossEncounterPhase::Phase1_Guardian;
	DisplayedHealthPercent = 1.0f;
	bCrisisAlertVisible = false;
}

void UAshenUserWidget_BossEncounterDynamicHUD::UpdateBossDisplay(const FBossArenaState& State)
{
	DisplayedPhase = State.CurrentPhase;
	DisplayedHealthPercent = State.BossHealthPercent;
}

void UAshenUserWidget_BossEncounterDynamicHUD::UpdateCrisisDisplay(const FCompanionCrisisContext& Context)
{
	bCrisisAlertVisible = (Context.CrisisState == ECompanionCrisisState::PinnedInExecution);
}
