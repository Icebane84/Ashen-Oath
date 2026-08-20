// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticFinisherGASAudioComponent.h"

UAshenDiegeticFinisherGASAudioComponent::UAshenDiegeticFinisherGASAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticFinisherGASAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticFinisherGASAudioComponent::PlayGrappleWhooshCue()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticFinisherGASAudioComponent: Grapple line hook whoosh audio played."));
}

void UAshenDiegeticFinisherGASAudioComponent::PlayNovaDetonationCue()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticFinisherGASAudioComponent: SUB-BASS NOVA DETONATION explosion audio played."));
}
