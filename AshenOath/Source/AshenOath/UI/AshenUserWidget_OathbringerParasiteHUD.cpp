// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_OathbringerParasiteHUD.h"

UAshenUserWidget_OathbringerParasiteHUD::UAshenUserWidget_OathbringerParasiteHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedCorruption = 0.15f;
	DisplayedMassKg = 45.0f;
	DisplayedPlayRate = 1.0f;
	DisplayedState = EBladeParasiteState::DormantSteel;
	bDisplayedFrozen = false;
	DisplayedFreezeTime = 0.0f;
}

void UAshenUserWidget_OathbringerParasiteHUD::UpdateBladeHUD(
	float Corruption01,
	float BladeMassKg,
	float SwingPlayRate,
	EBladeParasiteState State,
	bool bFrozen,
	float FreezeTimeRemaining)
{
	DisplayedCorruption = Corruption01;
	DisplayedMassKg = BladeMassKg;
	DisplayedPlayRate = SwingPlayRate;
	DisplayedState = State;
	bDisplayedFrozen = bFrozen;
	DisplayedFreezeTime = FreezeTimeRemaining;
}
