// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenFinisherDialogueReactivityAdapter.h"

UAshenFinisherDialogueReactivityAdapter::UAshenFinisherDialogueReactivityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherDialogueReactivityAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenFinisherDialogueReactivityAdapter::TriggerFinisherDialogueReaction(
	EAshenPartyFinisherType FinisherType, FName CompanionID)
{
	FString DialogueLine = TEXT("Together we stand.");
	if (FinisherType == EAshenPartyFinisherType::ShepherdsIntervention)
	{
		DialogueLine = TEXT("Hold on Kaelen, don't let the dark take you. We've got you.");
	}
	else if (FinisherType == EAshenPartyFinisherType::EmpathicConduitNova)
	{
		DialogueLine = TEXT("The corruption burns away... thank you, Kaelen.");
	}
	else if (FinisherType == EAshenPartyFinisherType::SentinelsEclipse)
	{
		DialogueLine = TEXT("Clean cut, Kaelen! Oil ignited like dry timber.");
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenFinisherDialogueReactivityAdapter: %s: \"%s\""), *CompanionID.ToString(), *DialogueLine);
}
