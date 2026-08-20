// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 279: Ashen Destructible Wall Prompt UMG Widget

#include "AshenUserWidget_DestructibleWallPrompt.h"

void UAshenUserWidget_DestructibleWallPrompt::ShowWallPrompt(const FText& WallPromptText)
{
	CurrentWallPromptText = WallPromptText;
	bPromptVisible = true;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DestructibleWallPrompt: Wall prompt displayed — '%s'."), *WallPromptText.ToString());
}

void UAshenUserWidget_DestructibleWallPrompt::HideWallPrompt()
{
	bPromptVisible = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DestructibleWallPrompt: Wall prompt hidden."));
}
