// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_StaggerExecutionPromptHUD.h"

void UAshenUserWidget_StaggerExecutionPromptHUD::ShowExecutionPrompt(float RemainingSeconds)
{
	bIsPromptActive = (RemainingSeconds > 0.0f);
	WindowTimeRemaining = RemainingSeconds;
	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_StaggerExecutionPromptHUD: STAGGER EXECUTION PROMPT: %s (Time: %.2fs)!"),
		bIsPromptActive ? TEXT("ACTIVE") : TEXT("CLOSED"), WindowTimeRemaining);
}
