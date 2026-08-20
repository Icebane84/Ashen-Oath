// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticUnchainedAudioComponent.h"

UAshenDiegeticUnchainedAudioComponent::UAshenDiegeticUnchainedAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticUnchainedAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticUnchainedAudioComponent::PlayUnchainedRoar()
{
	UE_LOG(LogTemp, Error, TEXT("UAshenDiegeticUnchainedAudioComponent: Playing Guttural Unchained Void Roar (Sub-Bass + Spatial Distortion)!"));
}
