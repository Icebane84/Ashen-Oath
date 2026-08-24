// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_ForensicJournalHUD.h"

UAshenUserWidget_ForensicJournalHUD::UAshenUserWidget_ForensicJournalHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedScenarioIndex = 1;
	DisplayedTitle = TEXT("The Bleeding Waystation");
	bKaelenNoteVisible = true;
	bGarrettNoteVisible = false;
	bSerafinaNoteVisible = false;
	DisplayedSootMicrons = 0.0f;
}

void UAshenUserWidget_ForensicJournalHUD::DisplayJournalEntry(
	const FForensicJournalEntry& Entry,
	float PartyTrust01)
{
	DisplayedScenarioIndex = Entry.ScenarioIndex;
	DisplayedTitle = Entry.ScenarioTitle;
	DisplayedSummary = Entry.CanonicalSummary;
	DisplayedSootMicrons = Entry.RecordedSootMicrons;

	bKaelenNoteVisible = true;
	bGarrettNoteVisible = PartyTrust01 >= 0.40f;
	bSerafinaNoteVisible = PartyTrust01 >= 0.70f;
}
