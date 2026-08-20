// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticCrisisAcousticAudioComponent.h"

UAshenDiegeticCrisisAcousticAudioComponent::UAshenDiegeticCrisisAcousticAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticCrisisAcousticAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticCrisisAcousticAudioComponent::TriggerAcousticMuffle()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCrisisAcousticAudioComponent: Triggered acoustic muffling (Cutoff Frequency: %f Hz)."), AcousticMuffleCutoffFrequency);
}

void UAshenDiegeticCrisisAcousticAudioComponent::TriggerSilverBellResolutionTone()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCrisisAcousticAudioComponent: Triggered pure silver bell resolution tone (Path B)."));
}
