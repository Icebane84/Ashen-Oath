// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenSanctuaryBeaconJournalRegistrarComponent.h"

UAshenSanctuaryBeaconJournalRegistrarComponent::UAshenSanctuaryBeaconJournalRegistrarComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenSanctuaryBeaconJournalRegistrarComponent::FormatBeaconJournalEntry(
	FName BeaconId,
	const FString& RegionName) const
{
	const FString EntryString = FString::Printf(
		TEXT("[Forensic Journal — Sanctuary Inscription]\nBeacon: %s | Province: %s\n'The White Flame ignited the slumbering hearth. Windchill and ash recede beyond the perimeter.'"),
		*BeaconId.ToString(), *RegionName);

	return FText::FromString(EntryString);
}

void UAshenSanctuaryBeaconJournalRegistrarComponent::RecordEntry(
	const FText& Entry)
{
	InscribedJournalEntries.Add(Entry);
}
