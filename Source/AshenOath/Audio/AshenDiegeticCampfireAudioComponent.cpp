// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticCampfireAudioComponent.h"

UAshenDiegeticCampfireAudioComponent::UAshenDiegeticCampfireAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticCampfireAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticCampfireAudioComponent::PlayCampfireIgniteAmbience()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCampfireAudioComponent: Warm crackling campfire ember ambience playing."));
}

void UAshenDiegeticCampfireAudioComponent::PlayHeartstoneResonanceChime()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCampfireAudioComponent: Resonant crystalline chime played for heartstone transmutation."));
}
