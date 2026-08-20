// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_InnerMonologueSubtitleHUD.h"

UAshenUserWidget_InnerMonologueSubtitleHUD::UAshenUserWidget_InnerMonologueSubtitleHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bActive = false;
	CurrentChannel = EVoiceChannel::ShadowSelf;
}

void UAshenUserWidget_InnerMonologueSubtitleHUD::DisplayMonologue(
	const FString& Text,
	EVoiceChannel Channel,
	float DurationSeconds)
{
	CurrentMonologueText = Text;
	CurrentChannel = Channel;
	bActive = true;
}

void UAshenUserWidget_InnerMonologueSubtitleHUD::ClearMonologue()
{
	CurrentMonologueText.Empty();
	bActive = false;
}
