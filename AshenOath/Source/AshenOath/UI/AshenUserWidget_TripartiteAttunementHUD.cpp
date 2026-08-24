// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_TripartiteAttunementHUD.h"

UAshenUserWidget_TripartiteAttunementHUD::UAshenUserWidget_TripartiteAttunementHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedMode = ETripartiteBehaviorMode::CombatEngagement;
	DisplayedPhase = ECompanionAttunementPhase::GuardedAlignment;
	DisplayedAttunementScore = 0.50f;
	DisplayedFlankAngle = 90.0f;
	DisplayedSerafinaDistance = 450.0f;
}

void UAshenUserWidget_TripartiteAttunementHUD::UpdateTripartiteHUD(
	ETripartiteBehaviorMode Mode,
	ECompanionAttunementPhase Phase,
	float AttunementScore,
	float GarrettFlankAngle,
	float SerafinaDist)
{
	DisplayedMode = Mode;
	DisplayedPhase = Phase;
	DisplayedAttunementScore = AttunementScore;
	DisplayedFlankAngle = GarrettFlankAngle;
	DisplayedSerafinaDistance = SerafinaDist;
}
