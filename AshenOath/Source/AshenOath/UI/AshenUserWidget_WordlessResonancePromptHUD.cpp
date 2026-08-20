// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_WordlessResonancePromptHUD.h"

UAshenUserWidget_WordlessResonancePromptHUD::UAshenUserWidget_WordlessResonancePromptHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bActive = false;
	Intensity = 0.0f;
}

void UAshenUserWidget_WordlessResonancePromptHUD::TriggerResonancePulse(
	FName CompanionName,
	float PulseIntensity)
{
	ActiveCompanionName = CompanionName;
	Intensity = FMath::Clamp(PulseIntensity, 0.0f, 1.0f);
	bActive = true;
}
