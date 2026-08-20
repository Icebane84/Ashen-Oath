// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 289: Ashen Secret Passage Prompt UMG Widget

#include "AshenUserWidget_SecretPassagePrompt.h"

void UAshenUserWidget_SecretPassagePrompt::ShowSecretPassagePrompt(const FText& PromptText)
{
	DisplayedPromptText = PromptText;
	bPromptVisible = true;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SecretPassagePrompt: Secret passage prompt displayed — '%s'."), *PromptText.ToString());
}

void UAshenUserWidget_SecretPassagePrompt::HidePrompt()
{
	bPromptVisible = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SecretPassagePrompt: Secret passage prompt hidden."));
}
