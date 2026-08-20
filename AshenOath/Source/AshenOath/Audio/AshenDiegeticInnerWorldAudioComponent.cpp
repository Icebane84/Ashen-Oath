// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticInnerWorldAudioComponent.h"

UAshenDiegeticInnerWorldAudioComponent::UAshenDiegeticInnerWorldAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticInnerWorldAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticInnerWorldAudioComponent::TriggerInnerWorldTransitionAudio()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticInnerWorldAudioComponent: Triggered visceral Inner World transition audio (Volume: %f)."), InnerWorldTransitionVolume);
}

void UAshenDiegeticInnerWorldAudioComponent::TriggerEldrinMemoryChimeAudio()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticInnerWorldAudioComponent: Triggered silver Eldrin memory chime audio."));
}
