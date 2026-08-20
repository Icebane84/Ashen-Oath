// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenLivingOathDialogueAdapter.h"

UAshenLivingOathDialogueAdapter::UAshenLivingOathDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLivingOathDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenLivingOathDialogueAdapter::TriggerOathDialogue(EAshenLivingOathType OathType, EAshenOathState State, FName CompanionID)
{
	FString Callout = TEXT("An oath has been sworn. May the White Flame preserve us.");
	if (State == EAshenOathState::Fulfilled)
	{
		Callout = TEXT("The vow is complete. Your soul remains unbroken.");
	}
	else if (State == EAshenOathState::Fractured)
	{
		Callout = TEXT("You broke the oath, Kaelen! Can you hear what the blade is whispering?!");
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenLivingOathDialogueAdapter: %s: \"%s\""), *CompanionID.ToString(), *Callout);
}
