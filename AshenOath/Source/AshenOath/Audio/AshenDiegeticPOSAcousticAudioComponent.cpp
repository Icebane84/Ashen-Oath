// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticPOSAcousticAudioComponent.h"

UAshenDiegeticPOSAcousticAudioComponent::UAshenDiegeticPOSAcousticAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticPOSAcousticAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticPOSAcousticAudioComponent::TriggerPageRustleAudio()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticPOSAcousticAudioComponent: Triggered diegetic page rustle audio (Volume: %f)."), PageRustleVolume);
}

void UAshenDiegeticPOSAcousticAudioComponent::TriggerSanctuaryChimeAudio()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticPOSAcousticAudioComponent: Triggered Heartstone sanctuary chime audio."));
}
