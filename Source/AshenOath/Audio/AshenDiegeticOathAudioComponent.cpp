// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticOathAudioComponent.h"

UAshenDiegeticOathAudioComponent::UAshenDiegeticOathAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticOathAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticOathAudioComponent::PlayOathSwornChime()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticOathAudioComponent: Ethereal oath vow chime sound played."));
}

void UAshenDiegeticOathAudioComponent::PlayOathbreakerShatterSound()
{
	UE_LOG(LogTemp, Error, TEXT("UAshenDiegeticOathAudioComponent: OATHBREAKER glass shattering sonic cue played."));
}
