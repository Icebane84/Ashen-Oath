// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_RunicReliquaryForgeHUD.h"

UAshenUserWidget_RunicReliquaryForgeHUD::UAshenUserWidget_RunicReliquaryForgeHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedMassKg = 120.0f;
	DisplayedPoiseMultiplier = 1.0f;
	DisplayedSocketCount = 0;
}

void UAshenUserWidget_RunicReliquaryForgeHUD::UpdateForgeDisplay(const FSoulForgeWeaponState& State)
{
	DisplayedMassKg = State.EffectiveMassKg;
	DisplayedPoiseMultiplier = State.TotalPoiseMultiplier;
	DisplayedSocketCount = State.ActiveSocketCount;
}
