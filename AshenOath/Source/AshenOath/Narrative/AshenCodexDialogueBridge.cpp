// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCodexDialogueBridge.h"

UAshenCodexDialogueBridge::UAshenCodexDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenCodexDialogueBridge::FormatLoreConversationOpener(
	const FName& EntryId,
	const FText& EntryTitle) const
{
	const FString Formatted = FString::Printf(
		TEXT("[Campfire Reflection]: 'We found '%s' in the ruins. What does your order teach of this?'"),
		*EntryTitle.ToString());
	return FText::FromString(Formatted);
}
