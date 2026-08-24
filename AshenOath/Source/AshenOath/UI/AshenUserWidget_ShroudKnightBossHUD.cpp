// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_ShroudKnightBossHUD.h"

UAshenUserWidget_ShroudKnightBossHUD::UAshenUserWidget_ShroudKnightBossHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedBossVector.HealthPercent = 1.0f;
	DisplayedBossVector.ParanoiaInfection01 = 0.10f;
	DisplayedBossVector.DitherOpacity = 1.0f;
	DisplayedBossVector.PhaseState = EShroudKnightPhaseState::PhysicalSolid;
	DisplayedBossVector.ParanoiaTier = EParanoiaInfectionTier::ClearMind;
	DisplayedBossVector.TrinityStep = ETrinityStrikeStep::None;
}

void UAshenUserWidget_ShroudKnightBossHUD::UpdateBossHUD(const FShroudKnightBossVector& BossVector)
{
	DisplayedBossVector = BossVector;
}
