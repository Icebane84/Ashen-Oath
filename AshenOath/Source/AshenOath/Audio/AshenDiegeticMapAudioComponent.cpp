// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticMapAudioComponent.h"

UAshenDiegeticMapAudioComponent::UAshenDiegeticMapAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticMapAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticMapAudioComponent::TriggerMapUnfoldAudio()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticMapAudioComponent: Triggered diegetic map unfold audio (Volume: %f)."), MapUnfoldVolume);
}

void UAshenDiegeticMapAudioComponent::TriggerGraphiteScratchAudio()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticMapAudioComponent: Triggered graphite pin scratch audio."));
}
