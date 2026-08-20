// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenBestiaryFinisherDialogueAdapter.h"

UAshenBestiaryFinisherDialogueAdapter::UAshenBestiaryFinisherDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBestiaryFinisherDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenBestiaryFinisherDialogueAdapter::TriggerBestiaryCallout(EAshenPartyFinisherType FinisherType, FName CompanionID)
{
	FString Callout = TEXT("Weakspot exploited! Hold the line!");
	if (FinisherType == EAshenPartyFinisherType::SlagSerpentBasaltVentCauterization)
	{
		Callout = TEXT("Carapace cracked! Strike the vent now, Kaelen!");
	}
	else if (FinisherType == EAshenPartyFinisherType::GuiltStitcherSeveredTetherCollapse)
	{
		Callout = TEXT("Suture severed! The damage reflection is broken!");
	}
	else if (FinisherType == EAshenPartyFinisherType::EchoMaimerChronosShatterAnchor)
	{
		Callout = TEXT("Timeline locked! Shatter the mirror frame!");
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenBestiaryFinisherDialogueAdapter: %s: \"%s\""), *CompanionID.ToString(), *Callout);
}
