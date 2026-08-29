// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_ExecutionerAdrenalineHUD.h"

UAshenUserWidget_ExecutionerAdrenalineHUD::UAshenUserWidget_ExecutionerAdrenalineHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedAdrenaline = 0.0f;
	bDisplayedHyperArmor = false;
	bDisplayedExecutionPrompt = false;
}

void UAshenUserWidget_ExecutionerAdrenalineHUD::UpdateAdrenalineHUD(
	float CurrentAdrenaline,
	float MaxAdrenaline,
	bool bHyperArmorActive,
	bool bExecutionPromptAvailable)
{
	DisplayedAdrenaline = (MaxAdrenaline > 0.0f) ? (CurrentAdrenaline / MaxAdrenaline) : 0.0f;
	bDisplayedHyperArmor = bHyperArmorActive;
	bDisplayedExecutionPrompt = bExecutionPromptAvailable;
}
