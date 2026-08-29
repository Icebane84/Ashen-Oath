// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_OathbringerStanceMatrixHUD.h"

UAshenUserWidget_OathbringerStanceMatrixHUD::UAshenUserWidget_OathbringerStanceMatrixHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedStance = EOathbringerMartialStance::VomTag_HighWrath;
	DisplayedSeamColor = FLinearColor(1.0f, 0.15f, 0.05f, 1.0f);
	DisplayedFlowCharge = 0.0f;
	bDisplayedFlowGlint = false;
}

void UAshenUserWidget_OathbringerStanceMatrixHUD::UpdateStanceHUD(
	EOathbringerMartialStance ActiveStance,
	FLinearColor SeamColor,
	float FlowCharge,
	bool bFlowGlintActive)
{
	DisplayedStance = ActiveStance;
	DisplayedSeamColor = SeamColor;
	DisplayedFlowCharge = FlowCharge;
	bDisplayedFlowGlint = bFlowGlintActive;
}
