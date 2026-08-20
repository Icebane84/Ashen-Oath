// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticMemoryAudioComponent.h"

UAshenDiegeticMemoryAudioComponent::UAshenDiegeticMemoryAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticMemoryAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticMemoryAudioComponent::PlayMemoryWhisperLoop()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticMemoryAudioComponent: Memory whisper spatial audio loop started."));
}

void UAshenDiegeticMemoryAudioComponent::PlayCatharticBellChime()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticMemoryAudioComponent: CATHARTIC BELL CHIME! Memory resolved."));
}
