// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_CodexRepositoryHUD.h"

UAshenUserWidget_CodexRepositoryHUD::UAshenUserWidget_CodexRepositoryHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedEntryId = NAME_None;
}

void UAshenUserWidget_CodexRepositoryHUD::DisplayLoreEntry(
	const FCodexEntry& Entry,
	const FText& MarginaliaText)
{
	DisplayedEntryId = Entry.EntryId;
	DisplayedTitle = Entry.Title;
	DisplayedMarginalia = MarginaliaText;
}
