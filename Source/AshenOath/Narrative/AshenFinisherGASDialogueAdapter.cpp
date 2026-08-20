// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenFinisherGASDialogueAdapter.h"

UAshenFinisherGASDialogueAdapter::UAshenFinisherGASDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherGASDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenFinisherGASDialogueAdapter::TriggerFinisherGASCallout(FName AbilityName, FName SpeakerID)
{
	FString Callout = TEXT("Strike now! The weakspot is exposed!");
	if (AbilityName == FName(TEXT("Ability.Serafina.ConduitNova")))
	{
		Callout = TEXT("Kaelen, take my hand! Drive the steel through!");
	}
	else if (AbilityName == FName(TEXT("Ability.Garrett.SentinelsEclipse")))
	{
		Callout = TEXT("I've got his guard! Take his head!");
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenFinisherGASDialogueAdapter: %s: \"%s\" (Ability: %s)"),
		*SpeakerID.ToString(), *Callout, *AbilityName.ToString());
}
