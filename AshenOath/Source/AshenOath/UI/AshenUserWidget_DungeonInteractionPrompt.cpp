// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 229: Ashen Dungeon Interaction Prompt UMG Widget

#include "AshenUserWidget_DungeonInteractionPrompt.h"

void UAshenUserWidget_DungeonInteractionPrompt::ShowPrompt(const FText& ActionText, const FText& KeyNameText)
{
	CurrentActionText = ActionText;
	CurrentKeyNameText = KeyNameText;
	bPromptVisible = true;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DungeonInteractionPrompt: Prompt displayed — '%s' [%s]."),
		*ActionText.ToString(), *KeyNameText.ToString());
}

void UAshenUserWidget_DungeonInteractionPrompt::HidePrompt()
{
	bPromptVisible = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_DungeonInteractionPrompt: Prompt hidden."));
}
