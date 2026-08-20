// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticJournalParchmentAudioComponent.h"

UAshenDiegeticJournalParchmentAudioComponent::UAshenDiegeticJournalParchmentAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticJournalParchmentAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticJournalParchmentAudioComponent::PlayPageTurnCue()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticJournalParchmentAudioComponent: Played DRIED PARCHMENT PAGE TURN CUE."));
}

void UAshenDiegeticJournalParchmentAudioComponent::PlayResolutionInscribedCue(bool bIsSynarchy)
{
	if (bIsSynarchy)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticJournalParchmentAudioComponent: Played HARMONIC LEYLINE INSCRIBE CUE."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticJournalParchmentAudioComponent: Played HARSH CHARCOAL SCRATCH CUE."));
	}
}
