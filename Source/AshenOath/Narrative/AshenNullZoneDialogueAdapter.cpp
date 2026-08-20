// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenNullZoneDialogueAdapter.h"

UAshenNullZoneDialogueAdapter::UAshenNullZoneDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNullZoneDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenNullZoneDialogueAdapter::TriggerNullZoneBark(FName SpeakerID, float ProximityRatio)
{
	FString Bark = TEXT("The air is growing thick with ash... stay close.");
	if (SpeakerID == FName(TEXT("Serafina")))
	{
		Bark = TEXT("The resonance here is fracturing. Be on your guard, Kaelen.");
	}
	else if (SpeakerID == FName(TEXT("Garrett")))
	{
		Bark = TEXT("Bad terrain ahead. Traps won't hold if the ground turns to void.");
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenNullZoneDialogueAdapter: %s: \"%s\" (Proximity: %.1f%%)"),
		*SpeakerID.ToString(), *Bark, ProximityRatio * 100.0f);
}
