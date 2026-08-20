// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenRetroactiveMarginaliaInscriberComponent.h"

UAshenRetroactiveMarginaliaInscriberComponent::UAshenRetroactiveMarginaliaInscriberComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FRetroactiveMarginaliaEntry UAshenRetroactiveMarginaliaInscriberComponent::InscribeMarginalia(
	int32 PageIndex,
	FName Author,
	const FString& Content,
	EMarginaliaInkMedium Medium)
{
	FRetroactiveMarginaliaEntry Entry;
	Entry.EntryId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	Entry.TargetJournalPageIndex = PageIndex;
	Entry.InscribingAuthor = Author;
	Entry.MarginaliaContent = Content;
	Entry.Medium = Medium;
	Entry.bDiscoveredByPlayer = false;

	InscribedEntries.Add(Entry);
	return Entry;
}

TArray<FRetroactiveMarginaliaEntry> UAshenRetroactiveMarginaliaInscriberComponent::GetMarginaliaForPage(int32 PageIndex) const
{
	TArray<FRetroactiveMarginaliaEntry> PageEntries;
	for (const FRetroactiveMarginaliaEntry& Entry : InscribedEntries)
	{
		if (Entry.TargetJournalPageIndex == PageIndex)
		{
			PageEntries.Add(Entry);
		}
	}
	return PageEntries;
}
