// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 299: Ashen Sanctuary Rune Prompt UMG Widget

#include "AshenUserWidget_SanctuaryRunePrompt.h"

void UAshenUserWidget_SanctuaryRunePrompt::DisplayRunePrompt(FName RuneID, const FText& RuneNameText)
{
	DisplayedRuneID = RuneID;
	DisplayedRuneName = RuneNameText;
	bPromptActive = true;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_SanctuaryRunePrompt: FAST TRAVEL RUNE PROMPT DISPLAYED — '%s' ('%s')."),
		*RuneID.ToString(), *RuneNameText.ToString());
}

void UAshenUserWidget_SanctuaryRunePrompt::HidePrompt()
{
	bPromptActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SanctuaryRunePrompt: Fast travel rune prompt hidden."));
}
