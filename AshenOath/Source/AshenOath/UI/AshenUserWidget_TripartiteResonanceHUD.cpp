// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_TripartiteResonanceHUD.h"

UAshenUserWidget_TripartiteResonanceHUD::UAshenUserWidget_TripartiteResonanceHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedPhase = ETripartiteComboPhase::Inactive;
	DisplayedRemainingTime = 0.0f;
}

void UAshenUserWidget_TripartiteResonanceHUD::UpdateComboDisplay(const FTripartiteComboState& State)
{
	DisplayedPhase = State.CurrentPhase;
	DisplayedRemainingTime = State.RemainingWindowSeconds;
}
