// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticJournalAudioComponent.h"

UAshenDiegeticJournalAudioComponent::UAshenDiegeticJournalAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticJournalAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticJournalAudioComponent::PlayPageFlipSFX()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticJournalAudioComponent: Playing Crisp Parchment Page Flip SFX."));
}

void UAshenDiegeticJournalAudioComponent::PlayQuillScribingSFX()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticJournalAudioComponent: Playing Scratchy Charcoal Quill Scribing SFX."));
}

void UAshenDiegeticJournalAudioComponent::PlayAstrolabeAttunedChimeSFX()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticJournalAudioComponent: Playing Brass Astrolabe Resonance Chime SFX!"));
}
