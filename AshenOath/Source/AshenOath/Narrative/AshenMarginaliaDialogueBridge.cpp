// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenMarginaliaDialogueBridge.h"

UAshenMarginaliaDialogueBridge::UAshenMarginaliaDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenMarginaliaDialogueBridge::FormatMarginaliaDialoguePrompt(
	const FString& BasePrompt,
	EMarginaliaAuthor Author,
	const FString& InscriptionText) const
{
	if (InscriptionText.IsEmpty())
	{
		return FText::FromString(BasePrompt);
	}

	const FString AuthorName = (Author == EMarginaliaAuthor::Garrett) ? TEXT("Garrett") : TEXT("Serafina");
	const FString Formatted = FString::Printf(TEXT("%s\n[Re: %s's Note: \"%s\"]"), *BasePrompt, *AuthorName, *InscriptionText);
	return FText::FromString(Formatted);
}
