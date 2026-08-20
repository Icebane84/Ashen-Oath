// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_CostlyPresencePromptHUD.h"

UAshenUserWidget_CostlyPresencePromptHUD::UAshenUserWidget_CostlyPresencePromptHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NotificationOpacity = 0.0f;
	bActive = false;
}

void UAshenUserWidget_CostlyPresencePromptHUD::TriggerInterceptNotification(
	FName CompanionName,
	ECompanionInterventionType Type)
{
	ActiveCompanionName = CompanionName;
	NotificationOpacity = 1.0f;
	bActive = true;
}

void UAshenUserWidget_CostlyPresencePromptHUD::DismissNotification()
{
	NotificationOpacity = 0.0f;
	bActive = false;
}
