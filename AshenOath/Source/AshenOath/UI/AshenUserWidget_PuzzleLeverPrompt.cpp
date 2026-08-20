// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 259: Ashen Puzzle Lever Prompt UMG Widget

#include "AshenUserWidget_PuzzleLeverPrompt.h"

void UAshenUserWidget_PuzzleLeverPrompt::ShowLeverPrompt(FName LeverID, const FText& LeverActionText, bool bIsAlreadyActivated)
{
	DisplayedLeverID = LeverID;
	DisplayedLeverActionText = LeverActionText;
	bLeverActivated = bIsAlreadyActivated;
	bPromptActive = true;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PuzzleLeverPrompt: Lever prompt displayed for '%s' ('%s') — Activated: %s."),
		*LeverID.ToString(), *LeverActionText.ToString(), bIsAlreadyActivated ? TEXT("TRUE") : TEXT("FALSE"));
}

void UAshenUserWidget_PuzzleLeverPrompt::HideLeverPrompt()
{
	bPromptActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PuzzleLeverPrompt: Lever prompt hidden."));
}
