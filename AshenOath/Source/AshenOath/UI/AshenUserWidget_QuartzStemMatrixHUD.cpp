// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_QuartzStemMatrixHUD.h"

UAshenUserWidget_QuartzStemMatrixHUD::UAshenUserWidget_QuartzStemMatrixHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedMatrixState.MasterBPM = 115.0f;
	DisplayedMatrixState.FlowState = ECombatFlowState::StandardTrioBaseline;
	DisplayedMatrixState.ActiveFilter = EAlchemicalAudioFilter::None;
}

void UAshenUserWidget_QuartzStemMatrixHUD::UpdateStemMatrixHUD(const FQuartzStemMatrixState& State)
{
	DisplayedMatrixState = State;
}
