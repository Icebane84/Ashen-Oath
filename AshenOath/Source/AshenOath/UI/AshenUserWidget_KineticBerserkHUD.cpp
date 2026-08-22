// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_KineticBerserkHUD.h"

UAshenUserWidget_KineticBerserkHUD::UAshenUserWidget_KineticBerserkHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedCounterZone = EAshenCounterAttackZone::VerticalOverhead;
	DisplayedAngleDegrees = 0.0f;
	DisplayedCutoffFrequency = 20000.0f;
	DisplayedKineticJoules = 4500.0f;
}

void UAshenUserWidget_KineticBerserkHUD::UpdateKineticDiagnostics(
	EAshenCounterAttackZone CounterZone,
	float CounterAngleDegrees,
	float DebrisCutoffFrequency,
	float KineticJoules)
{
	DisplayedCounterZone = CounterZone;
	DisplayedAngleDegrees = CounterAngleDegrees;
	DisplayedCutoffFrequency = DebrisCutoffFrequency;
	DisplayedKineticJoules = KineticJoules;
}
