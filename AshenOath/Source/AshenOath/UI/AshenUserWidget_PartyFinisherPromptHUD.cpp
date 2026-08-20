// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_PartyFinisherPromptHUD.h"

void UAshenUserWidget_PartyFinisherPromptHUD::DisplayFinisherPrompt(EAshenPartyFinisherType FinisherType, const FText& InTitle)
{
	ActivePromptType = FinisherType;
	FinisherTitle = InTitle;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_PartyFinisherPromptHUD: Prompt displayed for %s (Type: %d)."),
		*FinisherTitle.ToString(), (int32)ActivePromptType);
}
