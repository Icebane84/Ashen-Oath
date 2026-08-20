// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenDiegeticJournalPageTurnAudioComponent.h"

UAshenDiegeticJournalPageTurnAudioComponent::UAshenDiegeticJournalPageTurnAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticJournalPageTurnAudioComponent::PlayPageTurnAudio(bool bForward)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticJournalPageTurnAudioComponent: Playing page turn sound (%s)"), bForward ? TEXT("Forward") : TEXT("Backward"));
}

void UAshenDiegeticJournalPageTurnAudioComponent::PlayInkScratchAudio(float ScratchDuration)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticJournalPageTurnAudioComponent: Playing ink scratch sound for %.2f seconds"), ScratchDuration);
}
