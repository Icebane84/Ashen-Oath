// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_InterruptedStrugglePromptHUD.h"

UAshenUserWidget_InterruptedStrugglePromptHUD::UAshenUserWidget_InterruptedStrugglePromptHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	HesitationText = FText::FromString(TEXT("I—"));
	HesitationOpacity = 0.0f;
	bPromptVisible = false;
}

void UAshenUserWidget_InterruptedStrugglePromptHUD::TriggerInterruptedPrompt(float PartialCompletionRatio, float DisplayDuration)
{
	bPromptVisible = true;
	HesitationOpacity = 1.0f;
}

void UAshenUserWidget_InterruptedStrugglePromptHUD::DismissPrompt()
{
	bPromptVisible = false;
	HesitationOpacity = 0.0f;
}
