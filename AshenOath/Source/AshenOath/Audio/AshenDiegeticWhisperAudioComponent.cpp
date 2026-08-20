// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticWhisperAudioComponent.h"

UAshenDiegeticWhisperAudioComponent::UAshenDiegeticWhisperAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticWhisperAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticWhisperAudioComponent::PlayWhisperDroneCue(float Intensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticWhisperAudioComponent: Low-frequency whisper drone played (Intensity: %.2f)."), Intensity);
}

void UAshenDiegeticWhisperAudioComponent::PlayFragmentDiscoveryChime()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticWhisperAudioComponent: Memory Fragment discovery chime played."));
}
