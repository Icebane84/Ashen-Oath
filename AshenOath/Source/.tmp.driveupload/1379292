// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenInnerVoiceDialogueBridge.h"

UAshenInnerVoiceDialogueBridge::UAshenInnerVoiceDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenInnerVoiceDialogueBridge::FormatDialogueThoughtPrompt(
	const FString& RawPrompt,
	const FString& MonologueThought) const
{
	if (MonologueThought.IsEmpty())
	{
		return FText::FromString(RawPrompt);
	}

	const FString Formatted = FString::Printf(TEXT("%s\n[Thought: %s]"), *RawPrompt, *MonologueThought);
	return FText::FromString(Formatted);
}
